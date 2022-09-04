struct map {
    char** matrix;
    int lines;
    int columns;
};



void freeMapMemory();
void alocatesMapMemory();
void readsMap();
void move(char direction);
int gameOver();
void printsMap();
