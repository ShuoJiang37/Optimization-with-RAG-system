#include <stdio.h>
#define N 100

void bubbleSort(int*, int);

int main(void){

	int A[N],n;
	int i=0;

	scanf("%d",&n);

	for(i = 0; i < n; i++){
		scanf("%d",&A[i]);
	}

	bubbleSort(A,n);

	return 0;
}

void bubbleSort(int *A, int n){

	int i,j,swap,count=0;

	for(i = 0; i < n-1; i++){
		for(j = n-1; j >= i; j-- ){
			if(A[j] < A[j-1]){
				swap = A[j];
				A[j] = A[j-1];
				A[j-1] = swap;
				count++;
			}
		}
	}

	for (i = 0; i < n-1; i++){
		printf("%d ",A[i]);
	}
	printf("%d\n",A[n-1]);
	printf("%d\n",count);
}