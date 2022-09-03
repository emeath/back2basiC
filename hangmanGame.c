#include <stdio.h>
#include <string.h>


char secretWord[20];
char guesses[26];
int atempts = 0;

void printHeaderBaner() {
	printf("********************\n");
	printf("*   Hangman Game   *\n");
	printf("********************\n\n");
}

void playerGuesses() {
	char guess;
	printf("Which letter you want to guess? ");
	scanf(" %c", &guess); // note that there is a space then char mask.
	// this is used to ignore 'enter' in the buffer
	
	guesses[atempts] = guess;
}

int alreadyGuessed(chat letter) {
	int booleanRightAnswer = 0;
	for(int i = 0; i < attempts; i++) {
		if(guesses[i] == letter) {
			booleanRightAnswer = 1;
			break;
		}
	}

	return booleanRightAnswer;
}

void drawHanger() {
	printf("You have tried %d times\n", attemps);
	for(int i = 0; i < strlen(secretWord); i++) {
		if(alreadyGuessed(secretWord[i])) {
				printf("%c ", secretWord[i]);
		} else {
			printf("_ ");
		}
	}
	printf("\n");
}

void choseWord() {
	sprinf(secretWord, "WATERMELON");
}

int main() {

	int booleanRightAnswer = 0;
	int booleanHanged = 0;

	choseWord();
	printHeaderBaner();

	do {
		drawHanger();
		playerGuesses();

		attempts++;
	} while (!booleanRightAnswer && !booleanHanged);

	return 0;
}
