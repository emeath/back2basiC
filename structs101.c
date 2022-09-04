#include <stdio.h>

struct record {
	char name[31 + 1]; // +1 -> '\0'
	char telephone[15 + 1]; // +1 -> '\0'
};

void printRecord(struct record* reg) {
	printf("name: %s\n", reg->name);
	printf("telephone: %s\n\n", reg->telephone);
}

int main(){

	struct record r0;
	struct record r1;
	struct record r2;

	sprintf(r0.name, "Matheus");
	sprintf(r0.telephone, "(12) 3456-7890");

	sprintf(r1.name, "Michael Scott");
	sprintf(r1.telephone, "(23) 4567-8901");
	
	sprintf(r2.name, "Dwight Schrute");
	sprintf(r2.telephone, "(34) 5678-9012");

	printRecord(&r0);	
	printRecord(&r1);	
	printRecord(&r2);	

	return 0;
}
