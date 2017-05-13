//
// Created by kai on 5/13/17.
//

#include "Game.h"
#include "Obstacle.h"
#include <random>
#include <unistd.h>

std::random_device rd;
std::mt19937 rng(rd());
std::uniform_int_distribution<int> uni100(0,100);
std::uniform_int_distribution<int> uni10(0,10);
std::uniform_int_distribution<int> uni5(0,5);
std::uniform_int_distribution<int> uni3(0,3);

Game::Game(int highScore): highScore(highScore){
    initNCurse();
    player = new Player(COLS/2,LINES/2,LINES);
}

void Game::initNCurse() {
    initscr();
    start_color();
    raw();                  // line buffering disabled
    keypad(stdscr, TRUE);   // so we get special keys available.
    noecho();
    timeout(50);
}

void Game::start() {
    window = newwin(LINES,COLS,0,0);    //full size window.
    refresh();
    box(window,0,0);                    //draw box around.
    wrefresh(window);
    printDescriptions();
    mainLoop();
}

void Game::mainLoop() {
    while (true){
        int input = getch();
        if(input == 'x'){
            break;
        } else{
            processInput(input);
        }
        manageObstacles();
        checkIfDead();
        score++;
        draw();
    }
    endwin(); //free ncurse ressources.
}

void Game::processInput(int input) {
    switch(input){
        case KEY_UP:
                player->moveUp();
            break;
        case 'r':
                end();
            break;
        default:
                player->moveDown();
            break;
    }
}

void Game::draw() {
    player->draw(window);
    for(Entity* entity : entities){
        entity->move();
        entity->draw(window);
    }
    wmove(window,0,0);
    wprintw(window,"Score: %d",score);
    wrefresh(window);
}

// creates and deletes obstacles.
void Game::manageObstacles() {
    if(score%10==0){
        if(chanceOf100(33+score/50)){     //for example 1% chance of creating an obstacle
            entities.push_back(new Obstacle(COLS+1,1,uni10(rng)+uni3(rng)));
            entities.push_back(new Obstacle(COLS+1,LINES-2-uni5(rng),LINES-2));
        }
    }
    auto elem = std::begin(entities);
    while( elem != std::end(entities)){
        if((*elem)->canBeRemoved){
            elem = entities.erase(elem);        // clean up.
        } else{
            ++elem;
        }
    }

}

void Game::printDescriptions() {
    init_pair(1,COLOR_GREEN,COLOR_BLACK);
    wattron(window,COLOR_PAIR(1));
    mvwaddstr(window,0,COLS/2-10, " TERMINAL FLAPPY BIRD ");
    mvwaddstr(window,LINES-1,COLS/2-26," press r for restart, press UP to fly, x to quit. ");
    wrefresh(window);
    wattroff(window,COLOR_PAIR(1));
}

bool Game::chanceOf100(int percent) {
    auto random_integer = uni100(rng);
    if(random_integer<=percent){
        return true;
    }
    return false;
}

void Game::checkIfDead() {
    int playerX = player->getX();
    int playerY = player->getY();
     for(Entity* entity : entities){
         if(entity->isHit(playerX,playerY)){
             end();
         }
    }
    wrefresh(window);
}

void Game::end() {
    erase();    //clear screen quickly.
    refresh();
    if(score>highScore)highScore = score;

    mvwaddstr(window,LINES/2-1,COLS/2-10,"   THE END   ");
    wmove(window,LINES/2+1,COLS/2-10);
    wprintw(window,"Score: %d High score: %d",score,highScore);
    wrefresh(window);

    player->reset();
    score = 0;
    entities.clear();

    sleep(3);
    start();

}

