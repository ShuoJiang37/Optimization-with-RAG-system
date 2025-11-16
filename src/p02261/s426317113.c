#include <stdio.h>


typedef struct {
    char ch;
    char value;
} Card;

Card C1[37], C2[37];

void bubble(int);
void select(int);
void swap(Card *, Card *);

//main
int main(void){ 

    int n, i;
    char ch;
    scanf("%d%c", &n, &ch);
    for (i = 0; i < n; i++) {
        scanf("%c%c%c", &C1[i].ch, &C1[i].value, &ch);
    }

    // 配列コピー
    for (i = 0; i < n; i++) {
        C2[i].ch = C1[i].ch;
        C2[i].value= C1[i].value;
    }

    bubble(n);
    select(n);

    return 0;
}


void swap(Card *x, Card *y){
    Card temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void bubble(int n){

    int i, j;

    //sort
    for (i = 0; i < n-1; i++) {
        for (j = n-1; j > 0 ; j--) {
            if(C1[j].value < C1[j-1].value) swap(&C1[j], &C1[j-1]);
        }
    }

    // print
    for (i = 0; i < n; i++) {
        printf("%c%c", C1[i].ch, C1[i].value);
        if(i < n-1) printf(" ");
    }
    printf("\n");
    printf("Stable\n");
}

void select(int n){

    int min, i, j, cnt = 0;

    // sort
    for (i = 0; i < n-1; i++) {
        min = i;
        for (j = i; j < n; j++) {
            if(C2[j].value < C2[min].value) min = j;
        }
        swap(&C2[i], &C2[min]);
    }

    // print
    for (i = 0; i < n; i++) {
        printf("%c%c", C2[i].ch, C2[i].value);
        if(i < n-1) printf(" ");
    }
    printf("\n");

    // IsStable
    for (i = 0; i < n; i++) {
        if(C2[i].value == C1[i].value && C2[i].ch == C1[i].ch)
            cnt++;
    }
    if(n == cnt) printf("Stable\n");
    else printf("Not stable\n");
}