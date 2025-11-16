#include <stdio.h>

void bubbleSort(int A[], const int N)
{
    int i, j;
    int flag = 1, cnt = 0;

    for( i = 0; flag; ++i ){
        flag = 0;

        for( j = N-1; i < j; --j )
            if( A[j] < A[j-1] ){
                int tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;

                flag = 1;
                ++cnt;
            }
    }

    for( i = 0; i < N; ++i ){
        if( 0 < i ) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n%d\n", cnt);
}

int main()
{
    int i;

    int N;
    scanf("%d", &N);
    int A[N];
    for( i = 0; i < N; ++i )
        scanf("%d", &A[i]);

    bubbleSort(A, N);

    return 0;
}