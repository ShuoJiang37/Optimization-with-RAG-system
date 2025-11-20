#include <stdio.h>
#include <string.h>

typedef struct { 
    char suit;
    int value;
} Card;

void bubbleSort(Card C[], int N) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = N - 1; j > i; j--) {
            if (C[j].value < C[j-1].value) {
                Card tmp = C[j];
                C[j] = C[j-1];
                C[j-1] = tmp;
            }
        }
    }
}

void selectionSort(Card C[], int N) {
    int i, j, minj;
    for (i = 0; i < N; i++) {
        Card tmp;
        minj = i;
        for (j = i; j < N; j++) {
            if (C[j].value < C[minj].value) {
                minj = j;
            }
        }
        tmp = C[i];
        C[i] = C[minj];
        C[minj] = tmp;
    }
}

int equals(Card *c1, Card *c2) {
    if (c1->suit != c2->suit || c1->value != c2->value) {
        return 0;
    } else {
        return 1;
    }
}

void isStable(Card in[], Card out[], int N) {
    int i, j, a, b;
    for (i = 0; i < N - 1; i++) {
        for (j = i + 1; j < N - 1; j++) {
            for (a = 0; a < N - 1; a++) {
                for (b = a + 1; b < N - 1; b++) {
                    if (in[i].value == in[j].value && equals(&in[i], &out[b]) && equals(&in[j], &out[a])) {
                        printf("Not stable\n");
                        return;
                    }
                }
            }
        }
    }
    printf("Stable\n");
}

void trace(Card C[], int N) {
    int i;
    for (i = 0; i < N; i++) {
        if (i) printf(" ");
        printf("%c%d", C[i].suit, C[i].value);
    }
    printf("\n");
}

int main(void) {
    int i, N;
    Card in[36]; // 初期状態
    Card C1[36]; // バブルソート用
    Card C2[36]; // 選択ソート用
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf(" %c%d", &in[i].suit, &in[i].value);
    }
    memcpy(C1, in, sizeof(in[0]) * N);
    memcpy(C2, in, sizeof(in[0]) * N);
    bubbleSort(C1, N);
    trace(C1, N);
    isStable(in, C1, N);
    selectionSort(C2, N);
    trace(C2, N);
    isStable(in, C2, N);
    return 0;
}

