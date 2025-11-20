#include <stdio.h>
#define MAX 2000010
#define RANGE 10010

int A[MAX];
int B[MAX];
int C[RANGE] = {0};

void countingSort(int A[], int B[], int n, int r)
{
    int i;
    // ??????
    for (i=0; i<n; i++) {
        C[A[i]]++;
    }
    
    // ??°?????????
    for (i=1; i<r; i++) {
        C[i] += C[i-1];
    }
    
    // ?????????
    for (i=n-1; i>=0; i--) {
        B[--C[A[i]]] = A[i];
    }    
}

int main()
{
    int i, N;
    scanf("%d", &N);
    for (i=0; i<N; i++) {
        scanf("%d", &A[i]);
    }
    
    countingSort(A, B, N, RANGE);
    
    for (i=0; i<N; i++) {
        printf("%d", B[i]);
        if (i<N-1) printf(" ");
    }
    puts("");
    
    return 0;
}