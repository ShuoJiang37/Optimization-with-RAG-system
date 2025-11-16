#include <stdio.h>

typedef struct {
    char type;
    int num;
} card_t;

int
main(void)
{
    char flag;
    int i, j, N, minj;
    card_t cards1[36], cards2[36], cards3[36], tmp;
    
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf(" %c%d", &cards1[i].type, &cards1[i].num);
        cards2[i] = cards1[i];
        cards3[i] = cards1[i];
    }
    
    //bubble sort is stable
    flag = 1;
    while(flag) {
        flag = 0;
        for(i = N - 1; i > 0; --i) {
            if(cards3[i].num < cards3[i-1].num) {
                tmp = cards3[i];
                cards3[i] = cards3[i-1];
                cards3[i-1] = tmp;
                flag = 1;
            }
        }
    }
    
    for(i = 0; i < N; ++i) {
        for(j = N - 1; j > i; --j) {
            if(cards1[j].num < cards1[j-1].num) {
                tmp = cards1[j];
                cards1[j] = cards1[j-1];
                cards1[j-1] = tmp;
            }
        }
    }
    
    flag = 0;
    for(i = 0; i < N; ++i) {
        if(cards1[i].type != cards3[i].type) flag = 1;
        if(i != N - 1) printf("%c%d ", cards1[i].type, cards1[i].num);
        else printf("%c%d\n", cards1[i].type, cards1[i].num);
    }
    if(flag) printf("Not stable\n");
    else printf("Stable\n");

    
    for(i = 0; i < N; ++i) {
        minj = i;
        for(j = i; j < N; ++j) {
            if(cards2[j].num < cards2[minj].num)
                minj = j;
        }
        tmp = cards2[i];
        cards2[i] = cards2[minj];
        cards2[minj] = tmp;
    }
  
    flag = 0;
    for(i = 0; i < N; ++i) {
        if(cards2[i].type != cards3[i].type) flag = 1;
        if(i != N - 1) printf("%c%d ", cards2[i].type, cards2[i].num);
        else printf("%c%d\n", cards2[i].type, cards2[i].num);
    }
    if(flag) printf("Not stable\n");
    else printf("Stable\n");
}

