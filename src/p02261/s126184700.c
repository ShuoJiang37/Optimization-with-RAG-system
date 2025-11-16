#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


typedef struct CARD{
    int num;
    char var;
}CARD;

void BubbleSort(CARD array[], int first, int last){
    
    int i ,j, N;
    CARD tmp;
    
    N = last - first + 1;
    
    for(i=0; i < N; i++){
        for(j = N-1; j > i; j--) {
            if (array[j-1].num > array[j].num) {
                tmp = array[j];
                array[j] = array[j-1];
                array[j-1] = tmp;
            }
        }
    }
    return;
}

void SelectionSort(CARD array[], int first, int last, int* flg){
    
    int i ,j, k,N, mini;
    CARD tmp;
    
    N = last - first + 1;
    
    for(i=0; i < N; i++){
        mini = i;
        for(j=i; j < N; j++) {
            if (array[j].num < array[mini].num) {
                mini = j;
            }
        }
        k=i;
        tmp = array[k];
        for (k=i+1; k < mini; k++) {
            if (tmp.num == array[k].num) {
                *flg = 1;
                break;
            }
        }
        
        tmp = array[i];
        array[i] = array[mini];
        array[mini] = tmp;
    }
    
    return;
}

int main(){
    
    int i,n,flg;
    char input[2];
    flg = 0;
    
    //the number of cards
    scanf("%d",&n);
    
    CARD *cards1 = (CARD*)malloc(sizeof(CARD)*n);
    CARD *cards2 = (CARD*)malloc(sizeof(CARD)*n);
    
    for (i=0; i<n; i++) {
        scanf("%s", input);
        cards1[i].var = input[0];
        cards1[i].num = atoi(&(input[1]));
    }
    memcpy(cards2, cards1, sizeof(CARD) * n);
    
    
    BubbleSort(cards1, 0, n-1);
    for (i=0; i<n; i++) {
        printf("%c%d", cards1[i].var, cards1[i].num);
        if (i != n-1) {
            printf(" ");
        }
    }
    printf("\n");
    printf("Stable\n");
    
    SelectionSort(cards2, 0, n-1, &flg);
    for (i=0; i<n; i++) {
        printf("%c%d", cards2[i].var, cards2[i].num);
        if (i != n-1) {
            printf(" ");
        }
    }
    printf("\n");
    if (flg == 1) {
        printf("Not stable\n");
    }else{
        printf("Stable\n");
    }
    
    free(cards1);
    free(cards2);
    
    return 0;
}