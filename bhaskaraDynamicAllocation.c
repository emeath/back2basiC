#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void finalBhaskara(double* a, double* b, double* delta, double* ans, char* op) {
	if((*op) == '-')
		*ans = ( -(*b) - sqrt((*delta)) ) / ( 2 * (*a) );
	else if ((*op) == '+')
		*ans = ( -(*b) + sqrt((*delta)) ) / ( 2 * (*a) );
	else {
		printf("Expected 1 or 2 Received %d at address %p\n", *op, op);
		exit(1);
	}
}

void computeBhaskara(double* a, double* b, double* c, double* ans1, double* ans2) {
	
	double* delta = malloc(sizeof(double));

	char* op = malloc(sizeof(char));
	
	*delta = (*b) * (*b) - 4 * (*a) * (*c);
	*op = '-';
	finalBhaskara(a, b, delta, ans1, op);
	*op = '+';
	finalBhaskara(a, b, delta, ans2, op);
	
	free(delta);
	free(op);
}

void initValue(double* pointer, double value) {
	*pointer = value;
}

int main() {

	double* a;
	double* b;
	double* c;

	printf("size of a, b, c: %ld %ld %ld\n", sizeof(a), sizeof(b), sizeof(c));

	a = malloc(sizeof(double));
	b = malloc(sizeof(double));
	c = malloc(sizeof(double));

	double* answer1;
	double* answer2;

	answer1 = malloc(sizeof(double));
	answer2 = malloc(sizeof(double));

	initValue(a, 1);
	initValue(b, 10);
	initValue(c, 2);

	//*a = 1;
	//*b = 10;
	//*c = 2;

	computeBhaskara(a, b, c, answer1, answer2);

	printf("results %f\t%f\n", *answer1, *answer2);

	free(a);
	free(b);
	free(c);
	free(answer1);
	free(answer2);

	return 0;
}
