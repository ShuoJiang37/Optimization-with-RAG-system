#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<stdio.h>
#include<stdlib.h>
void CountingSort(int A[], int B[], int k,int n);
int main(){
	int *A, *B, k,n,i;
	scanf("%d", &n);
	A = (int *)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++) {
		scanf("%d", A + i);
		if (i == 0) k = *(A + i);
		if (*(A + i) > k) k = *(A + i);
	}
	B = (int *)malloc(sizeof(int)*(k+n));
	CountingSort(A, B, k,n);
	for (i = 1; i < n+1; i++) printf("%d%c", *(B + i), i < n ? ' ' : '\n');
	free(A);
	free(B);
	return 0;
}

void CountingSort(int A[], int B[], int k,int n){
	int i,*C;
	C = (int *)malloc(sizeof(int)*(k+n));
	for (i = 0; i <= k; i++) C[i] = 0;
	for (i = 0; i < n; i++) C[A[i]]++;
	for (i = 1; i <= k; i++)C[i] += C[i - 1];

	
	for (i = n-1; i >= 0; --i) {
		B[C[A[i]]] = A[i];
		C[A[i]]--;
	}
	
	free(C);
}