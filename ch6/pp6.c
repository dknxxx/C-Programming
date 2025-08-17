/* Prints all even squares between 1 and n */

#include <stdio.h>

int main(void) {
	int n;

	printf("Prints all even squares between 1 and n\n");
	printf("Enter an integer: ");
	scanf("%d", &n);

	for (int i = 2; i * i <= n; i += 2)
		 printf("%d\n", i * i);

	return 0;
}
