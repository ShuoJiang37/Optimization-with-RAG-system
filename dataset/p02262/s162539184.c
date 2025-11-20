#include <stdio.h>
#include <math.h>

int cnt;

void insertionSort( int A[], int n, int g )
{
    int v;
    int j;
    
    for ( int i = g; i < n; i++ ) {
        v = A[i];
        j = i - g;
        while ( j >= 0 && A[j] > v ) {
            A[j + g] = A[j];
            j -= g;
            cnt++;
        }
        A[j + g] = v;
    }
}

void shellSort( int A[], int n )
{
    cnt = 0;
    int m;
    m = log10(2 * n + 1) / log10(3.0);
    int G[100] = {0};

    G[m - 1] = 1;
    for ( int i = m - 2; i >= 0; i-- ) {
        G[i] = 3 * G[i + 1] + 1;
    }

    printf("%d\n", m);

    for ( int i = 0; i < m; i++ ) {
        printf("%d", G[i]);
        if ( i != m - 1 ) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
    for ( int i = 0; i < m; i++ ) {
        insertionSort( A, n, G[i]);
    }

}

int main(void)
{
    int n;
    static int A[1000000];
    
    scanf("%d", &n);
    
    for ( int i = 0; i < n; i++ ) {
        scanf("%d", &A[i]);
    }
    
    shellSort( A, n );
   
    printf("%d\n", cnt);

    for ( int i = 0; i < n; i++ ) {
        printf("%d\n", A[i]);
    }
    
    return 0;
}
