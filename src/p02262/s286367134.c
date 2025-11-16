#include <stdio.h>
#define N 1000000

int G[N], A[N], gsize;
int cnt;

void insertionSort(int A[N], int n, int g){
	
	int v,j;
	
	for( int i = g; i < n; i++ ){
		v = A[i];
		j = i-g;
		while( j >= 0 && A[j] > v ){
			A[j+g] = A[j];
			j = j-g;
			cnt++;
		}
		A[j+g] = v;
	}
}

void shellSort(int A[N], int n){
	
	int h;
	for(h = 1, gsize = 0;;gsize++){
		if( h > n ) break;
		G[gsize] = h;
		h = 3*h+1;
	}
	for(int j = gsize-1; j >= 0; j--){
		insertionSort(A,n,G[j]);
	}
	
	
}

int main(void){
	
	int n;
	cnt = 0;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &A[i]);
	}
	
	shellSort(A, n);
	
	printf("%d\n", gsize);
	for(int i = gsize-1; i >= 0; i--){
		printf("%d", G[i]);
		if( i == 0 ) printf("\n");
		else printf(" ");
	}
	printf("%d\n", cnt);
	for(int i = 0; i < n; i++){
		printf("%d\n", A[i]);
	}
	
}
