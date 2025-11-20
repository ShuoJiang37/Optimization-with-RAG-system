#include <stdbool.h>
#include <stdio.h>

struct Card
{
    char suit;
    int value;
};

static void print(struct Card A[], int N)
{
    for (int i = 0; i < N; i++) {
        if (i > 0)
            printf(" ");
        printf("%c%d", A[i].suit, A[i].value);
    }
    printf("\n");
}

static void bubbleSort(struct Card A[], int N)
{
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j >= i + 1; j--) {
            if (A[j].value < A[j - 1].value) {
                struct Card tmp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = tmp;
            }
        }
    }
}

static void selectionSort(struct Card A[], int N)
{
    for (int i = 0; i < N; i++) {
        int minj = i;
        for (int j = i + 1; j < N; j++) {
            if (A[j].value < A[minj].value) {
                minj = j;
            }
        }
        if (i != minj) {
            struct Card tmp = A[i];
            A[i] = A[minj];
            A[minj] = tmp;
        }
    }
}

static bool isStable(struct Card C1[], struct Card C2[], int N)
{
    for (int i = 0; i < N; i++) {
        if (C1[i].suit != C2[i].suit) {
            return false;
        }
    }

    return true;
}

int main()
{
    int N;
    struct Card C1[36], C2[36];

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%*c%c%d", &C1[i].suit, &C1[i].value);
        C2[i] = C1[i];
    }

    bubbleSort(C1, N);
    print(C1, N);
    printf("Stable\n");

    selectionSort(C2, N);
    print(C2, N);
    printf(isStable(C1, C2, N) ? "Stable\n" : "Not stable\n");
}
