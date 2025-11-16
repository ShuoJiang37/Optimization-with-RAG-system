#include <stdio.h>
int N;

void Process(int A[ ], int n){
	int i;
	for(i=0;i<n-1;i++)
		printf("%d ",A[i]);
	/*while(n>1){
		printf("%da", *A++);
	n--;
}*/
	printf("%d\n",A[i]);
}

void InsertionSort(int A[ ], int n){
	int i,j,v;
	for(i=1;i<n;i++){
		v = A[i];
		for(j = i; j > 0 && A[j-1] > v; j--)
			A[j] = A[j-1];
		A[j] = v;
		Process(A, N);

	}
}



int main(void){
	int i;
	scanf("%d",&N);
	int A[100];
	for(i=0;i<N;i++)
		scanf("%d",&A[i]);
	Process(A, N);
	InsertionSort(A, N);
	
	
	return 0;


}