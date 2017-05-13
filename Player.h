//
// Created by kai on 5/13/17.
//

#ifndef TERMINALRUNNER_PLAYER_H
#define TERMINALRUNNER_PLAYER_H


#include "Entity.h"

class Player {

private:
    char playerSymbol = '@';
    int yPos;
    const int xPos;
    int prevY;
    int freeFallTime = 0;
    const double acceleration = 0.01;
    int gameHeight;

public:
    Player(int xPos, int yPos, int gameHeight);

    void moveUp();

    void moveDown();

    void reset();

    void draw(WINDOW * window);

    int getY();

    int getX();
};
#endif //TERMINALRUNNER_PLAYER_H
