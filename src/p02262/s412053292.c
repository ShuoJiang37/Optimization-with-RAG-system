/* ALDS1_3_D: Shell Sort */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define N 1000000
#define M 100

int G[M] = {0}, m, cnt = 0;
void insertionSort(int *A, int n, int g);
void shellSort(int *A, int n);

int main(void){
	int n, i = 0;

    int *A = (int *) malloc(sizeof(int) * N);
	scanf("%d", &n);
	while(i < n){
		scanf("%d", &A[i++]);
	}

	shellSort(A, n);

	printf("%d\n", m);
	for(i = m-1; i >= 0; i-- ){
		printf("%d", G[i]);
		if(i) printf(" ");
	}

	printf("\n%d\n", cnt);

	for(i = 0; i < n; i++ ){
		printf("%d\n", A[i]);
	}
	return 0;
}

void shellSort(int *A, int n){
	int i = 0;

	G[0] = 1;
	while(G[i] <= n){
		i++;
		G[i] = 3*G[i-1] + 1;
	}

	G[i] = 0;
	m = i;
	i = 0;

	for(i = m - 1; i >= 0; i--){
		insertionSort(A, n, G[i]);
	}
}

void insertionSort(int* A, int n, int g){
	int v, i = 0, j;
	
	i = g;
	while(i < n){
		v = A[i];
		j = i - g;
		while(j >= 0 && A[j] > v){
			A[j + g] = A[j];
			j -= g;
			cnt++;
		}
		A[j + g] = v;
		i++;
	}
}
