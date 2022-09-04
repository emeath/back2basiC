#include <stdio.h>
#include <stdlib.h>
#include "runrun.h"

struct map m;

void freeMapMemory() {
	for(int i = 0; i < m.lines; i++) {
		free(m.matrix[i]);
	}
	free(m.matrix);
}

void alocatesMapMemory() {
	m.matrix = malloc(sizeof(char*) * m.lines);
	for(int i = 0; i < m.lines; i++) {
		m.matrix[i] = malloc(sizeof(char) * (m.columns + 1)); // +1 -> room for '\0' at the end of string
	}
}

void readsMap() {

	FILE* f;
	f = fopen("map.txt", "r");
	if(f == 0) {
		printf("Error reading the map file\n");
		exit(1);
	}
	
	fscanf(f, "%d %d", &(m.lines), &(m.columns));

	alocatesMapMemory();

	for(int i = 0; i < m.lines; i++) {
		fscanf(f, "%s", m.matrix[i]);
	}

	fclose(f);
}

void printsMap() {
	for(int i = 0; i < m.lines; i++) {
		printf("%s\n", m.matrix[i]);
	}
}

int gameOver() {
	return 0;
}

void move(char direction) {
	int x;
	int y;

	for(int i = 0; i < m.lines; i++) {
		for(int j = 0; j < m.columns; j++) {
			if(m.matrix[i][j] == '@') {
				x = i;
				y = j;
				break;
			}
		}
	}

	switch(direction) {
		case 'a': 
			m.matrix[x][y-1] = '@';
			break;
		case 'w':
			m.matrix[x-1][y] = '@';
			break;
		case 's':
			m.matrix[x+1][y] = '@';
			break;
		case 'd':
			m.matrix[x][y+1] = '@';
			break;
	}

	m.matrix[x][y] = '.';
}

int main() {

	readsMap();
	
	do {
		printsMap();

		char command;
		scanf(" %c", &command);

		move(command);
	} while(!gameOver());

	freeMapMemory();

	return 0;
}
