#include <stdio.h>

#define N 2

void sort(int a[], int low, int high) {
	int i, j, temp;
	
	for (i = low; i < high; i++) {
		for (j = low + i; j < high; j++) {
			if (a[i] > a[j]) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;

			}
		}
	}
}

void merge(int a[], int low, int high) {
	int middle = (low + high) / 2;
	
	if (middle <= 1) return;

	merge(a, low, middle - 1);
	merge(a, middle, high);
	sort(a, low, high);
}

int main(void) {
	int i = 0, a[N];

	printf("Enter %d numbers to be sorted: ", N);
	while (i < N) 
		scanf("%d", &a[i++]);

	merge(a, 0, N);
	
	printf("In sorted order: ");
	i = 0;
	while (i < N) 
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}
