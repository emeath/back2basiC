#include <stdio.h>

int main() {
	int x, y;
	printf("Digite dois numeros. Eles serao multiplicados.\n");
	printf("Digite numero x: ");
	scanf("%d", &x);
	printf("Digite numero y: ");
	scanf("%d", &y);

	printf(" %d x %d = %d\n", x, y, x*y);
	
	return 0;
}
