struct map {
    char** matrix;
    int lines;
    int columns;
};

struct position {
    int x;
    int y;
};

typedef struct map MAP;
typedef struct position POSITION;


void freeMapMemory(MAP* m);
void alocatesMapMemory(MAP* m);
void readsMap(MAP* m);
void printsMap(MAP* m);
void findsOnMap(MAP* m, POSITION* p, char c);
