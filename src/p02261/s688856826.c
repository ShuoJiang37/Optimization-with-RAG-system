#include <stdio.h>

typedef struct {
    char mark;
    int value;
} Card;

void print(Card C[], int N) {
    int i;
    for (i = 0; i < N; i++) {
        printf("%c%d", C[i].mark, C[i].value);
        if (i != N-1)
            printf(" ");
        else
            printf("\n");
    }
}

void BubbleSort(Card C[], int N) {
    int i, j;
    Card tmp;

    for (i = 0; i < N; i++) {
        for (j = N-1; j > i; j--) {
            if (C[j].value < C[j-1].value) {
                tmp = C[j];
                C[j] = C[j-1];
                C[j-1] = tmp;
            }
        }
    }
    print(C, N);
    printf("Stable\n");
}

void SelectionSort(Card C[], int N) {
    int i, j;
    int minj;
    Card tmp;

    for (i = 0; i < N; i++) {
        minj = i;
        for (j = i; j < N; j++){
            if (C[j].value < C[minj].value)
                minj = j;
        }
        tmp = C[i];
        C[i] = C[minj];
        C[minj] = tmp;
    }
    print(C, N);
}

int main() {
    int N, flag = 1;
    int i;
    Card C1[36], C2[36];

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf(" %c%d", &C1[i].mark, &C1[i].value);
        C2[i] = C1[i];
    }

    BubbleSort(C1, N);
    SelectionSort(C2, N);

    for(i = 0; i < N; i++) {
        if(C1[i].mark != C2[i].mark) {
            flag = 0;
            break;
        }
    }

    if (flag)
        printf("Stable\n");
    else
        printf("Not stable\n");

    return 0;
}