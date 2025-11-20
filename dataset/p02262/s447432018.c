
#include <stdio.h>
#include <string.h>

#define DEF_ELEM_MAX 1000000

typedef long long llong;

int S[DEF_ELEM_MAX];
int T[DEF_ELEM_MAX/3+1];
int G[DEF_ELEM_MAX/3+1];
int N;
int cnt;

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
void insertionSort(int *A, int n, int g)
{
	int i;
	int j;
	int v;

	for (i = g ; i < n ; i++ ) {
		v = A[i];
		j = i - g;
		while (j >= 0 && A[j] > v) {
			A[j+g] = A[j];
			j = j - g;
			cnt++;
		}
		A[j+g] = v;
	}
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
int shellSort(int *A, int n)
{
	int i;
	int m;
	int h;

	for ( m = 0, h = 1; ; ) {
		if ( h > n ) break;
		T[m++] = h;
		h = 3*h + 1;
	}
//	?????????????????????
	for ( i = 0 ; i < m ; i++) {
		G[i] = T[m-1-i];
	}

	for ( i = 0 ; i < m ; i++ ) {
		insertionSort(A, n, G[i]);
	}
	return m;
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
int main(void)
{
	int i;
	int m;
//
	scanf("%d", &N);
	for ( i = 0 ; i < N ; i++ ) {
		scanf("%d", &S[i] );
	}

	m = shellSort(S, N);

	printf("%d\n", m);
	for ( i = 0 ; i < m ; i++ ) {
		printf("%d", G[i]);
		if ( i < m-1) {
			printf(" ");
		} else {
			printf("\n");
		}
	}
	printf("%d\n", cnt);

	for ( i = 0 ; i < N ; i++ ) {
		printf("%d\n", S[i]);
	}

	return 0;
}