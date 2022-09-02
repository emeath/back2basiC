#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
	int n = rand();
	printf("Random number is: %d\n", n);

	int secondsSince1_1_1970 = time(0);
	srand(secondsSince1_1_1970);

	int n2 = rand();
	printf("Random number with seed: %d\n", n2);
	
	return 0;
}
