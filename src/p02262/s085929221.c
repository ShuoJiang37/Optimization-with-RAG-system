
#include <stdio.h>
#include <math.h>

int cnt;

void shellSort(int *A, int n);
void insertionSort(int *A, int n, int g);

int main(void)
{
	int n;
	int i;

	cnt = 0;
	scanf("%d", &n);

	int A[n];
	for(i = 0; i < n; i++){
		scanf("%d", &A[i]);
	}

	shellSort(A, n);
	
	printf("%d\n", cnt);	
	for(i = 0; i < n; i++){
		printf("%d\n", A[i]);	
	}
	
}

void shellSort(int *A, int n)
{
	int i, m;

	int G_rev[100], G_rev_cnt = 0;	

	G_rev[0] = 1;
	i = 1;
	while(1){
		G_rev[i] = G_rev[i - 1] + pow(3, i);
		if(G_rev[i] > n) break;
		//printf("G_rev[%d] = %d\n", i, G_rev[i]);
		i++;
	}
	m = i;
	printf("%d\n", m);

	int G[m];
	for(i = 0; i < m - 1; i++){
		G[i] = G_rev[m - i - 1];
		printf("%d ", G[i]);
		//printf("G[%d] = %d\n", i, G[i]);
	}
	G[i] = G_rev[m - i - 1];
	printf("%d\n", G[i]);

	for(i = 0; i <= m - 1; i++){
		insertionSort(A, n, G[i]);
	}
}

void insertionSort(int *A, int n, int g)
{
	int i, j, v;
	for(i = g; i <= n - 1; i++){
		v = A[i];
		j = i - g;
		while((j >= 0) && (A[j] > v)){
			A[j + g] = A[j];
			j = j - g;
			cnt++;
		}
		A[j + g] = v;
	}
}


