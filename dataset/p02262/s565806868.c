#include <stdio.h>
#include <stdlib.h>

int cnt;

void insertionSort(int A[], int n, int g) {
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

void shellSort(int A[], int n) {
    int m, g, i;
    int size = 100;
    int *G;

    G = (int *)malloc(sizeof(int) * size);
    if (G == NULL) exit(0);

    cnt = 0;

    // G[i]を生成
    for (m = 0, g = 1; g <= n; m++) {
        if (m >= size) {
            size = size + 100;
            G = (int *)realloc(G, sizeof(int) * size);
            if (G == NULL) exit(0);
        }
        G[m] = g;
        g = 3 * g + 1;
    }

    // 実行と出力
    printf("%d\n", m);
    for (i = m - 1; i >= 0; i--) {
        printf("%d", G[i]);
        if (i) printf(" ");
        else printf("\n");
        insertionSort(A, n, G[i]);
    }
    printf("%d\n", cnt);
    for (i = 0; i < n; i++) printf("%d\n", A[i]);

    free(G);
}

int main(void) {
    int A[1000000];
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", A + i);
    shellSort(A, n);
    return 0;
}

