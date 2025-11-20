#include <stdio.h>
#include <string.h>
#define CARDS 36
#define SUIT 4
#define NUMBER 9

void BubbleSort( char cards[CARDS][3], int N){
    int i,j,k;
    int tmp;

    for(i = 0; i < N;i++){
        for(j = N - 1;j > i;j--){
            if(strcmp( &cards[j][1], &cards[j-1][1]) < 0){
                for(k = 0;k < 2;k++){
                    tmp = cards[j-1][k];
                    cards[j-1][k] = cards[j][k];
                    cards[j][k] = tmp;
                }
            }
        }
    }

    for(i = 0; i < N - 1;i++){
        printf("%c%c ", cards[i][0], cards[i][1]);
    }
    printf("%c%c\n", cards[N -1][0], cards[N - 1][1]);

    return;
}

void SelectionSort( char cards[CARDS][3], int N){
    int i,j,k;
    int mini;
    char tmp;

    for(i = 0; i < N - 1;i++){
        mini = i;
        for(j = i + 1;j < N;j++){
            if(strcmp( &cards[j][1], &cards[mini][1]) < 0){
                mini = j;
            }
        }
        for(k = 0;k < 2;k++){
            tmp = cards[mini][k];
            cards[mini][k] = cards[i][k];
            cards[i][k] = tmp;
        }
    }

    for(i = 0; i < N - 1;i++){
        printf("%c%c ", cards[i][0], cards[i][1]);
    }
    printf("%c%c\n", cards[N -1][0], cards[N - 1][1]);

    return;
}

void Checker( char cards[CARDS][3], char check[NUMBER][SUIT+1], int N){
    int i,j,num = 0;
    for(i = 0;i < N;i++){
        num = cards[i][1] - '0';
        for(j = 0;j < 4;j++){
            if(check[num-1][j] == '\0'){
                check[num-1][j] = cards[i][0];
                break;
            }
        }
    }
}

void StableChecker(char SortCheck[NUMBER][SUIT+1],char check[NUMBER][SUIT+1]){
    int i,j,stable_cnt = 0;

    for(i = 0;i < NUMBER;i++){
        for(j = 0;j < SUIT;j++){
            if(SortCheck[i][j] != check[i][j]){
                stable_cnt++;
            }
        }
    }
    if(stable_cnt == 0){
        printf("Stable\n");
    }else{
        printf("Not stable\n");
    }

}
int main(void){
    int N,i,j,num = 0;
    char cards[CARDS][3];
    char Bubble[CARDS][3];
    char Selection[CARDS][3];

    char check[NUMBER][SUIT+1] = {0};
    char Bubblecheck[NUMBER][SUIT+1] = {0};
    char Selectioncheck[NUMBER][SUIT+1] = {0};

    scanf("%d" ,&N);

    for(i = 0;i < N;i++){
        scanf("%s", cards[i]);
    }

    /*copy array*/
    memcpy(Bubble,cards,sizeof cards);
    memcpy(Selection,cards,sizeof cards);

    Checker(cards,check,N);

    BubbleSort(Bubble,N);
    Checker(Bubble,Bubblecheck,N);
    StableChecker(Bubblecheck,check);

    SelectionSort(Selection,N);
    Checker(Selection,Selectioncheck,N);
    StableChecker(Selectioncheck,check);

    return 0;
}