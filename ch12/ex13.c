#include <stdio.h>

#define N 10

void ident(void) {
	double ident[N][N], *p;
	int consec = N;

	for (p = &ident[0][0]; p <= &ident[N - 1][N - 1]; p++)
		if (consec == N) {
			*p = 1.0;
			consec = 0;
		}
		else {
			*p = 0.0;
			consec++;
		}
}

int main(void) {
	ident();

	for (int i = 0; i < N; i++) {
		 printf("row %d: %f", i, ident[i]);
		 for (int j = 0; j < N; j++) {
			  printf(" column %d: %f", j, ident[i][j]);
		 }
		 printf("\n");
	}
	
	return 0;
}
