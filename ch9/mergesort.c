#include <stdio.h>

#define N 10

/* prototypes */

void merge(int a[], int low, int mid, int high) {
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

void sort(int a[], int low, int high) {
	if (low < high) {
	int mid = low + (high - low) / 2;

	sort(a, low, mid);
	sort(a, mid + 1, high);
	merge(a, low, mid, high);
	}
}

void printing(int *arr) {
	for (int i = 0; i < N; i++)
		 printf("%d ", arr[i]);
	printf("\n");
	return;
}

int main(void) {
	int arr[N] = {8, 4, 3, 2, 7, 6, 9, 0, 5, 1};

	printf("List to be sorted: ");
	printing(arr);

	sort(arr, 0, N - 1);
	
	printf("In sorted order: ");
	printing(arr);

	return 0;

}
