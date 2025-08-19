#include <stdio.h>

#define N 8

int sort(int a[], int b[], int n) {
	for (int i = 0; i < n; i++)
		 
}

int merge(int a[], int n) {
	int middle = n / 2;
	int lower[middle], upper[middle], temp[n];
	int i;
	
	if (n == 1) 
		return;

	for (i = 0; i < middle; i++) {
		lower[i] = a[i];
		upper[middle + i] = a[middle + i];
	}

	left = merge(lower, middle);
	right = merge(upper, middle);

	for (i = 0; i < n; i++)
	       if (left[i] <= right[i])
	           temp[
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
