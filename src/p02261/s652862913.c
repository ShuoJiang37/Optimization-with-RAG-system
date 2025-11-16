#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct tag_card {
    char suit_;
    int num_;
} card_t;

void DisplayArray(card_t C[], int N)
{
    int i;
    for (i = 0; i < N; i++) {
        if (i) printf(" ");
        printf("%c%d", C[i].suit_, C[i].num_);
    }
    printf("\n");
}

void BubbleSort(card_t C[], int N)
{
    int i, j;
    card_t tmp;

    for (i = 0; i < N - 1; i++) {
        for (j = N - 1; j >= i; j--) {
            if (C[j].num_ < C[j - 1].num_) {
                tmp = C[j];
                C[j] = C[j - 1];
                C[j - 1] = tmp;
            }
        }
    }
}

void SelectionSort(card_t C[], int N)
{
    int i, j, minj;
    card_t tmp;

    for (i = 0; i < N; i++) {
        minj = i;
        for (j = i; j < N; j++) {
            if (C[j].num_ < C[minj].num_) {
                minj = j;
            }
        }
        tmp = C[i];
        C[i] = C[minj];
        C[minj] = tmp;
    }
}

int IsStable(card_t cBubble[], card_t cSelection[], int N)
{
    int i;

    for (i = 0; i < N; i++) {
        if (cBubble[i].suit_ != cSelection[i].suit_) return FALSE;
    }

    return TRUE;
}

int main(void)
{
    int N, i;
    scanf("%d%*c", &N);
    card_t* C1 = (card_t*)malloc(sizeof(card_t) * N);
    card_t* C2 = (card_t*)malloc(sizeof(card_t) * N);

    for (i = 0; i < N; i++) {
        scanf("%c%d%*c", &C1[i].suit_, &C1[i].num_);
        C2[i].suit_ = C1[i].suit_;
        C2[i].num_ = C1[i].num_;
    }

    BubbleSort(C1, N);
    SelectionSort(C2, N);

    DisplayArray(C1, N);
    printf("Stable\n");
    DisplayArray(C2, N);
    if (IsStable(C1, C2, N)) {
        printf("Stable\n");
    } else {
        printf("Not stable\n");
    }

    return 0;
}