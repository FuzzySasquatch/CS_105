/** 
Name: Phoenix Bishea
Eid: pnb338
*/

#include <ncurses.h>    // the ncurses library
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <unistd.h> // sleep
#include <iostream>

using std::cout;

#include "timehelper.cpp"
#include "GameObject.h"
#include "PlayerShip.h"
#include "EnemyShip.h"
#include "PlayerProjectile.h"
#include "EnemyProjectile.h"

#define NUM_ENEMIES 22
#define PLAYER_PROJECTILE_LIMIT 5
#define ENEMY_PROJECTILE_LIMIT 35
#define ENEMY_X_START 34
#define ENEMY_Y_START 2
#define X_MAX 45 /// Right bounds
#define X_MIN 10 /// Left bounds

/// Clean up memory
void cleanGameObjects(EnemyShip* enemies[], EnemyProjectile* enemyProjectiles[], PlayerProjectile* pProjectiles[], PlayerShip *player) {
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
    if (player) {
        delete player;
    }
    
}

int main (int argc, char const *argv[])
{   
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

    /// Setup for player color and exit
    start_color();     
    init_pair(2, COLOR_GREEN, 0);
    init_pair(1, COLOR_RED, 0);

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

    /// Hold players and player projectiles
    PlayerShip* player = new PlayerShip(y, x, '^');
    PlayerProjectile* pProjectiles[PLAYER_PROJECTILE_LIMIT] = {0};

    /// Hold enemies and enemy projectiles
    EnemyShip* enemies[NUM_ENEMIES] = {0};
    EnemyProjectile* buffer[10] = {0};
    EnemyProjectile* enemyProjectiles[ENEMY_PROJECTILE_LIMIT] = {0};

    /// Enemy starting y, x values
    int enemyY = ENEMY_Y_START;
    int enemyX = ENEMY_X_START;

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
            enemyY += ENEMY_Y_START;
            enemyX = ENEMY_X_START;
        } else {
            enemyX += 2;
        }
    }

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

    // Win condition
    bool win = false;
    bool pressedQ = false;
    bool pause = false;

    while (!quit) {
        /// Print the score
        mvprintw(0, 22, "SCORE: %i   PRESS 'q' TO QUIT\n", score);
        if (score < 10)
            mvchgat(0, 40, 1, 'q', 1, NULL);
        else {
            mvchgat(0, 41, 1, 'q', 1, NULL);
        }
        mvchgat(0, 22, 5, 'S', 2, NULL);
        
        /// Gives player the ability to pause the game
        while (pause) {
            ch = getch();
            // erase(); /// erase the screen (after getch())
            if (ch == 'r' || ch == 'p') {
                pause = false;
            }
            mvprintw(9, 22, "PAUSED ||  PRESS 'r' TO RESUME\n");
            mvchgat(9, 40, 1, 'r', 2, NULL);
        }

        /// Fetch player input
        ch = getch();
        erase(); /// erase the screen (after getch())
        if ( ch != ERR) { /// user has a keypress
            /// this is to delay until the next tick
            elapsedTime = getElapsedTime();
            if (elapsedTime < delay){
                nsleep(delay-elapsedTime);
            } 
        }

        ticks += 1; /// Counts ticks

        /// Check for player projectile collisioins with enemies and enemy collisions with the player or the base
        for (int i = 0; i < PLAYER_PROJECTILE_LIMIT; ++i) {
            if (pProjectiles[i]) {
                bool deleteP = false;
                quit = EnemyShip::isCollision(enemies, NUM_ENEMIES, pProjectiles[i], &score, &deleteP);
                /// Player projectile has collided with enemy so delete it
                if (deleteP && pProjectiles[i]) {
                    delete pProjectiles[i];
                    pProjectiles[i] = 0;
                }
            } 
        }
        /// Check for enemy projectile collisions with the player or the base 
        quit = EnemyProjectile::isCollision(enemyProjectiles, player, ENEMY_PROJECTILE_LIMIT);
        /// check for player projectile collisions with the ceiling
        PlayerProjectile::isCollision(pProjectiles, PLAYER_PROJECTILE_LIMIT);
        if (!quit)
            quit = EnemyShip::isCollision(enemies, player, NUM_ENEMIES);
        /// Update the player postion based on user input
        switch(ch){
                case KEY_RIGHT: 
                case 'd':       
                    if (x < X_MAX + 9) {
                        x++; 
                        player->setX(1);
                    }
                    break;
                case KEY_LEFT: 
                case 'a':
                    if (x > X_MIN + 10) {
                        x--; 
                        player->setX(-1);
                    }
                    break;
                /// Limits the player to 5 projectiles at a time
                case ' ':
                    if (pProjectileIndex < PLAYER_PROJECTILE_LIMIT) {
                        cout << '\a';
                        pProjectiles[pProjectileIndex] = new PlayerProjectile(y-1, x, '|');
                        pProjectileIndex++;
                    /// Once a projectile has been destroyed the process starts over  
                    } else if (!pProjectiles[0]) {
                        pProjectileIndex = 0;
                    }
                    break;
                case 'q': 
                    pressedQ = true;
                    quit = true;
                    break;
                case 'p':
                    pause = true;
                    break;
        }

        /// Reset enemy projectile index
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

        /// Print the player ship colored green
        mvaddch(y,x,'^');
        mvchgat(y,x, 1, '^', 2, NULL);

        /// Print base like in space invaders
        for (int i = X_MIN + 10; i < X_MAX + 10; ++i) {
            mvaddch(22,i,'-');
            mvchgat(22, i, 1, '-', 2, NULL);
        }
        

        refresh(); // refresh the screen after adding everything
        move(0,0); /// move cursor to 0,0 (looks prettier if os doesn't allow invisible cursors)

        /// Player wins
        win = score == NUM_ENEMIES;
        // win = true;
        if (win) {
            quit = true;
        }

    }   

    refresh(); // refresh the screen
    move(0,0); /// move cursor to 0,0
    
    /// Game over screen
    quit = false;
    while (!quit) {
        ch = getch();
        erase();
        if (ch == 'x' || pressedQ) { /// If player pressed 'q' during game quit immediately
            quit = true;
        }
        /// Print win message
        if (win) {
           mvprintw(8, 30, "WELL DONE EARTHLING\n");
           mvchgat(8, 39, 10, 0, 2, NULL);
           mvprintw(9, 31, "THIS TIME YOU WIN\n");
           mvprintw(11, 31, "PRESS 'x' TO EXIT\n");
           mvchgat(11, 38, 1, 'x', 1, NULL);
        /// Print lose message
        } else {
            mvprintw(9, 35, "GAME OVER\n");
            mvprintw(11, 31, "PRESS 'x' TO EXIT\n");
            mvchgat(11, 38, 1, 'x', 1, NULL);
        }
    } 
    endwin();   /// cleanup the window

    // clean up memory
    cleanGameObjects(enemies, enemyProjectiles, pProjectiles, player);

    return 0;
}