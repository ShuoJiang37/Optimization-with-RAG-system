#include <stdio.h>

typedef struct {
    char suit;
    int number;
} Card;

void swap_Card(Card *x, Card *y)
{
    Card temp = *x;
    *x = *y;
    *y = temp;
}

int main(void)
{
    int N;
    scanf("%d\n", &N);

    int i;
    Card BC[N];
    Card SC[N];

    for (i = 0; i < N; i++) {
        Card c;
        scanf("%c", &c.suit);
        scanf("%d ", &c.number);
        BC[i] = c;
        SC[i] = c;
    }

    int j;

    for (i = 0; i < N - 1; i++) {
        for (j = N - 1; j > i; j--) {
            if (BC[j].number < BC[j - 1].number)
                swap_Card(&BC[j], &BC[j - 1]);
        }
    }

    for (i = 0; i < N - 1; i++) {
        int min_i = i;
        for (j = i + 1; j < N; j++) {
            if (SC[j].number < SC[min_i].number)
                min_i = j;
        }
        swap_Card(&SC[i], &SC[min_i]);
    }

    for (i = 0; i < N - 1; i++)
        printf("%c%d ", BC[i].suit, BC[i].number);
    printf("%c%d\n", BC[N - 1].suit, BC[N - 1].number);

    puts("Stable");

    for (i = 0; i < N - 1; i++)
        printf("%c%d ", SC[i].suit, SC[i].number);
    printf("%c%d\n", SC[N - 1].suit, SC[N - 1].number);

    for (i = 0; i < N; i++) {
        if (BC[i].suit != SC[i].suit) {
            puts("Not stable");
            return 0;
        }
    }
    puts("Stable");

    return 0;
}

