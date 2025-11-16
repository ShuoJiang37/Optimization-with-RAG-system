// Stable sort
#include <stdio.h>
#include <stdbool.h>

typedef struct Card{
    char c;
    int value;
}Card;

void bubbleSort(Card C[], int N)
{
    int i, j;
    Card tmp;
    for(i=0; i<N; i++){
        for(j = N-1; j>i; j--){
            if(C[j].value < C[j-1].value){
                tmp = C[j];
                C[j] = C[j-1];
                C[j-1] = tmp;
            }
        }
    }
}

void selectionSort(Card C[], int N)
{
    int i, j, minj;
    Card tmp;
    for(i=0; i<N; i++){
        minj = i;
        for(j=i; j<N; j++){
            if(C[j].value < C[minj].value){
                minj = j;
            }
        }
        tmp = C[i];
        C[i] = C[minj];
        C[minj] = tmp;
    }
}

bool isStable(Card in[], Card out[], int N)
{
    int i;
    for(i=0; i<N; i++){
        if(!(in[i].c == out[i].c && in[i].value == out[i].value)){
            return false;
        }
    }
    return true;
}

int main(void)
{
    int N, i;
    scanf("%d%*c", &N);
    Card c1[N], c2[N];
    for(i=0; i<N; i++){
        scanf("%c%d%*c", &c1[i].c, &c1[i].value);
        c2[i] = c1[i];
    }
    bubbleSort(c1, N);
    selectionSort(c2, N);

    // bubble sortした構造体Cardの配列の表示
    for(i=0; i<N; i++){
        if(i==N-1){
            printf("%c%d\n", c1[i].c, c1[i].value);
        }else{
            printf("%c%d ",c1[i].c, c1[i].value);
        }
    }
    printf("Stable\n");

    // selection sortした構造体Cardの配列の表示と安定の判断を行う
    for(i=0; i<N; i++){
        if(i==N-1){
            printf("%c%d\n", c2[i].c, c2[i].value);
        }else{
            printf("%c%d ", c2[i].c, c2[i].value);
        }
    }
    if(isStable(c1, c2, N)){
        printf("Stable\n");
    }else{
        printf("Not stable\n");
    }
    
    return 0;
}
