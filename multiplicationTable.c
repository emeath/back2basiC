#include <stdio.h>

int main() {
	int number = 0;
	printf("Enter a number to get the multiplication table: ");
	scanf("%d", &number);
	for(int i = 0; i < 10; i++) {
		printf("%d x %d = %d\n", number, i+1, number*(i+1));
	}

	return 0;
}
