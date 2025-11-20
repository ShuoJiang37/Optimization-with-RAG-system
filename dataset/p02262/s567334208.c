#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void insertionSort(int A[],int n,int g,int *cnt){
	int v,j,c=0;
	for(int i=g;i<n;i++){
		v=A[i];
		j=i-g;
		while(j>=0 && A[j]>v){
			A[j+g]=A[j];
			j=j-g;
			c++;
		}
		A[j+g]=v;
	}
	*cnt+=c;
}

int calc_m(int n){
	int m=0;
	int c=0;
	while(1){
		if(((m*3)+1)>n){
			break;
		}
		m=((m*3)+1);
		c++;
	}
	
	return c;
}

void shellSort(int A[],int n){
	//printf("\n\n");
	int cnt=0;
	int m=calc_m(n);
	int *G=(int*)malloc(sizeof(int)*m),g=0;

	for(int i=(m-1);i>=0;i--){
		G[i]=((g*3)+1);
		g=G[i];
	}
	
	for(int i=0;i<m;i++){
		insertionSort(A,n,G[i],&cnt);
	}
	
	printf("%d\n",m);
	for(int i=0;i<m;i++){
		printf("%d",G[i]);
		if(i==(m-1)){
			printf("\n");
		}else{
			printf(" ");
		}
	}
	printf("%d\n",cnt);
	for(int i=0;i<n;i++){
		printf("%d\n",A[i]);
	}
}

int main(){
    int n;
	int *A;

	scanf("%d",&n);
	A=(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
	}

	shellSort(A,n);

	return 0;
}
