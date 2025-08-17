#include <stdio.h>

void swap(int *p, int *q) {
	int temp;

	temp = *q;
	*q = *p;
	*p = temp;
}

int main(void) {
	int i = 0; int j = 1;

	printf("i: %d, j: %d\n", i, j);

	swap(&i, &j);

	printf("swapped i: %d, swapped j: %d\n", i, j);

	return 0;
}
