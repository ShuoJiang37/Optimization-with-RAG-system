#include <stdio.h>

#define FALSE 1
#define TRUE 0
#define MAX 36

typedef struct {
    char s;
    int value;
} T;


void print(T C[],int N){
    int i;
    for(i=0;i<N;i++){
        printf("%c%d",C[i].s,C[i].value);
        if(i!=N-1) printf(" ");
        else printf("\n");
    }
}


void Bubble(T C[],int N){
    int i,j;
    T t;
    
    for(i=0;i<N;i++){
        for(j=N-1;j>i;j--){
            if(C[j].value<C[j-1].value){
                t=C[j];
                C[j]=C[j-1];
                C[j-1]=t;
            }
        }
    }
    print(C,N);
    printf("Stable\n");
}

void Select(T C[],int N){
    int i,j;
    int minj;
    T t;
    
    for(i=0;i<N;i++){
        minj=i;
        for(j=i;j<N;j++){
            if(C[j].value<C[minj].value) minj=j;
        }
        t=C[i];
        C[i]=C[minj];
        C[minj]=t;
    }
    print(C,N);
}

int Stable(T A[],T B[],int N){
    int i;
    for(i=0;i<N;i++){
        if(A[i].s!=B[i].s) return FALSE;
    }
    return TRUE;
}

int main(){
    int n;
    int i;
    T A[MAX],B[MAX];

    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        scanf(" %c%d",&A[i].s,&A[i].value);
        B[i]=A[i];
    }
    
    Bubble(A,n);
    Select(B,n);
    
    for(i=0;i<n;i++){
        if(A[i].s!=B[i].s)break;
    }
    
    if(Stable(A,B,n)==TRUE) printf("Stable\n");
    else printf("Not stable\n");    
    
    return 0;
}

