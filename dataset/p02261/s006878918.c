#include <stdio.h>
#include <string.h>
#define swap(type, x, y) {type tmp = x; x = y; y = tmp;}

typedef struct {
    char suit;
    int value;
} card;

int bubbleSort(card *a, int n) {
    int i, j, flag;
    j = 0; flag = 1;
    while (flag) {
        flag = 0;
        for (i = n - 1; i > j; i--) {
            if (a[i].value < a[i - 1].value) {
                swap(card, a[i], a[i - 1]);
                flag = 1;
            }
        }
        j++;
    }
    return 0;
}

int selectionSort(card *b, int n) {
    int i, j, mini;
    for (i = 0; i < n; i++) {
        mini = i;
        for (j = i; j < n; j++) {
            if (b[j].value < b[mini].value) mini = j;
        }
        if (i != mini) {
            swap(card, b[i], b[mini]);
        }
    }
    return 0;
}

int main(void) {
    int N;
    scanf("%d", &N);
    card C[N];
    card A[N];
    card B[N];
    int idx;

    for (idx = 0; idx < N; idx++) {
        getchar();
        scanf("%c %d", &C[idx].suit, &C[idx].value);
        A[idx].suit = C[idx].suit;
        A[idx].value = C[idx].value;
        B[idx].suit = C[idx].suit;
        B[idx].value = C[idx].value;
    }
    bubbleSort(A, N);
    selectionSort(B, N);

    for (idx = 0; idx < N; idx++) {
        printf("%c%d", A[idx].suit, A[idx].value);
        if (idx < N - 1) printf(" ");
    }
    printf("\n");
    printf("Stable\n");

    int fg = 1;
    for (idx = 0; idx < N; idx++) {
        printf("%c%d", B[idx].suit, B[idx].value);
        if (idx < N - 1) printf(" ");
        if (A[idx].suit != B[idx].suit || A[idx].value != B[idx].value) {
            fg = 0;
        }
    }
    printf("\n");

    if (fg) printf("Stable\n");
    else printf("Not stable\n");

    return 0;
}
