#include <stdio.h>

#define N 8

void sort(int a[], int lower[], int upper[], int middle) {
	int i = 0; int j = 0;
	
	while (i < middle && j < middle) {
		if (lower[i] < upper[j]) {
			a[i + j] = lower[i];
			i++;
		}
		else {
			a[i + j] = upper[j];
			j++;
		}
	}
}

void merge(int a[], int n) {
	int middle = n / 2;
	int lower[middle], upper[middle];
	int i = 0;
	
	if (n == 1) {
		return;
	}

	for (i = 0; i < middle; i++) {
		lower[i] = a[i];
		upper[middle + i] = a[middle + i];
	}
	merge(lower, middle);
	merge(upper, middle);
	sort(a, lower, upper, middle);
}

int main(void) {
	int i = 0, a[N];

	printf("Enter 10 numbers to be sorted: ");
	while (i < N) 
		scanf("%d", &a[i++]);

	merge(a, N);
	
	printf("In sorted order: ");
	i = 0;
	while (i < N) 
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}
