#include<stdio.h>

void insertionSort(int A[], int n, int g);
void shellSort(int A[], int n);

int cnt;

int main(void){
	int n;
	scanf("%d", &n);
	
	int A[n], i;
	
	for(i=0; i<n; i++){
		scanf(" %d", &A[i]);
	}
	
	shellSort(A, n);
	printf("%d\n", cnt);
	for(i=0; i<n; i++) printf("%d\n", A[i]);
	
	return 0;
}

void insertionSort(int A[], int n, int g){
	
	int i, v, j;
	
	for(i=g; i<n; i++){
		v=A[i];
		j=i-g;
		
		while(0<=j && v<A[j]){
			A[j+g]=A[j];
			j=j-g;
			cnt++;
		}
		A[j+g]=v;
	}
}

void shellSort(int A[], int n){
	
	int g[100], m, i;
	
	g[0]=1;
	for(m=1; 3*g[m-1]+1<=n; m++) g[m]=g[m-1]*3+1;
	printf("%d\n", m);
	
	cnt=0;
	
	for(i=m-1; i>=0; i--) {
		if(i==0) printf("%d\n", g[i]);
    	else printf("%d ", g[i]);
		insertionSort(A, n, g[i]);
 	}
}
