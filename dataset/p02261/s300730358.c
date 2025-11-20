#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char suit;
    int value;
} card;

void DisplayArray(card C[], int N)
{
    int i;
    for (i = 0; i < N; i++) {
        if (i) printf(" ");
        printf("%c%d", C[i].suit, C[i].value);
    }
    printf("\n");
}

void BubbleSort(card C[], int N)
{
    int i, j;
    card temp;

    for (i = 0; i < N-1; i++) {
        for ( j = N-1; j >= 1; j--) {
            if (C[j].value < C[j-1].value) {
                temp = C[j];
                C[j] = C[j-1];
                C[j-1] = temp;
            }
        }
    }
}

void SelectionSort(card C[], int N)
{
    int i, j, minj;
    card temp;

    for (i = 0; i < N; i++) {
        minj = i;
        for (j = i; j < N; j++) {
            if (C[j].value < C[minj].value) minj = j;}
            temp = C[i];
            C[i] = C[minj];
            C[minj] = temp;
    }
}

int IsStable(card cBubble[], card cSelection[], int N)
{
    int i;

    for (i = 0; i < N; i++) {
        if (cBubble[i].suit != cSelection[i].suit) return 0;
    }

    return 1;
}

int main(void)
{
    int N, i;
    scanf("%d%*c", &N);
    card* C1 = (card*)malloc(sizeof(card) * N);
    card* C2 = (card*)malloc(sizeof(card) * N);

    for (i = 0; i < N; i++) {
        scanf("%c%d%*c", &C1[i].suit, &C1[i].value);
        C2[i] = C1[i];
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



