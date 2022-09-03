#include <stdio.h>
#include <string.h>

void printHeaderBaner() {
	printf("********************\n");
	printf("*   Hangman Game   *\n");
	printf("********************\n\n");
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
