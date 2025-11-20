#include <stdio.h>

void insertionSort(int A[],int n,int g);
void shellSort(int A[],int n);

int m;
int cnt;
int G[1000000];

int main(void)
{
	int i,n;
	scanf("%d", &n);
	
	int a[n];
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	
	shellSort(a,n);
	
	printf("%d\n", m);
	for(i=m-1; i>=0; i--){
		printf("%d ",G[i]);
	}
	printf("\n");
	printf("%d\n",cnt);
	for(i=0; i<n; i++){
		printf("%d\n",a[i]);
	}
	
	return 0;
}

void insertionSort(int A[],int n,int g)
{
	int i,j,v;
	for(i=g; i<n; i++){
		v=A[i];
		j=i-g;
		while(j >= 0 && A[j] > v){
			A[j+g] = A[j];
			j=j-g;
			cnt++;
		}
		A[j+g]=v;
	}
}

void shellSort(int A[], int n)
{
	int i,t;
	m=0;
	cnt=0;
	for(int h=0;; h++){
		t=1;
		for(i=0; i<=h; i++){
			t=3*t;
		}
		G[h]=(t-1)/2;
		if(G[h] > n){
			break;
		}
		m++;
	}
	
	for(i=m-1; i>=0; i--){
		insertionSort(A,n,G[i]);
	}
}
