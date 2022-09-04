#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "runrun.h"
#include "map.h"

MAP m;
POSITION hero;


int whereGhostGoes(int currentX, int currentY, int* destinyX, int* destinyY) {
    int options[4][2] = {
        {currentX, currentY + 1},
        {currentX + 1, currentY},
        {currentX, currentY - 1},
        {currentX - 1, currentY}
    };

    srand(time(0));
    for(int i = 0; i < GHOST_RANDOM_MOV_NUMBER_OF_ATTEMPTS; i++) {
        int position = rand() % 4;

        if(canMove(&m, GHOST, options[position][0], options[position][1])) {
            *destinyX = options[position][0];
            *destinyY = options[position][1];

            return 1;
        }

        return 0;
    }
}


void ghosts() {

    MAP copy;

    copyMap(&copy, &m);

    for(int i = 0; i < m.lines; i++) {
        for(int j = 0; j < m.columns; j++) {
            if(copy.matrix[i][j] == GHOST) {

                int destinyX;
                int destinyY;

                int found = whereGhostGoes(i, j, &destinyX, &destinyY);

                if(found) {
                    walksOnMap(&m, i, j, destinyX, destinyY);                
                }

            }
        }
    }
}

int gameOver() {
    POSITION pos;
    int runrunIsOnMap = findsOnMap(&m, &pos, HERO);
    return !runrunIsOnMap;
}

int isValidDirection(char direction) {
    return (direction == 'a' ||
            direction == 's' ||
            direction == 'd' ||
            direction == 'w');
}

void move(char direction) {

    if(!isValidDirection(direction))
        return;

    int nextX = hero.x;
    int nextY = hero.y;

	switch(direction) {
		case LEFT: 
			nextY--;
			break;
		case UP:
			nextX--;
            break;
		case DOWN:
			nextX++;
            break;
		case RIGHT:
			nextY++;
   			break;
	}

    if(!canMove(&m, HERO, nextX, nextY))
        return;

    walksOnMap(&m, hero.x, hero.y, nextX, nextY);
    hero.x = nextX;
    hero.y = nextY;
}

int main() {

	readsMap(&m);
    findsOnMap(&m, &hero, HERO);
	
	do {
		printsMap(&m);

		char command;
		scanf(" %c", &command);

		move(command);
        ghosts();
	} while(!gameOver());

	freeMapMemory(&m);

	return 0;
}
