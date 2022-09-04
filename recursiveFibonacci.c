#include <stdio.h>

int computeFibonacci(int n) {
	if(n == 0) return 0;
	if(n == 1) return 1;
	return computeFibonacci(n - 1) + computeFibonacci(n - 2);
}

int main() {
	int number = 4;
	printf("The Fibonnaci of %d F(%d) is: %d\n", number, number, computeFibonacci(number));

	return 0;
}
