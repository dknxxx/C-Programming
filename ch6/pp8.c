/* Prints a one-month calendar */

#include <stdio.h>

int main(void) {
	int days, start;
	
	printf("Prints a one-month calendar.\n");
	printf("Enter number of days in month: ");
	scanf("%d", &days);
	printf("Enter starting day of the week (1=Sun, 7=Sat): ");
	scanf("%d", &start);
	printf("\n");

	/* Creates blank spaces before the 1st date */
	for (int i = 1; i < start; i++)
	     printf("   ");

	/* Prints the calendar days */
	for (int i = 1; i <= days; i++) {
		 printf("%2d ", i);
		 if (((start + i - 1) % 7) == 0) {
		 	printf("\n");
		 }
	}
	
	printf("\n\n");
	return 0;
}
