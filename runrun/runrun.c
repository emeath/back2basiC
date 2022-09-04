#include <stdio.h>
#include <stdlib.h>
#include "runrun.h"

char** map; 
int lines;
int columns;

void freeMapMemory() {
	for(int i = 0; i < lines; i++) {
		free(map[i]);
	}
	free(map);
}

void alocatesMapMemory() {
	map = malloc(sizeof(char*) * lines);
	for(int i = 0; i < lines; i++) {
		map[i] = malloc(sizeof(char) * (columns + 1)); // +1 -> room for '\0' at the end of string
	}
}

void readsMap() {

	FILE* f;
	f = fopen("map.txt", "r");
	if(f == 0) {
		printf("Error reading the map file\n");
		exit(1);
	}
	
	fscanf(f, "%d %d", &lines, &columns);

	alocatesMapMemory();

	for(int i = 0; i < lines; i++) {
		fscanf(f, "%s", map[i]);
	}

	fclose(f);
}

int main() {

	readsMap();

	for(int i = 0; i < lines; i++) {
		printf("%s\n", map[i]);
	}
	
	freeMapMemory();

	return 0;
}
