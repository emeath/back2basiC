#include <stdio.h>
#include <stdlib.h>
#include "runrun.h"
#include "map.h"

MAP m;
POSITION hero;

int gameOver() {
	return 0;
}

void move(char direction) {

    //handling user input
    if(direction != 'a' &&
        direction != 's' &&
        direction != 'd' &&
        direction != 'w')
        return;

    int nextX = hero.x;
    int nextY = hero.y;

	switch(direction) {
		case 'a': 
			nextY--;
			break;
		case 'w':
			nextX--;
            break;
		case 's':
			nextX++;
            break;
		case 'd':
			nextY++;
   			break;
	}

    if(nextX >= m.lines)
        return;
    if(nextY >= m.columns)
        return;
    if(m.matrix[nextX][nextY] != '.')
        return;

    m.matrix[nextX][nextY] = '@';
    m.matrix[hero.x][hero.y] = '.';
    hero.x = nextX;
    hero.y = nextY;
    
}

int main() {

	readsMap(&m);
    findsOnMap(&m, &hero, '@');
	
	do {
		printsMap(&m);

		char command;
		scanf(" %c", &command);

		move(command);
	} while(!gameOver());

	freeMapMemory(&m);

	return 0;
}
