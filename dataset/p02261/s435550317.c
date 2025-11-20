#include <stdio.h>
struct Card{
    char c,n;
};
void BubbleSort(struct Card *A,int N){
    int i,j;
    struct Card v;
    for(i=0;i<N-1;i++){
        for(j=N-1;j>i;j--){
            if(A[j].n < A[j-1].n){
                v = A[j];
                A[j] = A[j-1];
                A[j-1] = v;
            }
        }
    }
}
void SelectionSort(struct Card *A,int N){
    int i,j,min;
    struct Card v;
    for(i=0;i<N;i++){
        min = i;
        for(j=i;j<N;j++){
            if(A[min].n > A[j].n){
                min = j;
            }
        }
        v = A[min];
        A[min] = A[i];
        A[i] = v;
    }
}
void print(struct Card *A,int N){
    int i;
    for(i=0;i<N;i++){
        if(i>0) printf(" ");
        printf("%c%c",A[i].c,A[i].n);
    }
    printf("\n");
}
int isStable(struct Card *A1,struct Card *A2,int N){
    int i;
    for(i=0;i<N;i++){
        if(A1[i].c != A2[i].c) return 1;
    }
    return 0;
}
int main(void){
    struct Card C1[100],C2[100];
    int N;
    int i;
    
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf(" %c %c",&C1[i].c,&C1[i].n);
        //printf("%c%c\n",C1[i].c,C1[i].n);
        C2[i] = C1[i];
    }
    BubbleSort(C1,N);
    SelectionSort(C2,N);
    
    print(C1,N);
    printf("Stable\n");
    print(C2,N);
    if(isStable(C1,C2,N) == 1){
        printf("Not stable\n");
    }else printf("Stable\n");
    return 0;
}

