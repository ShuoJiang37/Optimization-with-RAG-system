#include <stdio.h>
#include <stdlib.h>

struct Card {
    char suit;
    char value;
};

void printLine(struct Card C[], int N)
{
    int i;
    for (i = 0; i < N; i++) {
        if (i > 0) printf(" ");
        printf("%c%c", C[i].suit, C[i].value);
    }
    printf("\n");
}

void swap(struct Card *a, struct Card *b)
{
    struct Card tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void selectionSort(struct Card C[], int N)
{
    int minj;
    for (int i = 0; i < N - 1; i++) {
        minj = i;
        for (int j = i; j < N; j++) {
            if (C[j].value < C[minj].value) {
                minj = j;
            }
        }
        if (i != minj) {
            swap(&C[i], &C[minj]);
        }
    }
}


void bubbleSort(struct Card C[], int N)
{
    int flag = 1;
    for (int i = 0; flag; i++) {
        flag = 0;
        for (int j = N-1; j > i; j--) {
            if (C[j-1].value > C[j].value) {
                swap(&C[j], &C[j-1]);
                flag = 1;
            }
        }
    }
}

int isStable(struct Card C1[], struct Card C2[], int N)
{
    for (int i = 0; i < N; i++) {
        if (C1[i].suit != C2[i].suit) return 0;
    }
    return 1;
}

int main(void)
{  
    int i, N;
    struct Card C1[36];
    struct Card C2[36];

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        char tmp[2];
        scanf("%s", tmp);
        C1[i].suit = tmp[0];
        C1[i].value = tmp[1];
    }

    for (i = 0; i < N; i++) {
        C2[i] = C1[i];
    }

    bubbleSort(C1, N);
    printLine(C1, N);
    printf("Stable\n");

    selectionSort(C2, N);
    printLine(C2, N);
    if (isStable(C1, C2, N)) {
        printf("Stable\n");
    } else {
        printf("Not stable\n");
    }

    return 0;
}
