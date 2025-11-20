#include <stdio.h>

#define MAX 37

typedef struct TT{
    char s;
    int v;
}T;

int N;

T card_s[MAX],card_b[MAX];

void Bubble(void){
    int i,j,a;
    char b;

    for(i=0;i<N;i++){
        for(int j=N-1;j>i;j--){

            if(card_b[j].v < card_b[j-1].v){
               
                a = card_b[j].v;

                card_b[j].v = card_b[j-1].v;

                card_b[j-1].v = a;

                b= card_b[j].s;

                card_b[j].s=card_b[j-1].s;

                card_b[j-1].s=b;

            }
        }
    }
}

void Select(void){
    int i,minj,j,a;
    char b;

    for(i=0;i<N;i++){
        minj=i;
        for(j=i;j<N;j++){
            if(card_s[j].v< card_s[minj].v){
                minj=j;
            }
        }
       
        a=card_s[i].v;

        card_s[i].v=card_s[minj].v;

        card_s[minj].v=a;

        b=card_s[i].s;

        card_s[i].s=card_s[minj].s;

        card_s[minj].s=b;
    }
}

int main(void){
    int i,count=0;
    char p;

    scanf("%d",&N);

    for(i=0;i<N;i++){
        scanf("%c%c%d",&p,&card_b[i].s,&card_b[i].v);

        card_s[i].s=card_b[i].s;
        card_s[i].v= card_b[i].v;

    }

    Bubble();
    Select();

    for(i=0;i<N;i++){
        printf("%c%d",card_b[i].s,card_b[i].v);
        if(i!=N-1)
            printf(" ");
    }

    printf("\nStable\n");

    for(i=0;i<N;i++){
        printf("%c%d",card_s[i].s,card_s[i].v);
        if(i!=N-1)
            printf(" ");
    }
    for(i=0;i<N;i++){
        if(card_b[i].s != card_s[i].s){
            count++;
        }
    }
    if(count!=0)
        printf("\nNot stable\n");
    else
         printf("\nStable\n");

    return 0;
}


