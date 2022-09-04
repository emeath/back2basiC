#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define GHOST_RANDOM_MOV_NUMBER_OF_ATTEMPTS 10

int gameOver();
void move(char direction);
int isValidDirection(char direction);
int whereGhostGoes(int currentX, int currentY, int* destinyX, int* destinyY);
