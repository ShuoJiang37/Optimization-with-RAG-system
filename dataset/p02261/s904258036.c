#include<stdio.h>

typedef struct card{char suit; int value;}card;

void print(card A[],int N){
    int i;
    for(i=0;i<N;i++){
        if(i>0)printf(" ");
        printf("%c%d",A[i].suit,A[i].value);
    }
    printf("\n");
}

void bubble(card A[],int N){
    int i,j;
    for(i=0;i<N;i++){
        for(j=N-1;j>i;j--){
            if(A[j].value<A[j-1].value){
                card t=A[j];
                A[j]=A[j-1];
                A[j-1]=t;
            }
        }
    }
    print(A,N);
    printf("Stable\n");
}

void selection(card A[],int N){
    int i,j,minj;
    for(i=0;i<N;i++){
        minj=i;
        for(j=i;j<N;j++){
            if(A[j].value<A[minj].value) minj=j;
        }
        card t=A[i];
        A[i]=A[minj];
        A[minj]=t;
    }
    print(A,N);
}



int isstable(card C1[],card C2[],int N){
    int i;
    for(i=0;i<N;i++){
        if(C1[i].suit!=C2[i].suit)return 0;
    }
    return 1;
}

int main(){
    int n,i;
    card C1[100], C2[100];

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf(" %c%d",&C1[i].suit,&C1[i].value);
        C2[i]=C1[i];
    }

    bubble(C1,n);
    selection(C2,n);
    
    for(i=0;i<n;i++){
        if(C1[i].suit!=C2[i].suit)break;
    }
    
    if(isstable(C1,C2,n)==1) printf("Stable\n");
    else printf("Not stable\n");    
    
    return 0;
}



