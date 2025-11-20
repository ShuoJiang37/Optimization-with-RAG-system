#include <stdio.h>
#include <stdlib.h>

long long count = 0;

void insertionSort(int n, int A[], int g)
{
    int i;
    for (i = g; i < n; i++) {
        int v = A[i];
        int j = i - g;
        while (j >= 0 && A[j] > v) {
            A[j+g] = A[j];
            j -= g;
            count++;
        }
        A[j+g] = v;
    }
}

void shellSort(int n, int A[])
{
    if (n == 1) { printf("1\n1\n"); return;}
    
    int *G = (int*)malloc(sizeof(int) * n);
    int i, h, m;
    for (i = 0, h = 1; h < n; m = i++, h = 3*h + 1) {
        G[i] = h;
    }
    printf("%d\n", m+1);
    
    while(i-->0) {
        insertionSort(n, A, G[i]);
        if (m != i && i >= 0) printf(" ");
        printf("%d", G[i]);
    }
    puts("");
    free(G);
}

int main()
{
    int i;
    int N;    
    scanf("%d", &N);
    int *A = (int*)malloc(sizeof(int) * N);
    for (i = 0; i < N ;i++) {
        scanf("%d", &A[i]);
    }
    
    shellSort(N, A);    
    printf("%d\n", count);
    for (i = 0; i < N ;i++) {
        printf("%d\n", A[i]);
    }
    free(A);
    
    return 0;
}