//
// Created by kai on 5/13/17.
// A simple obstacle that moves from right to left.
//

#include "Obstacle.h"

Obstacle::Obstacle(int xPos, int yStart, int yEnd): xPosition(xPos), prevXPos(xPos),yStart(yStart),yEnd(yEnd) {}

bool Obstacle::isHit(int xVal, int yVal) {
    if(xVal != xPosition){      //since an obstacle is only one unit wide, something did hit the obstacle if the x values are equal.
        return false;
    }
    if(yVal > yEnd) return false; //check upper border of obstacle.
    if(yVal < yStart) return false; //check lower border of obstacle.

    return true;
}

void Obstacle::draw(WINDOW * window) {
    int temp = yStart;
    while(temp<=yEnd){
        mvwaddch(window, temp, prevXPos, ' ');
        mvwaddch(window,temp,xPosition,'#');
        temp++;
    }
    prevXPos = xPosition;   //save previous pos so we can delete it later.
}

void Obstacle::move() {
    xPosition--;    //move from left to right.
    if(xPosition< 0) canBeRemoved = true;
}
