#include <stdio.h>

#define MAX_VALUE 100
#define INITIAL_VALUE 1

int main() {
	printf("printing numbers from %d to %d\n", INITIAL_VALUE, MAX_VALUE);
	int counter = 0;
	int number = INITIAL_VALUE;
	while(counter < MAX_VALUE) {
		printf("#%d\n", number++);
		counter++;
	}
	return 0;
}	
