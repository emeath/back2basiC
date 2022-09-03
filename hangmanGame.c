#include <stdio.h>
#include <string.h>

void printHeaderBaner() {
	printf("********************\n");
	printf("*   Hangman Game   *\n");
	printf("********************\n\n");
}

void playerGuesses(char guesses[26], int atempts) {
	char guess;
	scanf(" %c", &guess); // note that there is a space then char mask.
	// this is used to ignore 'enter' in the buffer
	
	guesses[atempts] = guess;
	atempts++;
}

int main() {
	char secretWord[20];

	sprintf(secretWord, "watermelon");

	int booleanRightAnswer = 0;
	int booleanHanged = 0;

	char guesses[26];
	int atempts;

	printHeaderBaner();

	return 0;
}
