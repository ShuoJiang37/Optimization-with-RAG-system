#include <stdio.h>

void output(int A[], int N) {
	int i;
	
	for (i = 0; i < N; i++) {
		if (i > 0) printf(" ");
		printf("%d", A[i]);
	}
	printf("\n");
}

void insertionSort(int A[], int N) {
	int i, j;
	int tmp;
	
	for (i = 1; i < N; i++) {
		tmp = A[i];
		j = i - 1;
		
		while (j >= 0 && A[j] >= tmp) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = tmp;
		output(A, N);
	}
}

int main(void) {
	int N;
	int A[100];
	int i;
	
	scanf("%d", &N);
	
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
		
	output(A, N);
	insertionSort(A, N);

	return 0;
}