#include <stdio.h>

void insertionSort(int A[1001], int N) {
    int i, j;
    int v;

    for (i = 1; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d", A[j]);
            if (j != N-1)
                printf(" ");
            else
                printf("\n");
        }

        v = A[i];
        j = i-1;
        while (j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
    }
}

int main() {
    int N, A[1001];
    int i;

    scanf("%d", &N);

    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);

    insertionSort(A, N);

    for (i = 0; i < N; i++) {
        printf("%d", A[i]);
        if (i != N-1)
            printf(" ");
        else
            printf("\n");
    }

    return 0;
}