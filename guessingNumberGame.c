#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER_OF_ATTEMPS 5
#define INITIAL_SCORE 1000

int main() {

	// print game header
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~ Welcome to our guessing number game! :) ~\n"); 	
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	int secondsSince1970 = time(0);
	srand(secondsSince1970);	
	int secretNumber = rand() % 1000; // numbers from 0 to 1000

	int guess;
	int attempt = 1;
	int difficulty;
	printf("Select the game difficulty:\n");
	printf("(1) Easy (2) Normal (3) Hard\n");
	printf(">> ");
	scanf("%d", &difficulty);

	int lives;
	
	switch(difficulty) {
		case 1:
			lives = 20;
			break;
		case 2:
			lives = 10;
			break;
		default:
			lives = 5;
			break;
	}

	int correctGuess;

	double score = INITIAL_SCORE;
	for(int i = 0; i < lives; i++) {
		printf("Attempt %d\n", attempt);
		printf("What is your guess number? ");
		scanf("%d", &guess);
		printf("Your guess is: %d\n", guess);

		if(guess < 0) {
			printf("You can not guess negative numbers!\n");
			i--; // the player will not lose his life on this scenario;
			continue;
		}

		correctGuess = (guess == secretNumber);
		int bigger = (guess > secretNumber);

		if(correctGuess) {
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
	if(correctGuess) {
		printf("Congratulations! You got it!\n");
		printf("You should play again. You are such a good player! :D\n");
		printf("You won with #%d attempts!\n", attempt);
		printf("You scored: %.2f points!\n", score);
	} else {
		printf("try again!\n");
	}
	return 0;
	
}
