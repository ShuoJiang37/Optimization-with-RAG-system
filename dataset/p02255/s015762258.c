#include <stdio.h>

int main()
{
	int i,j,k,memo,n,A[100];
	scanf("%d",&n);
	for(i = 0; i < n; ++i)
	{
		scanf("%d",&A[i]);
    }

    for (i = 0; i < n-1; ++i)
    {
    	printf("%d ", A[i]);
    }
    printf("%d\n", A[n-1]);

	for (i = 1; i < n; ++i)
	{
		memo = A[i]; 
		j = i-1;
		while(j >= 0 && A[j] > memo)
		{
			A[j+1] = A[j];
			A[j] = memo;
			j--;
		}

		for (k = 0; k < n-1; ++k)
		{
			printf("%d ", A[k]);
		}
		printf("%d\n", A[n-1]);

	}

	return 0;
}