/* Classifies a poker hand */

#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5
#define RANK 0
#define SUIT 1

/* external variables */
int hand[NUM_CARDS][2];
bool straight, flush, four, three;
int pairs; /* can be 0, 1, 2 */

/* prototypes */
void read_cards(void);
void analyze_hand(void);
void print_results(void);
void sort_hands(void);

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

		if (bad_card) {
			printf("Bad card; ignored.\n");
			continue;
		}

		for (card = 0; card < NUM_CARDS; card++) {
			if (hand[card][RANK] == rank && hand[card][SUIT] == suit) {
				printf("Duplicate card; ignored.\n");
				dupe_card = true;
				break;
			}
		}

		if (!dupe_card) {
			hand[cards_read][RANK] = rank;
			hand[cards_read][SUIT] = suit;
			cards_read++;
		}
	}
	sort_hands();
}

/* analyze_hand: Determines whether the hand contains a
 *               straight, a flush, four-of-a-kind,
 *               and/or three-of-a-kind; determines the
 *               number of pairs; stores the results into
 *               the external variables straight, flush,
 *               four, three, and pairs. */


/* Sorts hand rank into numerical order */
void sort_hands(void) {
	int temp[1][2];
	int card, pass;

	for (card = 0; card < NUM_CARDS - 1; card++) {
		for (pass = 0; pass < NUM_CARDS - card - 1; pass++) {
			if (hand[pass][RANK] > hand[pass+1][RANK]) {
				temp[0][0] = hand[pass][RANK];
				temp[0][1] = hand[pass][SUIT];

				hand[pass][RANK] = hand[pass+1][RANK];
				hand[pass][SUIT] = hand[pass+1][SUIT];

				hand[pass+1][RANK] = temp[0][0];
				hand[pass+1][SUIT] = temp[0][1];
			}
		}
	}
}

void analyze_hand(void) {
	int num_consec;
	int suit;
	int card, pass;
	straight = true;
	flush = true;
	four = false;
	three = false;
	pairs = 0;

	/* check for flush */
	suit = hand[RANK][SUIT];
	for (card = 0; card < NUM_CARDS; card++) {
		if (hand[card][SUIT] != suit) {
			flush = false;
			break;
		}
	}

	/* setup to check for ace low straight */
	if (hand[3][RANK] == 4 && hand[4][RANK] == 13) {
		hand[4][RANK] = 0;
		sort_hands();
	}

	/* check for straight */
	for (card = 0; card < NUM_CARDS - 1; card++) {
		if ((hand[card][RANK] + 1) != hand[card+1][RANK]) {
			straight = false;
			break;
		}
	}

	/* check for 4-of-a-kind, 3-of-a-kind, and pairs */
	for (card = 0; card < NUM_CARDS; card++) {
		num_consec = 1;
		for (pass = card + 1; pass < NUM_CARDS; pass++) {
			if (hand[card][RANK] == hand[pass][RANK]) {
				num_consec++;
				card = pass;
			}
		}

		switch (num_consec) {
			case 2: pairs++; break;
			case 3: three = true; break;
			case 4: four = true; break;
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
