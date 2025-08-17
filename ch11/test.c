#include <stdio.h>

int main(void) {
	int i = 0, p = &i;

	printf("i: %d, *p = %d, p = %ls\n", i, *p, p);

	return 0;
}
