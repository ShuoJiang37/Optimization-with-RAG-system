#include <stdio.h>
#include <stdlib.h>

#define N 1000000

int cnt = 0;

void insertionSort(int *A, int n, int g) {
    int i, j, v;
    for (i = g; i < n; i++) {
        v = A[i];
        j = i - g;
        while (j >= 0 && A[j] > v) {
            A[j+g] = A[j];
            j = j - g;
            cnt++;
        }
        A[j+g] = v;
    }
}

int main(){

    int A[N], G[N], n, i, j, m, g;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    
    m = 1;
    for (g = 1; g * 3 + 1 < n; g = g * 3 + 1, m++);
    
    
    for (i = 0; i <= m - 1; i++) {
        G[i] = g;
        insertionSort(A, n, g);
        g = (g - 1) / 3;
    }
    
    printf("%d\n", m);
    
    for (i = 0; i < m - 1; i++) {
        printf("%d ", G[i]);
    }
    printf("%d\n%d\n", G[i], cnt);
    
    for (i = 0; i < n; i++) {
        printf("%d\n", A[i]);
    }

    return 0;
}

