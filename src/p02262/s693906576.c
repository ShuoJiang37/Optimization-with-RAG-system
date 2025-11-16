#include <stdio.h>

#define N 1000000

int insertionSort(int *A, int n, int g) {
	int i,j;
	int v;
	int cnt = 0;

	for (i = g; i < n; i++) {
		v = A[i];
		j = i - g;
		while (j >= 0 && A[j] > v) {
			A[j+g] = A[j];
			j = j - g;
			cnt++;
		}
		A[j+g] = v;
	}

	return cnt;
}

void shellSort(int *A, int n) {
	int i;
	int cnt = 0;
	int m;
	int G[n];

	G[0] = 1;
	for (m = 1; m < 100; m++) {
		G[m] = G[m-1] * 2;
		if (G[m] > n) break;
	}

	for (i = m-1; i >= 0; i--)
		cnt += insertionSort(A, n, G[i]);

	printf("%d\n", m);
	for (i = m-1; i >= 0; i--) {
		printf("%d", G[i]);
		if (i != 0) printf(" ");
	}
	printf("\n%d\n", cnt);
}

int main () {
	int i,n;
	int A[N];

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d", &A[i]);

	shellSort(A, n);

	for (i = 0; i < n; i++)
		printf("%d\n", A[i]);

	return 0;
}