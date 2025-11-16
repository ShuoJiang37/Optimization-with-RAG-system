#include<stdio.h>

int N;

typedef struct{
    char suit;
    int value;
}Card;

void swap(Card *A,Card *B){
    Card C;
    C=*A;
    *A=*B;
    *B=C;
}

void BubbleSort(Card C[],int N){
    int i,j;
    for(i=0;i<N;i++){
        for(j=N-1;j>=i+1;j--){
            if(C[j].value<C[j-1].value){
                swap(&C[j],&C[j-1]);
            }
        }
    }
    for(i=0;i<N;i++){
        printf("%c%d",C[i].suit,C[i].value);
        if(i!=N-1){
            printf(" ");
        }
    }
    printf("\nStable\n");
    
}

void SelectionSort(Card X[],int N){
    int i,j,minj;
    for(i=0;i<N;i++){
        minj=i;
        for(j=i;j<N;j++){
            if(X[j].value<X[minj].value){
                minj=j;
            }
        }
        swap(&X[i],&X[minj]);
    }
    for(i=0;i<N;i++){
        printf("%c%d",X[i].suit,X[i].value);
        if(i!=N-1){
            printf(" ");
        }
    }
    printf("\n");
}

void Judge(Card C[],Card X[]){
    int i;
    for(i=0;i<N;i++){
        if(X[i].value!=C[i].value || X[i].suit!=C[i].suit){
            printf("Not stable\n");
            return;
        }
    }
    printf("Stable\n");
}
int main(){
    Card C[36],X[36];
    int i;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf(" %c%d",&C[i].suit,&C[i].value);
        X[i]=C[i];
    }
    BubbleSort(C,N);
    SelectionSort(X,N);
    Judge(C,X);
    return 0;
}

