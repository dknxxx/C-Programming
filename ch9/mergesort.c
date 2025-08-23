#include <stdio.h>

#define N 10

void sort(int arr[], int low, int mid, int high) {
	int n1 = mid - low + 1;
	int n2 = high - mid;

	int left[n1], right[n2];

	for (int i = 0; i < n1; i++) {
		left[i] = arr[low + i];
	}

	for (int i = 0; i < n2; i++) {
		right[i] = arr[mid + i + 1];
	}

	int i = 0; int j = 0; int k = low;

	while (i < n1 || j < n2) {
		if (j >= n2 || left[i] <= right[j]) {
			arr[k++] = left[i++];
		} else {
			arr[k++] = right[j++];
		}
	}	
}

void merge(int arr[], int low, int high) {
	if (low < high) {
	int mid = low + (high - low) / 2;

	merge(arr, low, mid);
	merge(arr, mid + 1, high);
	sort(arr, low, mid, high);
	}
}

void printing(int arr[]) {
	for (int i = 0; i < N; i++) {
		 printf("%d ", arr[i]);
	}
	printf("\n");
	
	return;
}

int main(void) {
	int arr[N] = {8, 2, 4, 1, 0, 9, 5, 7, 3, 6};

	printf("Enter %d numbers to be sorted: ", N);
	printing(arr);

	merge(arr, 0, N - 1);
	
	printf("In sorted order: ");
	printing(arr);

	return 0;

}
