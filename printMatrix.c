#include <stdio.h>

int main() {
	int matrix[20][10];
	for(int i = 0; i < 20; i++) {
		for(int j = 0; j < 10; j++) {
			printf("[%d]", matrix[i][j]);
		}
		printf("\n");
	}

	return 0;
}
