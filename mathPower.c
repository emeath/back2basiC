#include <stdio.h>

void power(int a, int b) {
	int answer = 1;
	for(int i = 0; i < b; i++) {
		answer *= a;
	}
	printf("Answer = %d^%d = %d\n", a, b, answer);
}

int main() {
	power(2, 3);
	power(2, 30);
	power(9, 3);

	return 0;
}
