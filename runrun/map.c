#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

void copyMap(MAP* destiny, MAP* origin) {
    destiny->lines = origin->lines;
    destiny->columns = origin->columns;
    
    alocatesMapMemory(destiny);
    for(int i = 0; i < origin->lines; i++) {
        strcpy(destiny->matrix[i], origin->matrix[i]);
    }
    
    
}

void walksOnMap(MAP* m, int originX, int originY, int destinyX, int destinyY) {
    char character = m->matrix[originX][originY];
    m->matrix[destinyX][destinyY] = character;
    m->matrix[originX][originY] = EMPTY;
}

int isWall(MAP* m, int x, int y) {
    return m->matrix[x][y] == VERTICAL_WALL || m->matrix[x][y] == HORIZONTAL_WALL;
}

int isCharacter(MAP* m, char character, int x, int y) {
    return m->matrix[x][y] == character;
}

int isValid(MAP* m, int x, int y) {
    if(x >= m->lines)
        return 0;
    if(y >= m->columns) 
        return 0;

    return 1;
}

int isEmpty(MAP* m, int x, int y) {
    return m->matrix[x][y] == EMPTY;
}

int canMove(MAP* m, char character, int x, int y) {
    return isValid(m, x, y) && !isWall(m, x, y) && !isCharacter(m, character, x, y);
}


int findsOnMap(MAP* m, POSITION* p, char c) {
    for(int i = 0; i < m->lines; i++) {
		for(int j = 0; j < m->columns; j++) {
			if(m->matrix[i][j] == c) {
				p->x = i;
				p->y = j;
				return 1;
			}
		}
	}

    return 0;
}

void freeMapMemory(MAP* m) {
	for(int i = 0; i < m->lines; i++) {
		free(m->matrix[i]);
	}
	free(m->matrix);
}

void alocatesMapMemory(MAP* m) {
	m->matrix = malloc(sizeof(char*) * m->lines);
	for(int i = 0; i < m->lines; i++) {
		m->matrix[i] = malloc(sizeof(char) * (m->columns + 1)); // +1 -> room for '\0' at the end of string
	}
}

void readsMap(MAP* m) {

	FILE* f;
	f = fopen("map.txt", "r");
	if(f == 0) {
		printf("Error reading the map file\n");
		exit(1);
	}
	
	fscanf(f, "%d %d", &(m->lines), &(m->columns));

	alocatesMapMemory(m);

	for(int i = 0; i < m->lines; i++) {
		fscanf(f, "%s", m->matrix[i]);
	}

	fclose(f);
}
