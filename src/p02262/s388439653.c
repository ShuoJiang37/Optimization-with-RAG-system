#include <stdio.h>
#include <stdlib.h>

int count;

void insertionSort(int A[], int n, int g)
{
    int i;
    int j;
    int v;

    for(i = g; i < n; i++) {
        v = A[i];
        j = i - g;
        while(j >= 0 && A[j] > v) {
            A[j+g] = A[j];
            j = j - g;
            count++;
        }
        A[j+g] = v;
    }
}

void shellSort(int A[], int n)
{
    int m;
    int *G;
    int i;
    int c;

    count = 0;
    m = 1;
    for(c = n; (c/9) != 0; c /= 9) {
        m += 1;
    }
    //m = n / 2;
    G = (int *)malloc(sizeof(int) * m);
    G[m-0-1] = 1;
    for(i = 1; i < m; i++) {
        G[m-i-1] = 3*G[m-i] + 1;
    }
    for(i = 0; i < m; i++) {
        insertionSort(A, n, G[i]);
    }

    printf("%d\n", m);
    for(i = 0; i < m-1; i++) {
        printf("%d ", G[i]);
    }
    printf("%d\n", G[i]);
    printf("%d\n", count);

    free((void *)G);
}

int main()
{
    int n;
    int *A;
    int i;

    scanf("%d", &n);
    A = (int *)malloc(sizeof(int) * n);
    for(i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    shellSort(A, n);

    for(i = 0; i < n; i++) {
        printf("%d\n", A[i]);
    }

    return 0;
}
