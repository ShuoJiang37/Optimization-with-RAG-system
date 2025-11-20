#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n,minj;

typedef struct card{
    char mark;
    int num;
}card;

card C[36], D[36], tmp;

void bubble_sort(card C[]){
    for(int i=0 ; i<n ; i++){
        for(int j=n-1 ; j>i ; j--){
            if(C[j].num<C[j-1].num){
                tmp = C[j], C[j] = C[j-1], 
                C[j-1] = tmp;
            }
        }
    }
}

void select_sort(card C[]){
    for(int i=0 ; i<n-1 ; i++){
        minj=i;
        for(int j=i ; j<n ; j++)
            if(C[j].num<C[minj].num) minj=j;
        tmp=C[i], C[i]=C[minj] , C[minj]=tmp;
    }
}

void print(card C[]){
    for(int i=0 ; i<n ; i++)
        if(i==n-1)    printf("%c%d\n",C[i].mark,C[i].num);
        else          printf("%c%d ", C[i].mark, C[i].num);
}

void stable_check(card C[], card D[]){
    for(int i=0 ; i<n ; i++){
        if(C[i].num!=D[i].num || C[i].mark!=D[i].mark){
            printf("Not stable\n");
            break;
        }
        if(i==n-1)
            printf("Stable\n");
    }
}

int main(void){
    
     scanf("%d",&n);
     for(int i=0 ; i<n ; i++){
        scanf(" %c%d",&C[i].mark, &C[i].num);
        D[i]=C[i];
     }
    
    bubble_sort(C);
    select_sort(D);

    print(C);
    printf("Stable\n"); //バブルソートは安定
    print(D);
    stable_check(C, D);

    return 0; 
}
