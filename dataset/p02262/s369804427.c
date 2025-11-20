#include <stdio.h>

int cnt;
void insertionSort(int A[], int n, int g)
{
    
    for( int i = g; i < n; ++i ){
        int tmp = A[i];
        int j = i - g;
        while( -1 < j && tmp < A[j] ){
            
            A[j+g] = A[j];
            j = j - g;
            cnt++;
        }
        A[j+g] = tmp;
    }
}

void shellSort(int A[], int n)
{
    cnt = 0;
    int m;
    int G[100];
    for( int i = 0; i < 100; ++i ){
        if( i == 0 ) G[i] = n / 2 + 1;
        else G[i] = G[i-1] / 2 - 1;
        if( G[i] < 0 ){
            G[i-1] = 1;
            G[i] = 0;
            m = i;
            break;
        }
    }
    
    for( int i = 0; i < m; ++i )
        insertionSort(A, n, G[i]);
    
    printf("%d\n", m);
    for( int i = 0; i < m; ++i ){
        if( i ) printf(" ");
        printf("%d", G[i]);
    }
    printf("\n%d\n", cnt);
    for( int i = 0; i < n; ++i )
        printf("%d\n", A[i]);
}

int main()
{
    int n;
    scanf("%d", &n);
    int A[n];
    for( int i = 0; i < n; ++i )
        scanf("%d", &A[i]);
    
    shellSort(A, n);
    
    return 0;
}
