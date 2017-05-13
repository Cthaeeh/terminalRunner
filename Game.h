//
// Created by kai on 5/13/17.
//

#ifndef TERMINALRUNNER_GAME_H
#define TERMINALRUNNER_GAME_H

#include <ncurses.h>
#include "Player.h"
#include <list>

class Game {
    Player *player;
    std::list<Entity *> entities;
    WINDOW *window;
    int score = 0;

    void mainLoop();

    void initNCurse();

    void manageObstacles();

    void processInput(int i);

    void draw();

    void printDescriptions();

    bool chanceOf100(int percent);

    void checkIfDead();

    void end();

public:
    Game(int highScore);

    void start();

    int highScore;
};


#endif //TERMINALRUNNER_GAME_H
