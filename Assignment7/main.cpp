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
#include "Ship.h"
#include "PlayerShip.h"
#include "EnemyShip.h"

using std::cout;
using std::endl;

#define NUM_ENEMIES 22
#define X_MAX 36
#define X_MIN 0


static void enqueue(GameObject* obj) {
    // obj = new GameObject();
    cout << "  calling enqueue with obj address =" << obj << endl;
    // delete obj;
}

static void dequeue(GameObject* obj) {
    cout << "  calling dequeue with obj address =" << obj << endl; 
}

int main (int argc, char const *argv[])
{   


    PlayerShip* player = new PlayerShip(21, 16, '^');

    EnemyShip* enemies[NUM_ENEMIES];

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

    cout << player->getX() << endl;
    delete player;

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

    

    // for (int count = 12; count < 32; ++count) {

    //     EnemyShip::addObject();
    // }

    while (!quit){
        
        /// this is how to print a string to the screen, 0, 0 is the  y, x location
        mvprintw(0, 0, "SCORE: %i   'q' to quit.\n", score);

        /// Handle player input
        ch = getch();
        erase(); /// erase the screen (after getch())
        if ( ch != ERR) { /// user has a keypress
            /// this is to delay until the next tick
            elapsedTime = getElapsedTime();
            if (elapsedTime < delay){
                nsleep(delay-elapsedTime);}
            
        }
        ticks += getElapsedTime() / delay;
        mvprintw(20, 0, "Ticks = %i", ticks);
        /// some example code to show how to work with the keyboard
        switch(ch){
                case KEY_RIGHT: 
                case 'd':       
                    if (x < X_MAX) x++; break;
                case KEY_LEFT: 
                case 'a':
                    if (x > X_MIN) x--; break;
                case ' ':
                    mvprintw(y-1, x, "|");
                    break;
                case 'q': 
                    quit = true;
                    break;
        }

        // ticks += getElapsedTime();

        /// Print enemies
        EnemyShip::timeStep(&ticks, enemies, NUM_ENEMIES);
        for (int i = 0; i < NUM_ENEMIES; ++i) {
            // enemies[i]->timeStep(&ticks, enemies, NUM_ENEMIES);
            enemy = enemies[i]->getShape();
            enemyY = enemies[i]->getY();
            enemyX = enemies[i]->getX();
            mvaddch(enemyY, enemyX, enemy);
        }
        


        mvaddch(y,x,'^'); /// Print the player ship
        mvchgat(y,x, 1, '^', 2, NULL); /// color the player green

        refresh(); // refresh the screen after adding everything
        move(0,0); /// move cursor to 0,0 (looks prettier if os doesn't allow invisible cursors)
    }   
    
    endwin();   /// cleanup the window

    return 0;
}