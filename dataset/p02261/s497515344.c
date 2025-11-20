#include "stdlib.h"
#include "stdio.h"

struct card{
    char suit;
    int value;
};

int N;
struct card C1[100]; 
struct card C2[100];


void swapCard1(int i, int j){
    C1[i].suit = C1[i].suit ^ C1[j].suit;
    C1[j].suit = C1[i].suit ^ C1[j].suit;
    C1[i].suit = C1[i].suit ^ C1[j].suit;
    C1[i].value = C1[i].value ^ C1[j].value;
    C1[j].value = C1[i].value ^ C1[j].value;
    C1[i].value = C1[i].value ^ C1[j].value;
}

void swapCard2(int i, int j){
    C2[i].suit = C2[i].suit ^ C2[j].suit;
    C2[j].suit = C2[i].suit ^ C2[j].suit;
    C2[i].suit = C2[i].suit ^ C2[j].suit;
    C2[i].value = C2[i].value ^ C2[j].value;
    C2[j].value = C2[i].value ^ C2[j].value;
    C2[i].value = C2[i].value ^ C2[j].value;
}

void printCard1(){
    int i;
    for(i=0; i<N-1; i++){
        printf("%c%d ", C1[i].suit, C1[i].value);
    }
    printf("%c%d\n", C1[N-1].suit, C1[N-1].value);
}

void printCard2(){
    int i;
    for(i=0; i<N-1; i++){
        printf("%c%d ", C2[i].suit, C2[i].value);
    }
    printf("%c%d\n", C2[N-1].suit, C2[N-1].value);
}

int isStable(){
    int i;
    for(i=0; i<N; i++){
        if(C1[i].suit != C2[i].suit) return 0;
    }
    return 1;
}
void BubbleSort(){
    int i, j;
    for(i=0; i<N; i++){
        for(j=N-1; j>i; j--){
            if(C1[j].value < C1[j-1].value){
                swapCard1(j, j-1);
            }
        }
    }
}

void SelectionSort(){
    int i, j;
    int minIndex;
    for(i=0; i<N; i++){
        minIndex = i;
        for(j=i+1; j<N; j++){
            if(C2[j].value<C2[minIndex].value){
                minIndex = j;
            }
        }
        if(minIndex != i){
            swapCard2(i, minIndex);
        }
    }
}

int main(){
    //freopen("D:\\zhouyu\\study\\codes\\StableSort.txt", "r", stdin);
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        getchar();
        scanf("%c%d", &C1[i].suit, &C1[i].value);
        C2[i] = C1[i];
    }
    BubbleSort();
    printCard1();
    printf("Stable\n");
    SelectionSort();
    printCard2();
    int i;
    int flag = 1; 
    if(isStable()) printf("Stable\n");
    else printf("Not stable\n");
    return 0;
}
