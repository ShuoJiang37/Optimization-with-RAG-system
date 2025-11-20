#include <stdio.h>

static const int MAXNUMOFINPUT = 36;

typedef struct {
    char suit;
    int value;
} CARD;

int bubbleSort(CARD C[], int N);
int selectionSort(CARD C[], int N);
int isStable(CARD C1[], CARD C2[], int N);
int printArray(CARD C[], int N);

int main()
{
    int i;
    int N;
    CARD C1[MAXNUMOFINPUT];
    CARD C2[MAXNUMOFINPUT];

    scanf("%d\n", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%c%d", &C1[i].suit, &C1[i].value);
        getchar();
        C2[i] = C1[i];
    }

    bubbleSort(C1, N);
    selectionSort(C2, N);
    printArray(C1, N);
    printf("Stable\n");
    printArray(C2, N);
    printf("%s\n", isStable(C1, C2, N) ? "Stable" : "Not stable");

    return 0;
}

int bubbleSort(CARD C[], int N)
{
    int i, j;
    CARD tmp;

    for (i = 0; i < N; i++)
    {
        for (j = N - 1; j > i; j--)
        {
            if(C[j].value < C[j - 1].value)
            {
                tmp = C[j];
                C[j] = C[j - 1];
                C[j - 1] = tmp;
            }
        }
    }

    return 0;
}

int selectionSort(CARD C[], int N)
{
    int i, j;
    int minj;
    CARD tmp;

    for (i = 0; i < N; i++)
    {
        minj = i;

        for (j = i; j < N; j++)
        {
            if(C[j].value < C[minj].value)
            {
                minj = j;
            }
        }

        tmp = C[i];
        C[i] = C[minj];
        C[minj] = tmp;
    }

    return 0;
}

int isStable(CARD C1[], CARD C2[], int N)
{
    int i;

    for (i = 0; i < N; i++)
    {
        if(C1[i].suit != C2[i].suit)
        {
            return 0;
        }
    }

    return 1;
}

int printArray(CARD C[], int N)
{
    int i;

    for (i = 0; i < N; i++)
    {
        printf("%c%d", C[i].suit, C[i].value);
        if (i < N - 1)
        {
            printf(" ");
        }
    }

    printf("\n");

    return 0;
}

