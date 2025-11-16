#include <stdio.h>

void write(int A[], int n){
	int i;
	for (i = 0; i < n-1; ++i)
	{
		printf("%d ", A[i]);
	}
	printf("%d\n", A[n-1]);
}

void insertionSort(int A[], int n){
	int i,k,memo;
	for (i = 1; i < n; ++i)
	{
		memo = A[i]; 
		k = i-1;
		while(k >= 0 && A[k] > memo)
		{
			A[k+1] = A[k];
			k--;
		}
		A[k+1] = memo;

		write(A,n);
	}
}


int main()
{
	int n,A[100],memo,i,k;
	scanf("%d",&n);
	for(i = 0; i < n; ++i)
	{
		scanf("%d",&A[i]);
    }

    write(A,n);
    insertionSort(A,n);

	return 0;
}