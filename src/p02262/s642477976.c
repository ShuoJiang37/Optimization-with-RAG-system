#include<stdio.h>
#define mMax 100

int insertionSort(int A[], int n, int g)
{
	int i, j;
	int cnt = 0;
	for(i = g; i < n; ++i) {
		int v = A[i];
		j = i - g;
		while(j >= 0 && A[j] > v) {
			A[j+g] = A[j];
			j = j - g;
			cnt++;
		}
		A[j+g] = v;
	}
	return cnt;
}

int main()
{
	int i, j, g, m, n;
	int cnt;
	scanf("%d\n", &n);

	int A[n];
	int G[mMax];
	for(i = 0; i < n; ++i)
		scanf("%d", &A[i]);

	cnt = 0;
	G[0] = g = 1;
	for(i = 1, m = 1; 3*g + 1 <= n; ++i) {
		g = 3*g + 1;
			for(j = i; j > 0; --j)
			G[j] = G[j-1];
		G[0] = g;
		m++;
	}

	for(i = 0; i < m; ++i)
		cnt += insertionSort(A, n, G[i]);

	printf("%d\n", m);
	for(i = 0; i < m; ++i) {
		if(i == m-1)
			printf("%d\n", G[i]);
		else
			printf("%d ", G[i]);
	}
	printf("%d\n", cnt);
	for(i = 0; i < n; ++i) {
		printf("%d\n", A[i]);
	}
    return 0;
}