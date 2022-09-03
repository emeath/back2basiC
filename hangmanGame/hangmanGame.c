#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "hangmanGame.h"

char secretWord[SIZE_SECRET_WORD];
char guesses[26];
int attempts = 0;

int letterExists(char letter) {
    for(int j = 0; j < strlen(secretWord); j++) {
        if(letter == secretWord[j]) {
            return 1;
        }
    }
    return 0;
}

int wrongGuesses() {
    int wrongs = 0;
    for(int i = 0; i < attempts; i++)  {
        if(!letterExists(guesses[i])) {
            wrongs++;        
        }
    }
    return wrongs;
}

int hanged() {
    return wrongGuesses() >= CHANCES;
}

int playerWon() {
    for(int i = 0; i < strlen(secretWord); i++) {
        if(!alreadyGuessed(secretWord[i])) {
            return 0;
        }    
    }
    return 1;
}

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
	
    if(letterExists(guess)) {
        printf("You guessed the right letter. The secret word contains the letter %c\n\n", guess);
    } else {
        printf("\nYou missed! The secret word do NOT has the letter %c\n\n", guess);    
    }

	guesses[attempts] = guess;
    attempts++;
}

int alreadyGuessed(char letter) {
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
    int wrongs = wrongGuesses();

    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (wrongs >= 1 ? '('  : ' ' ), (wrongs >= 1 ? '_' : ' '), (wrongs >= 1 ? ')' : ' '));
    printf(" |      %c%c%c  \n", (wrongs >= 3 ? '\\' : ' ' ), (wrongs >= 2 ? '|' : ' '), (wrongs >= 3 ? '/' : ' '));
    printf(" |       %c     \n", (wrongs >= 2 ? '|'  : ' ' ));
    printf(" |      %c %c   \n", (wrongs >= 4 ? '/'  : ' ' ), (wrongs >= 4 ? '\\' :' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

    for(int i = 0; i < strlen(secretWord); i++) {
		if(alreadyGuessed(secretWord[i])) {
				printf("%c ", secretWord[i]);
		} else {
			printf("_ ");
		}
	}
	printf("\n");
}

void checkOpenFileOperation(FILE* f) {
    if(f == 0) {
        printf("Words database is not available right now!\n\n");
        exit(1);  
    }
}

void choseWord() {
	FILE* fp;
    fp = fopen(DATABASE_FILE_NAME, "r");
    checkOpenFileOperation(fp);

    int amountWords;
    fscanf(fp, "%d", &amountWords);

    srand(time(0));
    int randomValue = rand() % amountWords;

    for(int i = 0; i <= randomValue; i++) {
        fscanf(fp, "%s", secretWord);
    }

    fclose(fp);
}

void addWordToDataBase() {
    char userChoice;
    printf("Do you want to add a new word in the game (Y/N)? ");
    scanf(" %c", &userChoice);

    if(userChoice == 'Y') {

        char newWord[SIZE_SECRET_WORD];

        printf("Enter the new word in UPPERCASE, please: ");
        scanf("%s", newWord);
        
        FILE* fp;
        fp = fopen(DATABASE_FILE_NAME, "r+");
        checkOpenFileOperation(fp);

        int quantity;
        fscanf(fp, "%d", &quantity);
        quantity++;

        fseek(fp, 0, SEEK_SET); // put pointer on first line and first byte
        fprintf(fp, "%d", quantity); // overwrite quantity amount in the first line of the database word file

        fseek(fp, 0, SEEK_END); // put pointer on the bottom of file to insert a new word at the end
        fprintf(fp, "\n%s", newWord);


        fclose(fp);    
    }
}

int main() {

	choseWord();
	printHeaderBaner();

	do {

		drawHanger();
		playerGuesses();

	} while (!playerWon() && !hanged());

    if(playerWon()) {

        printf("\nCongratulations, you won!\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");

    } else {

        printf("\nOh no! You were hanged\n");
        printf("Thw secret word was **%s**\n\n", secretWord);

        printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");

    }

    addWordToDataBase();

	return 0;
}
