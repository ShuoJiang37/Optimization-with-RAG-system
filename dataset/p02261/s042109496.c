#include <stdio.h>

#define FALSE 1
#define TRUE 0
#define MAX 36

typedef struct {
    char suit;
    int value;
} Card;


void print(Card C[],int N){
    int i;
    for(i=0;i<N;i++){
        printf("%c%d",C[i].suit,C[i].value);
        if(i!=N-1) printf(" ");
        else printf("\n");
    }
}


void Bubble(Card C[],int N){
    int i,j;
    Card tmp;
    
    for(i=0;i<N;i++){
        for(j=N-1;j>i;j--){
            if(C[j].value<C[j-1].value){
                tmp=C[j];
                C[j]=C[j-1];
                C[j-1]=tmp;
            }
        }
    }
    print(C,N);
    printf("Stable\n");
}

void Select(Card C[],int N){
    int i,j;
    int minj;
    Card tmp;
    
    for(i=0;i<N;i++){
        minj=i;
        for(j=i;j<N;j++){
            if(C[j].value<C[minj].value) minj=j;
        }
        tmp=C[i];
        C[i]=C[minj];
        C[minj]=tmp;
    }
    print(C,N);
}

int isStable(Card A[],Card B[],int N){
    int i;
    for(i=0;i<N;i++){
        if(A[i].suit!=B[i].suit) return FALSE;
    }
    return TRUE;
}

int main(){
    int n;
    int i;
    Card A[MAX],B[MAX];

    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        scanf(" %c%d",&A[i].suit,&A[i].value);
        B[i]=A[i];
    }
    
    Bubble(A,n);
    Select(B,n);
    
    for(i=0;i<n;i++){
        if(A[i].suit!=B[i].suit)break;
    }
    
    if(isStable(A,B,n)==TRUE) printf("Stable\n");
    else printf("Not stable\n");    
    
    return 0;
}


