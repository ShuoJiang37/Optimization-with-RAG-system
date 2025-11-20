#include <stdio.h>

int insertionSort(int A[],int n,int g)
{
	int i, j, v, cnt=0;
	for(i=g; i<n; i++){
		v = A[i];
		j = i - g;
		while(j>=0 && A[j]>v){
			A[j+g] = A[j];
			j = j - g;
			cnt++;
		}
		A[j+g] = v;
	}
	return cnt;
}

int  shellSort(int A[],int n, int G[], int m)
{
	int i,cnt=0,be;

	for(i=m; i>=0; i--){
		be = insertionSort(A, n, G[i]);
		cnt+=be;
	}
	return cnt;
}

int main(void)
{	
	int n, i, a=1, cnt, j, su;
	int A[1000000];
	int G[100];

	scanf("%d", &n);	
	for(i=0; i<n; i++){
		scanf("%d", &A[i]);
	}
	
	for(i=1;;i++){
		su=(a*3-1)/2;
		if(su>n){break;}
		G[i-1]=su;
		a=a*3;
	}
	i=i-1;
	
	cnt=shellSort(A, n, G, i);

	printf("%d\n", i);
	for(j=i-1; j>0; j--){
		printf("%d ", G[j]);
	}
	printf("%d\n", G[0]);
	printf("%d\n", cnt);

	for(j=0; j<n; j++){
		printf("%d\n", A[j]);
	}
	
	return 0;
}
