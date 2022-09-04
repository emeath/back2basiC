#ifndef _MAP_H_
#define _MAP_H_

#define HERO '@'
#define GHOST 'F'
#define EMPTY '.'
#define VERTICAL_WALL '|'
#define HORIZONTAL_WALL '-'
#define PILL 'P'

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
int findsOnMap(MAP* m, POSITION* p, char c);
int isValid(MAP* m, int x, int y);
int isEmpty(MAP* m, int x, int y);
void walksOnMap(MAP* m, int originX, int originY, int destinyX, int destinyY);
void ghosts();
void copyMap(MAP* origin, MAP* destiny);
int canMove(MAP* m, char character, int x, int y);
int isWall(MAP* m, int x, int y);
int isCharacter(MAP* m, char character, int x, int y);

#endif
