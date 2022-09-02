#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_ATTEMPS 5
#define INITIAL_SCORE 1000

int main() {

	// print game header
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~ Welcome to our guessing number game! :) ~\n"); 	
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	int secretNumber = 42;

	int guess;
	int attempt = 1;

	double score = INITIAL_SCORE;
	while(1) {
		printf("Attempt %d\n", attempt);
		printf("What is your guess number? ");
		scanf("%d", &guess);
		printf("Your attempt is: %d\n", guess);

		if(guess < 0) {
			printf("You can not guess negative numbers!\n");
			continue;
		}

		int correctGuess = (guess == secretNumber);
		int bigger = (guess > secretNumber);

		if(correctGuess) {
			printf("Congratulations! You got it!\n");
			printf("You should play again. You are such a good player! :D\n");

			break;
		} else if(bigger) {
			printf("Your guess is bigger than the secret number!\n");
		} else {
			printf("Your guess is smaller than the secret number!\n");
		}

		attempt++;

		// compute score
		score = score - abs(secretNumber - guess)/2.0;
	}

	printf("Game over!\n");
	printf("You won with #%d attempts!\n", attempt);
	printf("You scored: %.2f points!\n", score);
	return 0;
	
}
