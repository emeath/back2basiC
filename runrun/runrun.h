#ifndef _RUNRUN_H_
#define _RUNRUN_H_

#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define GHOST_RANDOM_MOV_NUMBER_OF_ATTEMPTS 10
#define BOMB 'b'

int gameOver();
void move(char direction);
int isValidDirection(char direction);
int whereGhostGoes(int currentX, int currentY, int* destinyX, int* destinyY);
void explodesPill();
void explodesPill2(int x, int y, int addX, int addY, int quantity);

#endif
