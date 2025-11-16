#include <stdio.h>
#include <stdbool.h>

#define SIZE 36

typedef struct {
    char suit;
    int val;
} card;

void
selectionSort(card [], int);

void
bubbleSort(card [], int);

void
print(card [], int);

bool
compare(card [], card [], int);

int main(void)
{
    int n, i;
    card c1[SIZE], c2[SIZE];

    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++) {
        scanf("%c %d", &c1[i].suit, &c1[i].val);
        c2[i] = c1[i];
        getchar();
    }

    bubbleSort(c1, n);
    selectionSort(c2, n);

    print(c1, n);
    printf("Stable\n");
    print(c2, n);
    printf("%s\n", compare(c1, c2, n) ? "Stable" : "Not stable");

    return 0;
}


void
bubbleSort(card arr[], int n)
{
    int i, j;
    card v;

    for (i = 0; i < n; i++)
        for (j = n - 1; j > i; j--)
            if (arr[j].val < arr[j - 1].val) {
                v = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = v;
            }
}


void
selectionSort(card arr[], int n)
{
    int i, j, min;
    card v;

    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++)
            if (arr[j].val < arr[min].val) {
                min = j;
            }
        v = arr[i];
        arr[i] = arr[min];
        arr[min] = v;
    }
}


void
print(card arr[], int n)
{
    int i = 0;
    printf("%c%d", arr[i].suit, arr[i].val);
    for (i++ ; i < n; i++)
        printf(" %c%d", arr[i].suit, arr[i].val);
    putchar('\n');
}

bool
compare(card c1[], card c2[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        if (c1[i].suit != c2[i].suit)
            return false;
    return true;
}
