#include <stdio.h>
#include <string.h>

#define WORD_LEN 20

void read_line(char word[], int n) {
	int ch, i = 0;

	while ((ch = getchar()) != '\n')
		if (i < n)
			word[i++] = ch;
	word[i] = '\0';
}

int main(void) {
	char smallest_word[WORD_LEN+1];
	char largest_word[WORD_LEN+1];
	char word[WORD_LEN+1];

	printf("Enter word: ");
	read_line(word, WORD_LEN);
	strcpy(largest_word, strcpy(smallest_word, word));

	while (strlen(word) != 4) {
		printf("Enter word: ");
		read_line(word, WORD_LEN);
		if (strcmp(word, smallest_word) < 0)
			strcpy(smallest_word, word);
		if (strcmp(word, largest_word) > 0)
			strcpy(largest_word, word);
	}
	printf("Smallest word: %s\n", smallest_word);
	printf("Largest Word: %s\n", largest_word);

	return 0;
}
