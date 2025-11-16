#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define SENTINEL (1000000001)

int c = 0;
int S[500000];
int L[250001];
int R[250001];

static void Merge(int A[], int left, int mid, int right);
static void MergeSort(int A[], int left, int right);

int main(void) {
	int i;
	int n;
	
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &S[i]);
	}
	
	MergeSort(S, 0, n);
	
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

void Merge(int A[], int left, int mid, int right) {
	int i, j, k;
	int n1 = mid - left;
	int n2 = right - mid;
	memcpy(L, A + left, n1 * sizeof(int));
	memcpy(R, A + mid, n2 * sizeof(int));
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
}

void MergeSort(int A[], int left, int right) {
	int mid;
	if (left + 1 < right) {
		mid = (left + right) / 2;
		MergeSort(A, left, mid);
		MergeSort(A, mid, right);
		Merge(A, left, mid, right);
	}
}