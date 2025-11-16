#include <stdio.h>

int insertionSort(int A[],int n,int G,int cnt){
	int i,v;
	for(i=G;i<=n-1;i++){
		v=A[i];
		int j=i-G;
		
		while(j>=0 && A[j]>v){
			A[j+G]=A[j];
			j=j-G;
			cnt++;
		}
		A[j+G]=v;
		
	}
	return cnt;
}

void shellSort(int A[], int n){
	int m,i,cnt;
	int G[n];
	m=0;
	cnt=0;
	
	for(int h=1;;){
		if(h>n){
			break;
		}
		G[m]=h;
		h = 3*h+1;
		m++;
	}
	
	printf("%d\n",m);
	for(i=m-1;i>=0;i--){
		if(i!=m-1){
			printf(" ");
		}
		printf("%d",G[i]);
	}
	
	printf("\n");
	
	for(i=m-1;i>=0;i--){
		cnt=insertionSort(A,n,G[i],cnt);
	}
	printf("%d\n",cnt);
	for(i=0;i<n;i++){
		printf("%d\n",A[i]);
	}
}

int main(void){
	int n,i;
	int A[1000000];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	
	shellSort(A,n);
	return 0;
}
