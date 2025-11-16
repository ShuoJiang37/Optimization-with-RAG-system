#include <stdio.h>
#define M 37

typedef struct TT{
    char suit;
    int value;
}T;

int N;
T card_s[M],card_b[M];

void BubbleSort(void){
    int i;
    for(i=0;i<N;i++){
        for(int j=N-1;j>i;j--){
            if(card_b[j].value < card_b[j-1].value){
                int a;
                char b;
                a = card_b[j].value;
                card_b[j].value = card_b[j-1].value;
                card_b[j-1].value = a;
                b= card_b[j].suit;
                card_b[j].suit=card_b[j-1].suit;
                card_b[j-1].suit=b;
            }
        }
    }
}

void SelectionSort(void){
    int i,minj,j;
    for(i=0;i<N;i++){
        minj=i;
        for(j=i;j<N;j++){
            if(card_s[j].value < card_s[minj].value){
                minj=j;
            }
        }
        int a;
        char b;
        a=card_s[i].value;
        card_s[i].value=card_s[minj].value;
        card_s[minj].value=a;
        b=card_s[i].suit;
        card_s[i].suit=card_s[minj].suit;
        card_s[minj].suit=b;
    }
}

int main(void){
    int i,ct=0;
    char p;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%c%c%d",&p,&card_b[i].suit,&card_b[i].value);
        card_s[i].suit=card_b[i].suit;
        card_s[i].value = card_b[i].value;
    }
    BubbleSort();
    SelectionSort();
    for(i=0;i<N;i++){
        printf("%c%d",card_b[i].suit,card_b[i].value);
        if(i!=N-1)printf(" ");
    }
    printf("\nStable\n");

    for(i=0;i<N;i++){
        printf("%c%d",card_s[i].suit,card_s[i].value);
        if(i!=N-1)printf(" ");
    }
    for(i=0;i<N;i++){
        if(card_b[i].suit != card_s[i].suit){
            ct++;
        }
    }
    if(ct!=0)printf("\nNot stable\n");
    else printf("\nStable\n");
    return 0;
}

