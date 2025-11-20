#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 36


struct card{
    char suit[1]; //A, H, C, D
    int value; //1,2, ..., 9
};

void trace(struct card A[], int N){
    int i;
    for(i = 0; i < N; i++){
        if(i > 0) printf(" ");
        printf("%c%d", *A[i].suit, A[i].value);
    }
    printf("\n");
}

void BubbleSort(struct card A[], int N){
    int i,j,t1;
    char t2[1];
    for(i = 0; i < N; i++){
        for(j = N-1; j > i; j--){
            if( A[j].value < A[j-1].value){
                t1 = A[j].value;
                *t2 = *A[j].suit;
                A[j].value = A[j-1].value;
                *A[j].suit = *A[j-1].suit;
                A[j-1].value = t1;
                *A[j-1].suit = *t2;
            } 
            
        }

    }
}

void SelectionSort (struct card B[], int N ){
    int i,j,t1,min;
    char t2[1];
    for( i = 0; i < N; i++ ){
        
        min = i;
        
        for( j = i; j < N; j++ ){
            if( B[j].value < B[min].value) min = j;
        }

        t1 = B[min].value;
        *t2 = *B[min].suit;
        B[min].value = B[i].value;
        *B[min].suit = *B[i].suit;
        B[i].value = t1; 
        *B[i].suit = *t2; 

    }

}

bool isStable( struct card A[], struct card B[], int N ){
    for( int i = 0; i < N; i++){
        if( *A[i].suit != *B[i].suit ) return (false);
    }
    return (true);
}

int main(){

    struct card A[MAXSIZE], B[MAXSIZE];
    int N;
    int i;

    scanf("%d", &N);
    getchar();
    for( i = 0; i < N; i++ ){
        scanf("%c%d", A[i].suit, &A[i].value);
        getchar();
    }
    for( i = 0; i < N; i++ ){
        *B[i].suit = *A[i].suit;
        B[i].value = A[i].value;
    }

    BubbleSort(A, N);
    trace(A, N);
    printf("Stable\n");

    SelectionSort(B, N);
    trace(B, N);
    if(isStable(A, B, N)){
        printf("Stable\n");
    }else{
        printf("Not stable\n");
    }

    return 0;
}
