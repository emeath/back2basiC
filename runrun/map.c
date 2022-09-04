#include <stdio.h>
#include <stdlib.h>
#include "map.h"

void findsOnMap(MAP* m, POSITION* p, char c) {
    for(int i = 0; i < m->lines; i++) {
		for(int j = 0; j < m->columns; j++) {
			if(m->matrix[i][j] == c) {
				p->x = i;
				p->y = j;
				break;
			}
		}
	}
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

void printsMap(MAP* m) {
	for(int i = 0; i < m->lines; i++) {
		printf("%s\n", m->matrix[i]);
	}
}
