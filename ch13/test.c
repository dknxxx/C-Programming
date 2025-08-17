#include <stdio.h>
#include <string.h>

int main(void) {
	if ((strcmp("2", "10")) < 0)
		printf("true\n");
	else
		printf("false\n");

	return 0;
}
