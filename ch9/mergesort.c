#include <stdio.h>

#define N 4

void sort(int a[], int low, int mid, int high) {
	int n1 = mid - low + 1;
	int n2 = high - mid;

	int left[n1], right[n2];

	for (int i = 0; i < n1; i++) {
		left[i] = a[low + i];
	}

	for (int i = 0; i < n2; i++) {
		right[i] = a[mid + i + 1];
	}

	int i = 0; int j = 0; int k = low;

	while (i < n1 && j < n2) {
		if (left[i] <= right[j]) {
			a[k] = left[i];
			i++;
		} else {
			a[k] = right[j];
			j++;
		}
		k++;
	}	
	while (i < n1) {
		a[k] = left[i];
		i++;
		k++;
	}

	while (j < n2) {
		a[k] = right[j];
		j++;
		k++;
	}
}

void merge(int a[], int low, int high) {
	if (low < high) {
	int mid = low + (high - low) / 2;

	merge(a, low, mid);
	merge(a, mid + 1, high);
	sort(a, low, mid, high);
	}
}

int main(void) {
	int i = 0, a[N];

	printf("Enter %d numbers to be sorted: ", N);
	while (i < N) 
		scanf("%d", &a[i++]);

	merge(a, 0, N - 1);
	
	printf("In sorted order: ");
	i = 0;
	while (i < N) {
		printf("%d ", a[i]);
		i++;
	}
	printf("\n");

	return 0;

}
