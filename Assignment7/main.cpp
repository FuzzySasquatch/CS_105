/** 
Name: Phoenix Bishea
Eid: pnb338
*/

#include <ncurses.h>    // the ncurses library
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <unistd.h> // sleep
#include <iostream>

#include "timehelper.cpp"
#include "GameObject.h"
// #include "Ship.h"
#include "PlayerShip.h"
#include "EnemyShip.h"
// #include "Projectile.h"
#include "PlayerProjectile.h"
#include "EnemyProjectile.h"

using std::cout;
using std::endl;

#define NUM_ENEMIES 22
#define PLAYER_PROJECTILE_LIMIT 5
#define ENEMY_PROJECTILE_LIMIT 25
#define X_MAX 36
#define X_MIN 0


// static void enqueue(GameObject* obj) {
//     cout << "  calling enqueue" << endl;
//     // return new GameObject(y, x, ch);
//     // =" << obj << endl;
//     // delete obj;
// }

// static void dequeue(GameObject* obj) {
//     cout << "  calling dequeue with obj address =" << obj << endl; 
// }

int main (int argc, char const *argv[])
{   

    // GameObject::myEnqueue = &enqueue;
    // GameObject::myDequeue = &dequeue;
    
    /// Hold players and player projectiles
    PlayerShip* player = new PlayerShip(21, 20, '^');
    PlayerProjectile* pProjectiles[PLAYER_PROJECTILE_LIMIT] = {0};

    /// Hold enemies and enemy projectiles
    EnemyShip* enemies[NUM_ENEMIES] = {0};
    EnemyProjectile* enemyProjectiles[ENEMY_PROJECTILE_LIMIT] = {0};

    /// Enemy starting y, x values
    int enemyY = 2;
    int enemyX = 16;

    /// Create enemies
    for (int count = 0; count < NUM_ENEMIES; ++count) {
        bool u = count % 2;
        bool newLine = count == 10;
        if (u) {
            enemies[count] = new EnemyShip(enemyY, enemyX, 'u');
        } else {
            enemies[count] = new EnemyShip(enemyY, enemyX, 'W');
        }
        if (newLine) {
            enemyY += 2;
            enemyX = 16;
        } else {
            enemyX += 2;
        }
    }

    srand (time(NULL)); /// seed to some random number based on time
    if ( initscr() == NULL ) { /// init the screen, defaults to stdscr
        fprintf(stderr, "Error initialising ncurses.\n");
        exit(EXIT_FAILURE);
    }

    if(has_colors() == FALSE)   /// check to see if terminal supports colors
    {   
        endwin();
        printf("Your terminal does not support color.\n");
        exit(1);
    }

    /// Setup for player color
    start_color();     
    init_pair(2, COLOR_GREEN, 0);

    noecho(); /// don't echo keypresses
    keypad(stdscr, TRUE); /// set the keypad to stdscr
    nodelay(stdscr, false);
    curs_set(0); /// set cursor to invisible (if allowed by the os)
    const int delay = 50; /// milliseconds = one tick
    timeout(delay); /// set how long between keypresses (more or less)

    /// some variables to give you some hints
    int ch = 0;
    bool quit = false;
    int score = 0;

    int elapsedTime = getElapsedTime();
    int ticks = 0;

    /// Player positional values
    int x = 20;
    int y = 21;

    /// Player projectile values and index
    int pProjectileY = 0;
    int pProjectileX= 0;
    int pProjectileIndex = 0;

    /// Enemy projectile values and index
    int eProjectileY = 0;
    int eProjectileX = 0;
    int enemyProjectileIndex = 0;

    /// Holds enemy shape
    char enemy;

    while (!quit){
        /// this is how to print a string to the screen, 0, 0 is the  y, x location
        mvprintw(0, 0, "SCORE: %i   'q' to quit.\n", score);

        /// Handle player input
        ch = getch();
        erase(); /// erase the screen (after getch())
        if ( ch != ERR) { /// user has a keypress
             mvprintw(20, 0, "Got here"); 
            /// this is to delay until the next tick
            elapsedTime = getElapsedTime();
            if (elapsedTime < delay){
                nsleep(delay-elapsedTime);
            } 
        }

        ticks += 1; /// Counts ticks
        mvprintw(20, 0, "Ticks = %i", ticks);

        if (enemyProjectileIndex > ENEMY_PROJECTILE_LIMIT) {
            enemyProjectileIndex = 0;
        }
        
        /// Print enemy projectiles
        EnemyProjectile::timeStep(enemyProjectiles, ENEMY_PROJECTILE_LIMIT, ticks);
        for (int i = 0; i < ENEMY_PROJECTILE_LIMIT; ++i) {
            if (enemyProjectiles[i]) {
                eProjectileY = enemyProjectiles[i]->getY();
                eProjectileX = enemyProjectiles[i]->getX();
                mvprintw(eProjectileY, eProjectileX, "|");
            }
        }

        /// some example code to show how to work with the keyboard
        switch(ch){
                case KEY_RIGHT: 
                case 'd':       
                    if (x < X_MAX) x++; break;
                case KEY_LEFT: 
                case 'a':
                    if (x > X_MIN) x--; break;
                /// Limits the player to 5 projectiles at a time
                case ' ':
                    if (pProjectileIndex < PLAYER_PROJECTILE_LIMIT) {
                        pProjectiles[pProjectileIndex] = new PlayerProjectile(y-1, x, '|');
                        pProjectileIndex++;
                    /// Once a projectile has been destroyed the process starts over  
                    } else if (!pProjectiles[0]) {
                        pProjectileIndex = 0;
                    }
                    break;
                case 'q': 
                    quit = true;
                    break;
        }

        /// Print player projectiles
        PlayerProjectile::timeStep(pProjectiles, PLAYER_PROJECTILE_LIMIT);
        for (int i = 0; i < PLAYER_PROJECTILE_LIMIT; ++i) {
            if (pProjectiles[i]) {
                pProjectileY = pProjectiles[i]->getY();
                pProjectileX = pProjectiles[i]->getX();
                mvprintw(pProjectileY, pProjectileX, "|");
            }
        }

        /// Print enemies and create enemy projectiles
        EnemyShip::timeStep(&ticks, enemies, NUM_ENEMIES, enemyProjectiles, &enemyProjectileIndex);
        for (int i = 0; i < NUM_ENEMIES; ++i) {
            if (enemies[i]) {
                enemy = enemies[i]->getShape();
                enemyY = enemies[i]->getY();
                enemyX = enemies[i]->getX();
                mvaddch(enemyY, enemyX, enemy);
            }
        }    

        mvaddch(y,x,'^'); /// Print the player ship
        mvchgat(y,x, 1, '^', 2, NULL); /// color the player green

        refresh(); // refresh the screen after adding everything
        move(0,0); /// move cursor to 0,0 (looks prettier if os doesn't allow invisible cursors)
    }   
    
    endwin();   /// cleanup the window

    // cleanup game objects
    for (int i = 0; i < NUM_ENEMIES; ++i) {
        if (enemies[i]) {
            delete enemies[i];
            enemies[i] = 0;
        }
    }
    for (int i = 0; i < ENEMY_PROJECTILE_LIMIT; ++i) {
        if (enemyProjectiles[i]) {
            delete enemyProjectiles[i];
            enemyProjectiles[i] = 0;
        }
    }
    for (int i = 0; i < PLAYER_PROJECTILE_LIMIT; ++i) {
        if (pProjectiles[i]) {
            delete pProjectiles[i];
            pProjectiles[i] = 0;
        }
    }
    delete player;

    return 0;
}