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


    

    PlayerShip* player = new PlayerShip(21, 16, '^');
    PlayerProjectile* pProjectiles[PLAYER_PROJECTILE_LIMIT] = {0};

    EnemyShip* enemies[NUM_ENEMIES] = {0};
    EnemyProjectile* enemyProjectiles[ENEMY_PROJECTILE_LIMIT] = {0};

    int enemyY = 2;
    int enemyX = 12;

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
            enemyX = 12;
        } else {
            enemyX += 2;
        }
    }





    // cout << player->getX() << endl;
    // delete player;

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


    /// Assign function pointers
    // GameObject obj;
    // GameObject::myEnqueue = &enqueue;
    // GameObject::myDequeue = &dequeue;

    /// Create the player
    
    // PlayerShip::addObject(&player);

    /// some variables to give you some hints
    int ch = 0;
    bool quit = false;
    int score = 0;

    int x = 16;
    int y = 21;

    int elapsedTime = getElapsedTime();
    int ticks = getElapsedTime();

    char enemy;

    int pProjectileY = 0;
    int pProjectileX= 0;
    int pProjectileIndex = 0;

    int eProjectileY = 0;
    int eProjectileX = 0;
    int enemyProjectileIndex = 0;
    

    bool uFiring = false;
    bool WFiring = false;    

    // int random = rand() % 100;

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
        // random = rand() % 10;

        EnemyProjectile::timeStep(enemyProjectiles, ENEMY_PROJECTILE_LIMIT, ticks);
        ticks += 1;

        if (enemyProjectileIndex > ENEMY_PROJECTILE_LIMIT) {
            enemyProjectileIndex = 0;
        }
        
        // for (int i = 0; i < NUM_ENEMIES; ++i) {
        //     uFiring = false;
        //     WFiring = false;
        //     // double random = (double)rand() / RAND_MAX;
            
        //     // random = random * (100 - 0);
        //     mvprintw(13, 1, "random is %i", random);
        //     if (enemies[i]) {
        //         EnemyShip* enemy = enemies[i];

        //         char shape = enemy->getShape();

        //         // uFiring = (shape == 'u' && random <= 1);
        //         WFiring = (shape == 'W' && random <= 2);

        //         mvprintw(15, 1, "index is %i", enemyProjectileIndex);
        //         if (uFiring) 
        //         {
        //             // enemyProjectiles[enemyProjectileIndex] = new EnemyProjectile(enemy->getY(), enemy->getX(), '|');
        //             enemyProjectileIndex+= 1;
        //         } 

        //     }
        // }

        /// Print enemy projectiles
        
        for (int i = 0; i < ENEMY_PROJECTILE_LIMIT; ++i) {
            if (enemyProjectiles[i]) {
                eProjectileY = enemyProjectiles[i]->getY();
                eProjectileX = enemyProjectiles[i]->getX();
                mvprintw(eProjectileY, eProjectileX, "|");
            }
        }

        // ticks += getElapsedTime() / delay;
        mvprintw(20, 0, "Ticks = %i", ticks);

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
    delete player;

    return 0;
}