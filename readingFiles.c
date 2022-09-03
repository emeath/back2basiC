#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE* filePointer;
	filePointer = fopen("pokemons.txt", "r");
	if(filePointer == 0) {
		printf("There was an error when openning the file.\n");
		exit(1);
	}


	int numberOfPokemons = 0;

	fscanf(filePointer, "%d", &numberOfPokemons);

	for(int i = 0; i < numberOfPokemons; i++) {
		char pokemon[64];
		fscanf(filePointer, "%s", pokemon);
		printf("Pokemon #%d: %s\n", i+1, pokemon);
	}
	fclose(filePointer);
	
	return 0;
}
