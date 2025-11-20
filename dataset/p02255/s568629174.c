#include <stdio.h>

void output(int A[], int N) {
	int i;
	for ( i = 0; i < N; i++ ) {
		if (i > 0) printf(" ");
		printf("%d", A[i]);
	}
	printf("\n");
}

int InsertionSort(int A[], int N) {
	int i, j;
	int esc;
	
	for ( i = 1; i < N; i++ ) {
		j = i - 1;
		esc = A[i];
		
		while ( j >= 0 && A[j] > esc ) {
			A[j + 1] = A[j];
			j--;
		}
		
		A[j + 1] = esc;
		output(A, N);
	}
	
}

int main(void) {
	int N;
	int A[100];
	int i;
	
	scanf("%d", &N);
	
	for ( i = 0; i < N; i++ ) {
		scanf("%d", &A[i]);
	}

	output(A, N);
	InsertionSort(A, N);

	return 0;
}