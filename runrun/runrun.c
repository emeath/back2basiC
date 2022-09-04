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

    m.matrix[hero.x][hero.y] = '.';

	switch(direction) {
		case 'a': 
			m.matrix[hero.x][hero.y-1] = '@';
            hero.y--;   
			break;
		case 'w':
			m.matrix[hero.x-1][hero.y] = '@';
            hero.x--;			
            break;
		case 's':
			m.matrix[hero.x+1][hero.y] = '@';
            hero.x++;			
            break;
		case 'd':
			m.matrix[hero.x][hero.y+1] = '@';
            hero.y++;
   			break;
	}

    
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
