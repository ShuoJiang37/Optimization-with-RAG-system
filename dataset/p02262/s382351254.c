#include<stdio.h>
#include<math.h>
int m;
int G[10000000];
int A[10000000];
int i,n;
int cnt;
void insertionSort(int A[] ,int n, int g){
	for(int i=g;i<n;i++){
		int v=A[i];
		int j=i-g;
		while(j>=0 && A[j]>v){
			A[j+g]=A[j];
			j-=g;
			cnt++;
		}
	A[j+g]=v;
	}
}

void shellSort(int A[], int n){
	cnt =0;
	G[0]=1;
	for(i=1;i<100;i++){
		G[i]=3*(G[i-1])+1;
		if(G[i]>n){break;}
	}
	m=i;
	for(i=m-1; i>=0; i--){
		insertionSort(A,n,G[i]);
	}
}

int main(void){
	scanf("%d",&n);
	
	for(i=0; i<n; i++){
		scanf("%d",&A[i]);
	}
	
	 cnt=0;
	
	shellSort(A,n);
	
	printf("%d\n",m);
	
	for(i=m-1; i>=0; i--){
		printf("%d",G[i]);
		if(i){printf(" ");}
	}
	
	printf("\n");
	
	printf("%d\n",cnt);
	
	for(i=0; i<n; i++){
		printf("%d\n",A[i]);
	}
	
	return 0;
}		
