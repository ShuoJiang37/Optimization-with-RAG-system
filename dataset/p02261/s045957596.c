// 1_2_C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CARDSIZE 2

typedef struct {
    char suit;
    int num;
} card_t;

void Swap(card_t *card1, card_t *card2){
    card_t tmp;
    tmp = *card1;
    *card1 = *card2;
    *card2 = tmp;
    return;
}

void SetCard(card_t *card, char input[]){
    card->suit = input[0];
    card->num = atoi(&input[1]);
    return;
}

void PrintCards(card_t cards[], int length){
    int i;
    for(i = 0; i < length; i++){
        printf("%c", cards[i].suit);
        printf("%d", cards[i].num);
        if(i == length - 1){
            printf("\n");
        } else {
            printf(" ");
        }
    }
    return;
}

card_t *BubbleSort(card_t *cards, int length){
    int i, flag = 1;
    while(flag){
        flag = 0;
        for(i = length - 1; i >= 1; i--){
            if(cards[i].num < cards[i-1].num){
                Swap(&cards[i], &cards[i-1]);
                flag = 1;
            }
        }
    }
    PrintCards(cards, length);
    return cards;
}

card_t *SelectionSort(card_t *cards, int length){
    int i, j, minj;
    for(i = 0; i < length; i++){
        minj = i;
        for(j = i; j < length; j++){
            if(cards[j].num < cards[minj].num) minj = j;
        }
        Swap(&cards[minj], &cards[i]);
    }
    PrintCards(cards, length);
    return cards;
}

int main(){
    int n, i;
    char input[CARDSIZE + 1];
    card_t *cards_bub, *cards_sel;
    scanf("%d", &n);

    cards_bub = (card_t *)malloc(sizeof(card_t) * n);
    cards_sel = (card_t *)malloc(sizeof(card_t) * n);

    for(i = 0; i < n; i++){
        scanf("%s", input);
        SetCard(&cards_bub[i], input);
    }
    memcpy(cards_sel, cards_bub, sizeof(card_t) * n);

    cards_bub = BubbleSort(cards_bub, n);
    printf("Stable\n");
    cards_sel = SelectionSort(cards_sel, n);
    if(memcmp(cards_bub, cards_sel, sizeof(card_t) * n) == 0){
        printf("Stable\n");
    } else {
        printf("Not stable\n");
    }

    free(cards_bub);
    free(cards_sel);
    return 0;
}