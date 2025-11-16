#include<stdio.h>

/*構造体の定義*/
typedef struct {
	char suit;
	int value;
} Card ;


void swap_Card(Card *x, Card *y)
{
	Card temp = *x;
	*x = *y;
	*y = temp;
}


int main()
{
	int N;
	scanf("%d\n", &N);

	int i,j;
	Card BC[36];
	Card SC[36];

	for (i = 0; i < N; i++) {
		Card c;
		scanf("%c", &c.suit);
		scanf("%d ", &c.value);
		BC[i] = c;
		SC[i] = c;
	}

	/* Bubble Sort */
    for (i = 0; i < N - 1; i++) {
        for (j = N - 1; j > i; j--) {
            if (BC[j].value < BC[j - 1].value)
                swap_Card(&BC[j], &BC[j - 1]);
        }
    }
	
	/* Selection Sort */
    for (i = 0; i < N - 1; i++) {
        int minj = i;
        for (j = i + 1; j < N; j++) {
            if (SC[j].value < SC[minj].value)
                minj = j;
        }
        swap_Card(&SC[i], &SC[minj]);
    }
	
	/* Output */
	for (i = 0; i < N - 1; i++) {
		printf("%c%d ", BC[i].suit, BC[i].value);
	}
	printf("%c%d\n", BC[N - 1].suit, BC[N - 1].value);
	puts("Stable");

	for (i = 0; i < N - 1; i++) {
		printf("%c%d ", SC[i].suit, SC[i].value);
	}
	printf("%c%d\n", SC[N - 1].suit, SC[N - 1].value);

	for (i = 0; i < N; i++) {
		if (BC[i].suit != SC[i].suit) {
			puts("Not stable");
			return 0;
		}
	}
	puts("Stable");

	return 0;
}
