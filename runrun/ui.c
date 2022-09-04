#include <stdio.h>
#include "map.h"

char wallDrawing[4][7] = {
	{"......" },
	{"......" },
	{"......" },
	{"......" }
};

char ghostDrawing[4][7] = {
	{" .-.  " },
	{"| OO| " },
	{"|   | " },
	{"'^^^' " }
};

char heroDrawing[4][7] = {
	{" .--. "  },
	{"/ _.-'"  },
	{"\\  '-." },
	{" '--' "  }
};

char pillDrawing[4][7] = {
	{"      "},
	{" .-.  "},
	{" '-'  "},
	{"      "}
};

char emptyDrawing[4][7] = {
	{"      "},
	{"      "},
	{"      "},
	{"      "}
};

char gameOverDrawing[25][50] = {
    {"...................................." },
    {"@@@ººº@@.@@@ººº@@@.@@@º@o@º@@@.@@ººº" },
    {"@@....@@.@@.....@@.@@...@...@@.@@..." },
    {"@@...ooo.@@ooooo@@.@@...º...@@.@@ººº" },
    {"@@....@@.@@.....@@.@@.......@@.@@..." },
    {"@@@ooo@@.@@.....@@.@@.......@@.@@ooo" },
    {"...................................." },
    {"@@@ººº@@@.º@@@..@@º.@@ººº.@@ºººº@@o." },
    {"@@.....@@...@@..@@..@@....@@.....@@." },
    {"@@.....@@...@@..@@..@@ººº.@@oooooºº." },
    {"@@.....@@...@@..@º..@@....@@.....@@." },
    {"@@@ooo@@@...─º@º..─.@@ooo.@@.....@@o" },
    {"...................................." },
    {"........@@...............@@........." },
    {"......@@@@o...ooooooo...o@@@@......." },
    {".........ºº@o@@@@@@@@@o@ºº.........." },
    {"...........@@@@@@@@@@@@@............" },
    {"...........@@ººº@@@ººº@@............" },
    {"...........@@...@@@...@@............" },
    {"...........@@@@@ºoº@@@@@............" },
    {"............@@@@@@@@@@@............." },
    {"........ooo@@..@º@º@..@@ooo........." },
    {"........ºº@@...........@@ºº........." },
    {"..........ºº...........ºº..........." },
    {"...................................." }
};  
 
void printsGameOver() {
    printf("\n\n");
    for(int i = 0; i < 25; i++) {
        printf("%s", gameOverDrawing[i]);
        printf("\n"); 
    }
    printf("\n\n");
}

void printPart(char drawing[4][7], int part) {
    printf("%s", drawing[part]);
}

void printsMap(MAP* m) {
    for(int i = 0; i < m->lines; i++) {
        for(int part = 0; part < 4; part++) {
            for(int j = 0; j < m->columns; j++) {
                switch(m->matrix[i][j]) {
                    case GHOST:
                        printPart(ghostDrawing, part);
                        break;   
                    case HERO:
                        printPart(heroDrawing, part);
                        break;     
                    case PILL:
                        printPart(pillDrawing, part);
                        break;     
                    case VERTICAL_WALL:
                    case HORIZONTAL_WALL:
                        printPart(wallDrawing, part);
                        break;     
                    case EMPTY:
                        printPart(emptyDrawing, part);
                        break;         
                } 
            }

        
            printf("\n");    
        }
    }
}
