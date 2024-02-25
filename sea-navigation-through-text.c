#include <stdio.h>

typedef struct coordinate_struct
{
    float x;
    float y;
} coordinate;

typedef struct ship_struct
{
    coordinate ship_coordinate;
} ship;

void go_north(ship *pShip)
{
    pShip->ship_coordinate.y += 5;
}

void go_south(ship *pShip)
{
    pShip->ship_coordinate.y -= 5;
}

void go_east(ship *pShip)
{
    pShip->ship_coordinate.x += 5;
}

void go_west(ship *pShip)
{
    pShip->ship_coordinate.x -= 5;
}

void display_ship_coordinate(ship *pShip)
{
    printf("You are at coordinate [x: %f | y: %f]\n", pShip->ship_coordinate.x, pShip->ship_coordinate.y);
}

void init(ship *pShip)
{
    pShip->ship_coordinate.x = 0;
    pShip->ship_coordinate.y = 0;
}

int main()
{
    ship myShip;
    init(&myShip);
    display_ship_coordinate(&myShip);
    go_north(&myShip);
    display_ship_coordinate(&myShip);
    go_east(&myShip);
    display_ship_coordinate(&myShip);
    go_south(&myShip);
    display_ship_coordinate(&myShip);
    go_west(&myShip);
    display_ship_coordinate(&myShip);
    return 0;
}