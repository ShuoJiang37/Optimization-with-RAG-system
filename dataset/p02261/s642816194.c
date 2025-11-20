#include <stdio.h>

#define FALSE 1
#define TRUE 0

typedef struct {
    char pic;
    int num;
} Card;

void print(Card C[],int N){
    int i;
    for(i=0;i<N;i++){
        printf("%c%d",C[i].pic,C[i].num);
        if(i!=N-1){
            printf(" ");
        }
        else{
            printf("\n");
        }
    }
}

void BubbleSort(Card C[],int N){
    int i,j;
    Card tmp;
    
    for(i=0;i<N;i++){
        for(j=N-1;j>i;j--){
            if(C[j].num<C[j-1].num){
                tmp=C[j];
                C[j]=C[j-1];
                C[j-1]=tmp;
            }
        }
    }
    print(C,N);
    printf("Stable\n");
}

void SelectionSort(Card C[],int N){
    int i,j;
    int minj;
    Card temp;
    
    for(i=0;i<N;i++){
        minj=i;
        for(j=i;j<N;j++){
            if(C[j].num<C[minj].num)minj=j;
        }
        temp=C[i];
        C[i]=C[minj];
        C[minj]=temp;
    }
    print(C,N);
}

int isStable(Card C1[],Card C2[],int N){
    int i;
    for(i=0;i<N;i++){
        if(C1[i].pic!=C2[i].pic){
            return FALSE;
        }
    }
    return TRUE;
}

int main(){
    int N;
    int i;
    Card C1[36],C2[36];//1はバブルソートで、2が選択ソート

    scanf("%d",&N);
    
    for(i=0;i<N;i++){
        scanf(" %c%d",&C1[i].pic,&C1[i].num);
        C2[i]=C1[i];
        }
    
    BubbleSort(C1,N);
    SelectionSort(C2,N);
    
    for(i=0;i<N;i++){
     if(C1[i].pic!=C2[i].pic){
         break;
     }   
    }
    
    if(isStable(C1,C2,N)==TRUE)
        printf("Stable\n");
    else
        printf("Not stable\n");    
    return 0;
}

