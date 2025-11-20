#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>

typedef struct{
    uint8_t suit ;
    uint8_t value;
} card_s;

void swap_card(card_s *c1, card_s *c2)
{
    card_s tmp = *c1;
    *c1        = *c2;
    *c2        = tmp;
}

void bubble_sort_card(card_s *c, uint8_t n)
{
    for(uint8_t i=0; i<n-1; ++i)
        for(uint8_t j=n-1; j>i; --j)
            if(c[j].value < c[j-1].value)
                swap_card(&c[j], &c[j-1]);
}

void selection_sort_card(card_s *c, uint8_t n)
{
    for(uint8_t i=0; i<n; ++i){
        uint8_t minj = i;
        for(uint8_t j=i+1; j<n; ++j)
            if(c[j].value < c[minj].value)
                minj = j;
        if(minj != i)
            swap_card(&c[i], &c[minj]);
    }
}

void print_card_array(card_s *c, uint8_t n)
{
    printf("%c%"PRIu8, c[0].suit, c[0].value);
    for(uint8_t i=1; i<n; ++i)
        printf(" %c%"PRIu8, c[i].suit, c[i].value);
    printf("\n");
}

uint8_t card_array_is_same(card_s *c1, card_s *c2, uint8_t n)
{
    for(uint8_t i=0; i<n; ++i){
        if(c1[i].suit != c2[i].suit)
            return 0;
        if(c1[i].value != c2[i].value)
            return 0;
    }
    return 1;
}

int main()
{
    uint8_t n;
    scanf("%"PRIu8, &n);

    card_s c[n];
    scanf("\n%c%"PRIu8, &c[0].suit, &c[0].value);
    for(uint8_t i=1; i<n; ++i)
        scanf(" %c%"PRIu8, &c[i].suit, &c[i].value);

    card_s c_bubble[n], c_selection[n];
    for(uint8_t i=0; i<n; ++i){
        c_bubble[i] = c_selection[i] = c[i];
    }
    bubble_sort_card   (c_bubble   , n);
    selection_sort_card(c_selection, n);

    print_card_array(c_bubble   , n);
    printf("Stable\n");
    print_card_array(c_selection, n);
    if(card_array_is_same(c_bubble, c_selection, n)){
        printf("Stable\n");
    }else{
        printf("Not stable\n");
    }

    return 0;
}