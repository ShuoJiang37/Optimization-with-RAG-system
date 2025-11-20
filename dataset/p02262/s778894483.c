#include <stdio.h>
#include <stdlib.h>

void insertionSort(int A[], int n, int g, int *cnt)
{
	int i, j, v;
	for (i = g; i < n; i++)
	{
		v = A[i];
		j = i - g;
		while (j >= 0 && A[j] > v)
		{
			A[j + g] = A[j];
			j = j - g;
			(*cnt)++;
		}
		A[j + g] = v;		
	}
	
}

int main()
{
	int i, n, m, cnt;
	int *A;
	int G[100];

	scanf("%d", &n);
	A = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++) scanf("%d", &A[i]);

	i = n;
	m = 0;
	while ((i = i / 2) > 1)	G[m++] = i;
	G[m++] = 1;

	cnt = 0;
	for (i = 0; i < m; i++) insertionSort(A, n, G[i], &cnt);
	
	printf("%d\n", m);
	for (i = 0; i < m; i++)
	{
		printf("%d", G[i]);
		if (i < m - 1) printf(" ");
	}
	printf("\n");

	printf("%d\n", cnt);

	for (i = 0; i < n; i++)
	{
		printf("%d\n", A[i]);
	}

	free(A);

	return 0;
}