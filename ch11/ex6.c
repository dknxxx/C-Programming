#include <stdio.h>

#define SIZE 5


void find_two_largest(int a[], int n, int *largest, int *second_largest);

int main(void) {
	int a[SIZE];
	int largest, second_largest;

	printf("Enter %d numbers: ", SIZE);
	for (int i = 0; i < SIZE; i++)
		 scanf("%d", &a[i]);

	find_two_largest(a, SIZE, &largest, &second_largest);

	printf("Largest: %d, Second Largest: %d\n", largest, second_largest);

	return 0;
}

void find_two_largest(int a[], int n, int *largest, int *second_largest) {
	if (a[0] > a[1]) {
		*largest = a[0];
		*second_largest = a[1];
	} else {
		*largest = a[1];
		*second_largest = a[0];
	}
		

	for (int i = 2; i < SIZE; i++) {
		 if (a[i] > *largest) {
		 	*second_largest = *largest;
		 	*largest = a[i];
		 } else if (a[i] > *second_largest) {
		 	*second_largest = a[i];
		 }
	}
}
