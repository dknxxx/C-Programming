/* Classifies a poker hand */

#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>

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

/* main: Calls read_cards, analyze_hands, and print_results
 *        repeatedly */

int main(void) {
	for (;;) {
	     read_cards();
	     analyze_hand();
	     print_results();
	}
}

/* read_cards: Reads the cards into the external
 *             variables num_in_rank and num_in_suit;
 *             checks for bad cards and duplicate cards */

void read_cards(void) {
	char ch, rank_ch, suit_ch;
	int rank, suit;
	bool bad_card, duplicate_card;
	int cards_read = 0;

	while (cards_read < NUM_CARDS) {
		bad_card = false;

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

		dupicate_card = false;
		for (i = 0; i < cards_read; i++)
			if (hand[RANK][i] == rank && hand[SUIT][i] == suit) {
				duplicate_card = true;
				break;
			}
		       
		if (!duplicate_card) {
			hand[cards_read][RANK] = rank;
			hand[cards_read][SUIT] = suit;
			cards_read++;
		}
	}
}

/* analyze_hand: Determines whether the hand contains a
 *               straight, a flush, four-of-a-kind,
 *               and/or three-of-a-kind; determines the
 *               number of pairs; stores the resutls into
 *               the external variables straighht, flush,
 *               four, three, and pairs. */

void analyze_hand(void) {
	int num_consec = 0;
	int rank, suit;
	straight = false;
	flush = false;
	four = false;
	three = false;
	pairs = 0;

	/* check for flush */
	suit = hand[SUIT][0];
	for (suit = 0; suit < NUM_CARDS; suit++) {
		  if (hand[SUIT][suit] == suit)
		  	num_consec++;
	if (num_consec == NUM_CARDS)
		flush = true;
	}

	/* check for straight */
	rank = 0;
	while (num_in_rank[rank] == 0) rank++;
	for (; rank < NUM_RANKS && num_in_rank[rank] > 0; rank++)
	     num_consec++;
	if (num_consec == NUM_CARDS) {
		straight = true;
		return;
	}
	/* check for 4-of-a-kind, 3-of-a-kind, and paris */
	for (rank = 0; rank < NUM_RANKS; rank++) {
		  if (num_in_rank[rank] == 4) four = true;
		  if (num_in_rank[rank] == 3) three = true;
		  if (num_in_rank[rank] == 2) pairs++;
	}
}

/* print_result: Prints the calssification of the hand,
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
