#include <stdio.h>

int main() {
	int m = 10;
	int n = 3;
	double ans = m / n;
	printf("Without casting: %.2f\n", ans);
	printf("Casting: %.2f\n", (double) m / (double) n);
	return 0;
}
