/* Calculates GCD of two numbers */

#include <stdio.h>

int main(void) {
	int m, n, r;

	printf("Calculates Greatest Common Divisor (GCD) of two numbers\n");
	printf("Enter two integers: ");
	scanf("%d %d", &m, &n);

	while (n != 0) {
		r = m % n;
		m = n;
		n = r;
	}

	printf("Greatest common divisor: %d\n", m);

	return 0;
}
