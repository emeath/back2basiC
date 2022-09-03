#include <stdio.h>

void sumArrayElements(int array[10]) {
	int ans = 0;
	for(int i = 0; i < 10; i++) {
		ans += array[i];
	}
	printf("Sum of elements: %d\n", ans);
}

int main() {
	int numbers[10];
	for(int i = 0; i < 10; i++) {
		numbers[i] = i+1;
	}
	sumArrayElements(numbers);
}
