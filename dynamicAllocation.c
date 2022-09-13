#include <stdio.h>
#include <stdlib.h>

int main() {
	int* p = malloc(sizeof(int));
	*p = 42;
	printf("addr of p = %p | value of p = %d\n", p, *p);

	int* a;
	int b = 33;
	printf("size of int* %ld\n", sizeof(a));
	printf("size of *p %ld\n", sizeof(*p));
	printf("size of p %ld\n", sizeof(p));
	printf("size of b (integer): %ld\n", sizeof(b));

	return 0;
}

