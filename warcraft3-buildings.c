#include <stdio.h>

struct building
{
    char name[101];
    int gold;
    int lumber;
    int buildingTime;
    struct building *next;
};

void label(struct building b)
{
    printf("=====================================================\n\n");
    printf("Building info:\n");
    printf("--------------\n\n");
    printf("Name: %s\n", b.name);
    printf("Cost => gold: %d | lumber: %d\n", b.gold, b.lumber);
    printf("Time to build: %d seconds.\n", b.buildingTime);
    printf("=====================================================\n\n");
}

void printSequence(struct building *b)
{
    if (b->next == NULL)
    {
        return;
    }
    printf(">>After building %s the next build will be: %s\n", b->name, b->next->name);
    printSequence(b->next);
}

int main()
{

    struct building altar = {"Altar", 200, 50, 30, NULL};
    struct building barracs = {"Barracs", 150, 20, 40, NULL};
    struct building arcaneVault = {"Arcane Vault", 150, 30, 20, NULL};

    struct building buildings[3];
    buildings[0] = altar;
    buildings[1] = barracs;
    buildings[2] = arcaneVault;

    altar.next = &barracs;
    barracs.next = &arcaneVault;

    for (size_t i = 0; i < 3; i++)
    {
        label(buildings[i]);
    }

    printSequence(&altar);
}
