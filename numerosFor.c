#include <stdio.h>

#define MAX_NUMBER 100
#define INITIAL_NUMBER 1
int main() { 
	printf("printing numbers from %d to %d\n", INITIAL_NUMBER, MAX_NUMBER);

	for(int i = INITIAL_NUMBER; i <= MAX_NUMBER; i++) {
		printf("#%d\n", i);
	}	
	
	return 0;
}

