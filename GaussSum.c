#include <stdio.h>
#include <stdlib.h>

#define INITIAL_VALUE 1
#define MAX_VALUE 100
int main() {
	
	int isOdd =(( MAX_VALUE - INITIAL_VALUE + 1) % 2 == 0);	
	if(!isOdd){
		printf("Please, set up INITIAL_VALUE and MAX_VALUE so the amount of integer in the range between them are odd, e.g, 1 to 6, 1 to 100.\n");
		exit(-1);
	}	
	int numbers[MAX_VALUE];
	int sum = 0;	
	// populate array with numbers from INITIAL_VALUE to MAX_VALUE 
	for(int i = INITIAL_VALUE; i <= MAX_VALUE; i++) {
		numbers[i-1] = i;
	}

	// using the method
	for(int j = 0; j < MAX_VALUE/2; j++){
		sum += numbers[j] + numbers[MAX_VALUE-j-1];
	}

	printf("Answer = %d\n", sum);
}
