#include <stdio.h>

void powerPointers(int* ans, int a, int b) {
	(*ans) = 1;	
	for(int i = 0; i < b; i++) {
		(*ans) = (*ans) * a;
	}
}

int main() {
	int answer = 1;
	powerPointers(&answer, 10, 3);
	printf("%d^%d = %d\n", 10, 3, answer);
	powerPointers(&answer, 92, 2);
	printf("%d^%d = %d\n", 92, 2, answer);
	powerPointers(&answer, 3, 6);
	printf("%d^%d = %d\n", 3, 6, answer);
	
	return 0;
}
