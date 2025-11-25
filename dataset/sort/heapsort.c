#include <stdio.h>

int max(int *A, int n, int i, int j, int k) {
    int m = i;
    if (j < n && A[j] > A[m]) {
        m = j;
    }
    if (k < n && A[k] > A[m]) {
        m = k;
    }
    return m;
}

void downheap(int *A, int n, int i) {
    while (1) {
        int j = max(A, n, i, 2 * i + 1, 2 * i + 2);
        if (j == i) {
            break;
        }
        int t = A[i];
        A[i] = A[j];
        A[j] = t;
        i = j;
    }
}

void heapsort(int *A, int n) {
    int i;
    for (i = (n - 2) / 2; i >= 0; i--) {
        downheap(A, n, i);
    }
    for (i = 0; i < n; i++) {
        int t = A[n - i - 1];
        A[n - i - 1] = A[0];
        A[0] = t;
        downheap(A, n - i - 1, 0);
    }
}

int main(void) {
    int A[1000000];
    int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++ ){
		scanf("%d", &A[i]);
	}
    for (int i = 0; i < n; i++) {
        printf("%d%s", A[i], i == n - 1 ? "\n" : " ");
    }
    heapsort(A, n);
    for (int i = 0; i < n; i++) {
        printf("%d%s", A[i], i == n - 1 ? "\n" : " ");
    }
    return 0;
}
