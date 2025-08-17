#include <stdio.h>
#include <ctype.h>

int main(void) {
	int points = 0;
	char ch;

	printf("Enter a word: \n");

	while ((ch = getchar()) != '\n') {
		ch = toupper(ch);
		if (ch == 'A' || 'E' || 'I' || 'L' || 'N' || 'O' || 'R' || 'S' || 'T' || 'U') {
			points += 2;
			printf("Letter: %c\n", ch);
			printf("Points: %d\n", points);
		} else if (ch == 'D' || 'G') {
			points += 2;
			printf("Letter: %c\n", ch);
			printf("Points: %d\n", points);
		} else if (ch == 'B' || 'C' || 'M' || 'P') {
			points += 3;
			printf("Letter: %c\n", ch);
			printf("Points: %d\n", points);
		} else if (ch == 'F' || 'H' || 'V' || 'W' || 'Y') {
			points += 4;
			printf("Letter: %c\n", ch);
			printf("Points: %d\n", points);
		} else if (ch == 'K') {
			points += 5;
			printf("Letter: %c\n", ch);
			printf("Points: %d\n", points);
		} else if (ch == 'J' || 'X') {
			points += 8;
			printf("Letter: %c\n", ch);
			printf("Points: %d\n", points);
		} else if (ch == 'Q' || 'Z') {
			points += 10;
			printf("Letter: %c\n", ch);
			printf("Points: %d\n", points);
		} else {
			printf("Not a valid letter");
			return 0;
		}
	}

	printf("Scrabble value: %d\n", points);

	return 0;
}
