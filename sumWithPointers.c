#include <stdio.h>

void sumWithPointers(int* num, int a, int b) {
	(*num) = a + b;
}

int main() {
	int answer = 0;
	int aMain = 9;
	int bMain = 33;
	sumWithPointers(&answer, aMain, bMain);

	printf("Answer is: %d + %d = %d\n", aMain, bMain, answer);

	return 0;
}
