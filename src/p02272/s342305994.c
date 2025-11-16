#include <stdio.h>
#include <stdlib.h>

#define SENTINEL (1000000001)

static int Merge(int A[], int left, int mid, int right);
static int MergeSort(int A[], int left, int right);

int main(void) {
	int i;
	int c;
	int n;
	int S[500000];
	
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &S[i]);
	}
	
	c = MergeSort(S, 0, n);
	
	for (i = 0; i < n; ++i) {
		if (i > 0) {
			putchar(' ');
		}
		printf("%d", S[i]);
	}
	putchar('\n');
	
	printf("%d\n", c);

	return 0;
}

int Merge(int A[], int left, int mid, int right) {
	int c = 0;
	int i, j, k;
	int n1 = mid - left;
	int n2 = right - mid;
	int *L = (int *)calloc(n1 + 1, sizeof(int));
	int *R = (int *)calloc(n2 + 1, sizeof(int));
	for (i = 0; i < n1; ++i) {
		L[i] = A[left + i];
	}
	for (i = 0; i < n2; ++i) {
		R[i] = A[mid + i];
	}
	L[n1] = R[n2] = SENTINEL;
	i = j = 0;
	for (k = left; k < right; ++k) {
		++c;
		if (L[i] <= R[j]) {
			A[k] = L[i];
			++i;
		} else {
			A[k] = R[j];
			++j;
		}
	}
	free(L);
	free(R);
	return c;
}

int MergeSort(int A[], int left, int right) {
	int c = 0;
	int mid;
	if (left + 1 < right) {
		mid = (left + right) / 2;
		c += MergeSort(A, left, mid);
		c += MergeSort(A, mid, right);
		c += Merge(A, left, mid, right);
	}
	return c;
}