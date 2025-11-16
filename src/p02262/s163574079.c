#include <stdio.h>

int insertionSort(int A[], int n, int g, int c){
	int i;
	for(i = g; i < n; i++){
		int v = A[i];
		int j = i - g;
		while(j >= 0 && A[j] > v){
			A[j + g] = A[j];
			j = j - g;
			c++;
		}
		A[j + g] = v;
	}
	return c;
}

void shellSort(int A[], int n){
	int i,j,m,c = 0;
	int G[n]; 
	G[0] = 1;
	m = 1;
	for(i = 1; i < n; i++){
		G[i] = G[i - 1] * 3 + 1;
		if(G[i] < n){
			m = i + 1;
		}
		else{
			break;
		}
	}
	printf("%d\n" ,m);
	for(j = m - 1; j >= 0; j--){
		if(j > 0){
			printf("%d " ,G[j]);
			c = insertionSort(A, n, G[j], c);
		}
		else{
			printf("%d\n" ,G[j]);
			c = insertionSort(A, n, G[j], c);
		}
	}
	printf("%d\n",c);
}

int main(void){
	int n,i = 0;
	scanf("%d" ,&n);
	int A[n];
	for(i = 0; i < n; i++){
		scanf("%d" ,&A[i]);
	}
	shellSort(A,n);
	for(i = 0; i < n; i++){
		printf("%d\n" ,A[i]);
	}
	return 0;
}
