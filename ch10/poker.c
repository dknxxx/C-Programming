/* Classifies a poker hand */

#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

/* external variables */
int hand[NUM_CARDS][2];
bool straight, flush, four, three;
int pairs; /* can be 0, 1, 2 */

/* prototypes */
void read_cards(void);
void analyze_hand(void);
void print_results(void);

/* main: Calls read_cards, analyze_hands, and print_results
 *        repeatedly */

int main(void) {
     read_cards();
     analyze_hand();
     print_results();
}

/* read_cards: Reads the cards into the external
 *             variables num_in_rank and num_in_suit;
 *             checks for bad cards and duplicate cards */

void read_cards(void) {
	char ch, rank_ch, suit_ch;
	int rank = 0; int suit = 0; int card;
	bool bad_card, dupe_card;
	int cards_read = 0;

	while (cards_read < NUM_CARDS) {
		bad_card = false;
		dupe_card = false;

		printf("Enter a card: ");

		rank_ch = getchar();
		switch(rank_ch) {
			case '0': exit(EXIT_SUCCESS);
			case '1': rank = 0; break;
			case '2': rank = 1; break;
			case '3': rank = 2; break;
			case '4': rank = 3; break;
			case '5': rank = 4; break;
			case '6': rank = 5; break;
			case '7': rank = 6; break;
			case '8': rank = 7; break;
			case '9': rank = 8; break;
			case 't': case 'T': rank = 9; break;
			case 'j': case 'J': rank = 10; break;
			case 'q': case 'Q': rank = 11; break;
			case 'k': case 'K': rank = 12; break;
			case 'a': case 'A': rank = 13; break;
			default : bad_card = true;
		}

		suit_ch = getchar();
		switch(suit_ch) {
			case 'c': case 'C': suit = 0; break;
			case 'd': case 'D': suit = 1; break;
			case 'h': case 'H': suit = 2; break;
			case 's': case 'S': suit = 3; break;
			default : bad_card = true;
		}

		while ((ch = getchar()) != '\n')
			if (ch != ' ') bad_card = true;

		if (bad_card)
			printf("Bad card; ignored.\n");

		for (card = 0; card < NUM_CARDS; card++) {
			if (hand[card][0] == rank && hand[card][1] == suit) {
				printf("Duplicate card; ignored.\n");
				dupe_card = true;
				break;
			}
		}

		if (!dupe_card) {
			hand[cards_read][0] = rank;
			hand[cards_read][1] = suit;
			cards_read++;
		}
	}
}

/* analyze_hand: Determines whether the hand contains a
 *               straight, a flush, four-of-a-kind,
 *               and/or three-of-a-kind; determines the
 *               number of pairs; stores the results into
 *               the external variables straight, flush,
 *               four, three, and pairs. */

void analyze_hand(void) {
	int num_consec;
	int suit;
	int card;
	straight = true;
	flush = true;
	four = false;
	three = false;
	pairs = 0;

	/* Sorts hand into numerical order */
	int temp[1][1];
	for (card = 0; card < NUM_CARDS - 1; card++) {
		for (int j = 0; j < NUM_CARDS - card - 1; j++) {
			if (hand[j][0] > hand[j+1][0]) {
				temp[0][0] = hand[j][0];
				temp[0][1] = hand[j][1];

				hand[j][0] = hand[j+1][0];
				hand[j][1] = hand[j+1][1];

				hand[j+1][0] = temp[0][0];
				hand[j+1][1] = temp[0][1];
			}
		}
	}

	/* check for flush */
	suit = hand[0][1];
	for (int card = 0; card < NUM_CARDS; card++) {
		if (hand[card][1] != suit) {
			flush = false;
			break;
		}
	}

	/* check for straight */
	for (card = 0; card < NUM_CARDS; card++) {
		if ((hand[card][0] + 1) != hand[card+1][0]) {
			straight = false;
			break;
		}
	}

	/* check for 4-of-a-kind, 3-of-a-kind, and pairs */
	for (card = 0; card < NUM_CARDS; card++) {
		num_consec = 1;
		for (int j = card + 1; j < NUM_CARDS - card; j++) {
			if (hand[card][0] == hand[j][0])
				num_consec++;
		switch (num_consec) {
			case 2: pairs++; break;
			case 3: three = true; break;
			case 4: four = true; break;
		}
		}
	}
}

/* print_result: Prints the classification of the hand,
 *               based on the values of the external
 *               variables straight, flush, four, three,
 *               and pairs. */

void print_results(void) {
	if (straight && flush) printf("Straight flush");
	else if (four) printf("Four of a kind");
	else if (three && pairs == 1) printf("Full house");
	else if (flush) printf("Flush");
	else if (straight) printf("Straight");
	else if (three) printf("Three of a kind");
	else if (pairs == 2) printf("Two pair");
	else if (pairs == 1) printf("Pair");
	else printf("High card");

	printf("\n\n");
}
