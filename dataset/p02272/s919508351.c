#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define SENTINEL (1000000001)

int c = 0;
int S[500000];
int L[250001];
int R[250001];
char str[5500000];
char *p = str;

static void Merge(int A[], int left, int mid, int right);
static void MergeSort(int A[], int left, int right);
static int getNum(void);
static void putNum(int n);

int main(void) {
	register int i;
	int n;
	
	fread(str, sizeof(char), 5500000, stdin);
	n = getNum();
	for (i = 0; i < n; ++i) {
		S[i] = getNum();
	}
	
	MergeSort(S, 0, n);
	
	--n;
	p = str;
	for (i = 0; i < n; ++i) {
		putNum(S[i]);
		*p = ' ';
		++p;
	}
	putNum(S[i]);
	*p = '\n';
	++p;
	
	putNum(c);
	*p = '\0';
	
	puts(str);

	return 0;
}

int getNum(void) {
	int n = 0;
	while ((*p >= '0') && (*p <= '9')) {
		n = n * 10 + (int)(*p - '0');
		++p;
	} 
	++p;
	return n;
}

void putNum(int n) {
	int d = n / 10;
	if (n < 10) {
		*p = '0' + (char)n;
		++p;
		return;
	}
	if (d) putNum(d);
	*p = '0' + (char)(n % 10);
	++p;
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