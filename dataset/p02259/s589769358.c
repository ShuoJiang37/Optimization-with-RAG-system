#include <stdio.h>

int bubbleSort(int A[], int n);
void swap(int *a, int *b);

int main(){
	int i,n,a;
	int A[100];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	a=bubbleSort(A,n);
	for(i=0;i<n;i++){
		if(i>0) printf(" ");
		printf("%d",A[i]);
	}
	printf("\n");
	printf("%d\n",a);
	return 0;
}

int bubbleSort(int A[], int n){
	int i,j;
	int count=0;
	for(i=0;i<n;i++){
		for(j=n-1;j>i;j--){
			if(A[j]<A[j-1]){
				swap(&A[j],&A[j-1]);
				count++;
			}
		}
	}
	return count;
}

void swap(int *a, int *b){
	int c;
	c=*a;
	*a=*b;
	*b=c;
}