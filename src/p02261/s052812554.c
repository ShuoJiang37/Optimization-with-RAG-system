#include <stdio.h>
#include <stdbool.h>
 
typedef struct {
    char suit;
    int num;
} card;
 
void BubbleSort(int n, card cards[]);
void SelectionSort(int n, card cards[]);
void swap(card *one, card *another);
bool judge_stable(int n, card cards01[], card cards02[]);
 
int main(void)
{
    int i;
 
    int n;
    scanf("%d", &n);
 
    card cards01[36], cards02[36];
    for (i = 0; i < n; i++) {
        scanf(" %c%d", &cards01[i].suit, &cards01[i].num);
        cards02[i] = cards01[i];
    }
 
    BubbleSort(n, cards01);
    for (i = 0; i < n; i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%c%d", cards01[i].suit, cards01[i].num);
    }
    printf("\n");
    printf("Stable\n");
 
    SelectionSort(n, cards02);
    for (i = 0; i < n; i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%c%d", cards02[i].suit, cards02[i].num);
    }
    printf("\n");
    bool isStable = judge_stable(n, cards01, cards02);
    if (isStable) {
        printf("Stable\n");
    } else {
        printf("Not stable\n");
    }
 
    return 0;
}
 
void BubbleSort(int n, card cards[])
{
    int i, j;
 
    for (i = 0; i < n; i++) {
        for (j = n - 1; j > i; j--) {
            if (cards[j].num < cards[j - 1].num) {
                swap(&cards[j], &cards[j - 1]);
            }
        }
    }
}
 
void SelectionSort(int n, card cards[])
{
    int i, j;
    int min;
 
    for (i = 0; i < n; i++) {
        min = i;
        for (j = i; j < n; j++) {
            if (cards[j].num < cards[min].num) {
                min = j;
            }
        }
        swap(&cards[i], &cards[min]);
    }
}
 
void swap(card *one, card *another)
{
    card tmp = *one;
    *one = *another;
    *another = tmp;
}
 
bool judge_stable(int n, card cards01[], card cards02[])
{
    int i;
    for (i = 0; i < n; i++) {
        if (cards02[i].suit != cards01[i].suit) {
            return false;
        }
    }
    return true;
}