// 23 41
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char str[5]; /* 念のため一個多めに */
	int A[100];
	int i, j, v, N, count, m;

	count = 0;

	scanf("%s",str);
	N = atoi( str );

	while( scanf("%s",str) != EOF ){
		A[count] = atoi(str);
		count++;
	}

	for( m = 0; m <= N - 2; m++ ){
		printf("%d",A[m]);
		printf(" ");
	}

	printf("%d\n",A[N-1]);

	for( i = 1; i <= N - 1; i++ ){
		v = A[i];
		j = i - 1;

		while(( j >= 0 ) && ( A[j] > v ) ){
			A[j+1] = A[j];
			j--;
		}

		A[j+1] = v;

		for( m = 0; m <= N - 2; m++ ){
			printf("%d",A[m]);
			printf(" ");
		}

		printf("%d\n",A[N-1]);
	}
	return 0;
}

