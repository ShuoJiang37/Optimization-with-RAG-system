#include <stdio.h>

void shellSort(int *A, int n);
int insertionSort(int *A, int n, int g);

int main() {
    int n;
    scanf("%d", &n);
    int A[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &A[i]);
    }
    
    shellSort(A, n);
    
    for (int j=0; j<n; j++) {
        printf("%d\n", A[j]);
    }
    
    return 0;
}

void shellSort(int *A, int n) {
    int cnt = 0;
    int m = 1;
    int temp = 1;       // interval (1, 4, 13, 40, 121, …)
    while (temp * 3 + 1 < n) {
        temp = temp * 3 + 1;
        m++;
    }
    int G[m];
    for (int i=0; i<m; i++) {
        G[i] = temp;
        temp = (temp - 1) / 3;
    }
    
    for (int j=0; j<m; j++) {
        cnt += insertionSort(A, n, G[j]);
    }
    
    printf("%d\n", m);
    for (int k=0; k<m; k++) {
        printf("%d", G[k]);
        if (k == m - 1) {
            putchar('\n');
        } else {
            putchar(' ');
        }
    }
    printf("%d\n", cnt);
    return;
}

int insertionSort(int *A, int n, int g) {
    int cnt = 0;
    for (int i=g; i<n; i++) {
        int v = A[i];
        int j = i - g;
        while (j >= 0 && A[j] > v) {
            A[j+g] = A[j];
            j = j - g;
            cnt++;
        }
        A[j+g] = v;
    }
    
    return cnt;
}


