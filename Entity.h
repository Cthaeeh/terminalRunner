//
// Created by kai on 5/13/17.
// Represents something in the game that is not the player.
//

#ifndef TERMINALRUNNER_ENTITY_H
#define TERMINALRUNNER_ENTITY_H


#include <ncurses.h>

class Entity {

public:
    bool canBeRemoved = false;

    virtual void draw(WINDOW * window) = 0;

    virtual void move() = 0;

    virtual bool isHit(int xVal, int yVal) = 0;
};

#endif //TERMINALRUNNER_ENTITY_H
