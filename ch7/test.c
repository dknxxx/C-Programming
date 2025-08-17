#include <stdio.h>

int main(void) {
	char a;
	printf("Enter letter: ");
	a = getchar();
	if (a == ('A' || 'B')) {
		printf("True");
	} else {
		printf("False");
	}

	return 0;
}
