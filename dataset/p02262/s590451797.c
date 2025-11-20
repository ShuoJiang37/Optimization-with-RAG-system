#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int insertionSort(int A[], int N,int g,int cnt);
void shellSort(int A[], int n);

int main(){
	int *A, n, i;
	scanf("%d", &n);
	A = (int *)malloc(sizeof(int)*n);
	for (i = 0; i < n; ++i)  scanf("%d", A + i);
	shellSort(A, n);
	free(A);
	return 0;
}

int insertionSort(int A[], int N,int g,int cnt){
	int i, j, v;
	for (i = g; i < N ; i++) {
		v = A[i];
		j = i - g;
		while (j >= 0 && A[j] > v) {
			A[j + g] = A[j];
			j = j - g;
			cnt++;
		}
		A[j + g] = v;
	}
	return cnt;
}

void shellSort(int A[], int n){
	int cnt = 0, m=0;
	int *G;
	int i;
	
	for (i = 1; (int)(pow(3, i) - 1) / 2.0<n; i++) m++;
	if (n == 1) m = 1;
	G = (int *)malloc(sizeof(int)*m);
	for (i = m-1; i >= 0; --i) G[m-i-1] = (int)((pow(3, i+1) - 1) / 2.0);
	
	for (i = 0; i < m; i++) {
		cnt=insertionSort(A, n, G[i],cnt);
	}
	printf("%d\n", m);
	for (i = 0; i < m; ++i) printf("%d%c", G[i], i < m - 1 ? ' ' : '\n');
	printf("%d\n", cnt);
	for (i = 0; i < n; i++) printf("%d\n", A[i]);
}