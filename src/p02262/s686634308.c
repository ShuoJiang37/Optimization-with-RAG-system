#include <stdio.h>

void insertionSort(int *, int, int);

int cnt;

int main(void)
{
	int i, n, m, h, A[1000000], G[100];
	
	scanf("%d",&n);
	for (i=0; i<n; i++) {
		scanf("%d",&A[i]);
	}
	
	cnt = 0;
	h = 1;
	for (m=1; h<=n/9; m++) {
		h = 3*h + 1;
	}
	for (i=0; i<m; i++) {
		G[i] = h;
		h /= 3;
	}
	for (i=0; i<m; i++) {
		insertionSort(A, n, G[i]);
	}
	
	printf("%d\n",m);
	for (i=0; i<m-1; i++) {
		printf("%d ",G[i]);
	}
	printf("%d\n",G[m-1]);
	printf("%d\n",cnt);
	for (i=0; i<n; i++) {
		printf("%d\n",A[i]);
	}
	
	return 0;
}

void insertionSort(int *A, int n, int g)
{
	int i, j, v;
	
	for (i=g; i<n; i++) {
		v = A[i];
		j = i - g;
		while ( j >= 0 && A[j] > v ) {
			A[j+g] = A[j];
			j = j - g;
			cnt++;
		}
		A[j+g] = v;
	}
}