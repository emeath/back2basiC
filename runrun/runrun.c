#include <stdio.h>
#include <stdlib.h>

int main() {
	char map[5][10+1]; // +1 -> room for '\0' at the end of string

	FILE* f;
	f = fopen("map.txt", "r");
	if(f == 0) {
		printf("Error reading the map file\n");
		exit(1);
	}

	for(int i = 0; i < 5; i++) {
		fscanf(f, "%s", map[i]);
	}
	for(int i = 0; i < 5; i++) {
		printf("%s\n", map[i]);
	}
	fclose(f);

	return 0;
}
