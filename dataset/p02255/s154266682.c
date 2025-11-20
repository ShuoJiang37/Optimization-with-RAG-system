#include <stdio.h>
int N;

void Process(int A[ ], int n){
	int i;
	for(i=0;i<n-1;i++)
		printf("%d ",A[i]);
	printf("%d\n",A[i]);
}

void InsertionSort(int A[ ], int n){
	int i,j,v;
	for(i=1;i<n;i++){
		v = A[i];
		j = i - 1;
		/*for(j = i; j > 0 && A[j-1] > v; j--)
			A[j] = A[j-1];
		A[j] = v;*/
		while(j>=0 && A[j]>v){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
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