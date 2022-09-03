#define SIZE_SECRET_WORD 32
#define CHANCES 5
#define DATABASE_FILE_NAME "words.txt"

void printHeaderBaner();
int letterExists(char letter);
int wrongGuesses();
int hanged();
int playerWon();
void playerGuesses();
int alreadyGuessed(char letter);
void drawHanger();
void choseWord();
void addWordToDataBase();
void checkOpenFileOperation(FILE* f);
