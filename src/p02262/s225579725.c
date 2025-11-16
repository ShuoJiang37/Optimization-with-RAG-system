#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

void insertionSort(int *A,int n,int g);
void shellSort(int *A,int n);

	
	int cnt=0;
	
int main(void){
	
	int A[1000000],G[1000];
	int i,n;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	
	shellSort(A,n);
	
	printf("%d\n",cnt);
	
	for(i=0;i<n;i++){
		printf("%d\n",A[i]);
	}
	
	return 0;
}

void insertionSort(int *A,int n,int g){
	
	int i,j,v;
	
	for(i=g;i<n;i++){
		v=A[i];
		j=i-g;
		while(j>=0 && A[j]>v){
			A[j+g]=A[j];
			j=j-g;
			cnt++;
		}
		A[j+g]=v;
	}
}

void shellSort(int *A,int n){
	
	int cnt,m=0,i,h;
	int G[1000];
	
	cnt=0;
	
	for(h=1,i=0;;i++){
		if(h>n){
			break;
		}
		G[i]=h;
		h=3*h+1;
		m++;
	}
	
	
	for(i=m-1;i>=0;i--){
		insertionSort(A,n,G[i]);
	}
	
	printf("%d\n",m);
	
	for(i=m-1;i>=0;i--){
		printf("%d",G[i]);
		if(i!=0){
			printf(" ");
		}
	}
	printf("\n");
	

}

