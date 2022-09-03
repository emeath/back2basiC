#include <stdio.h>

int sum(int* array, int size) {
	int total = 0;
	for(int i = 0; i < size; i++) {
		total += array[i];
	}
	return total;
}

int main() {
	int numbers[3];
	numbers[0] = 10;
	numbers[1] = 20;
	numbers[2] = 30;

	int answer = sum(numbers, 3);
	printf("the answer is: %d\n", answer);
}
