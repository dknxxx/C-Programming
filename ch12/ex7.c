bool search(const int a[], int n, int key)
	int *p;

	for (p = a; p <= a + n; p++)
		if (*p == key)
	       		return true;
		else
			return false;

int main(void) {
	int temperature[7][24], *p;
	
	search(temperature, 7 * 24, 32);

	for (p = temperature; p < tempurature[7]; p++)
	       printf("temperature: %d", (*p)tempurature + 24;
	printf("\n");


	return 0;
}


