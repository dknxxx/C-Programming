#include <stdio.h>

#define limit 100

int main(void) {
	char message[limit];
	char *p;

	printf("Enter a message: ");
	for (p = message; p < message + limit; p++) {
	       *p = getchar();
	       if (*p == '\n')
	       		break;
	}

	printf("In reverse...\n");
	for (p--; p >= message; p--)
	       putchar(*p);
	putchar('\n');
	
	return 0;
}
