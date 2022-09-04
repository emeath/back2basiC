#include <stdio.h>
#include <stdlib.h>

int main() {
	int lines = 5;
	int columns = 10;

	int** matrix;

	matrix = malloc(sizeof(int*) * lines);
	for(int i = 0; i < lines; i++) {
		matrix[i] = malloc(sizeof(int) * columns);
	}

	for(int m = 0; m < lines; m++) {
		for(int n = 0; n < columns; n++) {
			matrix[m][n] = 0;
		}
	}

	for(int l = 0; l < lines; l++) {
		for (int c = 0; c < columns; c++) {
			printf("[%d]", matrix[l][c]);
		}
		printf("\n");
	}

	// free memory
	
	for(int i = 0; i < lines; i++) {
		free(matrix[i]);
	}
	free(matrix);

	return 0;
}
