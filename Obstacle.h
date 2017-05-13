//
// Created by kai on 5/13/17.
//

#ifndef TERMINALRUNNER_OBSTACLE_H
#define TERMINALRUNNER_OBSTACLE_H
#include "Entity.h"

class Obstacle : public Entity{
    int prevXPos;
    int xPosition;
    int yStart;
    int yEnd;


public:
    Obstacle(int xPos, int yStart, int yEnd);
    bool isHit(int xVal, int yVal) override ;

    int getX();
    void draw(WINDOW * window) override ;
    void move() override ;
};


#endif //TERMINALRUNNER_OBSTACLE_H
