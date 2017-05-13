//
// Created by kai on 5/13/17.
//

#include <ncurses.h>
#include "Player.h"

Player::Player(int xPos, int yPos, int gameHeight):xPos(xPos),yPos(yPos),freeFallTime(0),gameHeight(gameHeight),prevY(yPos){}

void Player::moveUp() {
    yPos--;
    if(yPos<1)yPos =1;
    freeFallTime = 0;
}

void Player::moveDown() {
    freeFallTime ++;
    yPos+=(freeFallTime*freeFallTime)*acceleration;
    if(yPos>=gameHeight-1)yPos = gameHeight-2;
}

void Player::reset() {
    freeFallTime = 0;
    yPos = gameHeight/2;
}

void Player::draw(WINDOW * window) {
    mvwaddch(window,prevY,xPos,' ');           //remove old player char.
    mvwaddch(window,yPos,xPos,playerSymbol);    //place new player char.
    prevY = yPos;
}

int Player::getY() {
    return yPos;
}

int Player::getX() {
    return xPos;
}

