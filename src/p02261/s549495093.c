#include <stdio.h>

typedef struct{
    char suit;
    int value;
}   CARD;

void bubbleSort(CARD *);
void selectionSort(CARD *);
int isStable(CARD *, CARD *);
void printcard(CARD *);
void swap(CARD *, CARD *);

int n;

int main(){
    CARD card[36], b_card[36], s_card[36];
    int a;
    scanf("%d",&n);
    for(a = 0; a < n; a++){
        scanf(" %c%d",&card[a].suit,&card[a].value);
        b_card[a] = s_card[a] = card[a];
    }

    bubbleSort(b_card);
    selectionSort(s_card);

    printcard(b_card);
    if(isStable(card,b_card) == 1) printf("Stable\n");
    else printf("Not stable\n");
    printcard(s_card);
    if(isStable(card,s_card) == 1) printf("Stable\n");
    else printf("Not stable\n");

    return 0;
}

void bubbleSort(CARD *c){
    int a, b;
    for(a = 0; a < n; a++){
        for(b = n-1; b > a; b--){
            if(c[b].value < c[b-1].value) swap(&c[b],&c[b-1]);
        }
    }
}

void selectionSort(CARD *c){
    int a, b, min;
    for(a = 0; a < n; a++){
        min = a;
        for(b = a; b < n; b++){
            if(c[b].value < c[min].value) min = b;
        }
        swap(&c[a],&c[min]);
    }
}

int isStable(CARD *in, CARD *out){
    int a, b, i, j;
    for(i = 0; i < n; i++){
        for(j = i+1; j < n; j++){
            for(a = 0; a < n; a++){
                for(b = a+1; b < n; b++){
                    if(in[i].value == in[j].value){
                        if(in[i].suit == out[b].suit && in[j].suit == out[a].suit &&
                           in[i].value == out[b].value && in[j].value == out[a].value) return 0;
                    }
                }
            }
        }
    }
    return 1;
}

void printcard(CARD *c){
    int a;
    for(a = 0; a < n-1; a++){
        printf("%c%d ",c[a].suit,c[a].value);
    }
    printf("%c%d\n",c[a].suit,c[a].value);
}

void swap(CARD *x, CARD *y){
    CARD temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
