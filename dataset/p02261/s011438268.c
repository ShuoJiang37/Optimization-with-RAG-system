#include <stdio.h>
#define false 0
#define true 1

typedef struct cc{
    char mark;
    char num;
} Card;

void bubble(Card C[], int N){
    int i, j;
    Card card_tmp; 
    for ( i = 0; i < N; i++) {
        for ( j = N-1; j >= i; j--){
            if (C[j].num < C[j-1].num){
                card_tmp = C[j];
                C[j] = C[j-1];
                C[j-1]= card_tmp;
            }
        }
    }
}

void selection (Card C[], int N) {
    int i, j;
    int minj;
    Card card_tmp;
    for ( i = 0; i < N; i++) {
        minj = i;
        for  ( j = i; j < N; j++) {
            if (C[j].num < C[minj].num) minj = j;
        }
        card_tmp = C[i];
        C[i] = C[minj];
        C[minj]= card_tmp;
    }
}

int isStable (Card in[], Card out[], int N) {
    int i;
    for ( i = 0; i < N; i++) {
        if (in[i].mark != out[i].mark) return false;
    }
    return true;
}

void output (Card C[], int N) {
    int i;
    for ( i = 0; i < N; i++) {
        printf("%c%c",C[i].mark,C[i].num);
        if(i == N-1)printf("\n");
        else printf(" ");
    }
}

int main(){
    int N;
    int i;
    char trash;
    Card A[100], B[100];
    
    scanf("%d\n",&N);
    for(i=0; i < N; i++) scanf("%c%c%c",&A[i].mark,&A[i].num,&trash);
    
    for (i = 0; i < N; i++) B[i] = A[i];

    bubble(A, N);
    selection(B, N);

    output(A,N);
    printf("Stable\n");
    
    
    
    output(B,N);
    if(isStable(A, B, N) == true)printf("Stable\n");
    else printf("Not stable\n");
    
    return 0;
}

