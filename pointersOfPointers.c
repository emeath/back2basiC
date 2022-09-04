#include <stdio.h>

int main() {
	int numbers[4][2];

	int* line0 = numbers[0];
	int* line1 = numbers[1];
	int* line2 = numbers[2];
	int* line3 = numbers[3];


	printf("%p %p\n", line2, &numbers[2]);
	
	return 0;
}
