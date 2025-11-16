#include <stdio.h>
int cnt = 0;
int m = 1;
int G[1000000] = {0};
void showA(int A[], int N) {
	int i;
	for (i = 0; i < N; ++i) {
		printf("%d ", A[i]);
	}
	printf("\n");
	return;
}


void inSertSort(int A[], int n, int g) {
	int i, j, v;
	
//	printf("g = %d\n", g);
	for (i = g ; i < n; ++i) {
		v = A[i];
		j = i - g;
		while (j >= 0 && A[j] > v) {
			A[j + g] = A[j];
			j = j - g;
			cnt++;
		}
		A[j + g] = v;
	}
	return;
}

void shellSort(int A[] , int n) {
	int i;
	//int G[1000000] = {0};
	//int m = 1;
	G[0] = 1;
	for (i = 0; (3 * G[i] + 1) < n  ; ++i) {
		G[i + 1] = 3 * G[i] + 1;
		++m;
	}
	//printf("m = %d\n", m);
	for (i = m - 1 ; i >= 0; --i) {
		inSertSort(A, n, G[i]);
	}
	
	return;
}


int main(void) {
	int n, i;
	int A[1000000] = {0};
	
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &A[i]);
	}
//	showA(A, n);
	shellSort(A, n);
//	showA(A, n);
	printf("%d\n", m);
	for (i = m -1 ; i >= 0; --i) {
		if (i != 0) {
			printf("%d ", G[i]);
		} else {
			printf("%d\n", G[i]);
		}
	}
	printf("%d\n", cnt);
	for (i = 0; i < n; ++i) {
		printf("%d\n", A[i]);
	}
			
	return 0;
}