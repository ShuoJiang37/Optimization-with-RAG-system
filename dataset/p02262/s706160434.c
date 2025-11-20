#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *A, int n, int g, int *cnt) {
    int i, j, v;

    for (i=g;i<n;i++) {
        v = A[i];
        j = i - g;
        while (j>=0 && A[j]>v) {
            A[j+g] = A[j];
            j = j - g;
            (*cnt)++;
        }
        A[j+g] = v;
    }
}


int main(void) {
    int i, n, *A;
    int j, G[100], h=1, cnt=0;

    scanf("%d", &n);
    A=(int *)malloc(sizeof(int)*n);
    for (i=0; i<n; i++) scanf("%d", &A[i]);
    
    // shellSort
    j=0;
    while (h<=n) {
        G[j]=h;
        j++;
        h=3*h+1;
    }

    for (i=j-1;i>=0;i--) insertionSort(A, n, G[i], &cnt);
    
    printf("%d\n", j);
    for (i=j-1;i>=0;i--) {
        printf("%d", G[i]);
        if (i>0) printf(" ");
    }
    printf("\n%d\n", cnt);
    for (i=0;i<n;i++) printf("%d\n", A[i]);

    return 0;
}

