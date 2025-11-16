#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 36

int isStable(char[][max],char[][max],int);
void selectionSort(char[][max],int);
void bubbleSort(char[][max],int);

int main(){
    char cards[max][max];
    char bubble[max][max];
    char selection[max][max];
    int n;

    scanf("%d",&n);

    for(int i = 0;i < n;i++){
        scanf("%s",cards[i]);
        strcpy(bubble[i],cards[i]);
        strcpy(selection[i],cards[i]);
    }

    bubbleSort(bubble,n);
    for(int i = 0;i < n;i++){
        printf("%s",bubble[i]);
        if(i < n-1)printf(" ");
    }
    printf("\n");
    if(isStable(cards,bubble,n) == 1)printf("Stable\n");
    else printf("Not stable\n");

    selectionSort(selection,n);
    for(int i = 0;i < n;i++){
        printf("%s",selection[i]);
        if(i < n-1)printf(" ");
    }
    printf("\n");
    if(isStable(cards,selection,n) == 1)printf("Stable\n");
    else printf("Not stable\n");

    return 0;
}

int isStable(char in[][max],char out[][max],int n){
    for(int i = 0;i < n;i++){
        for(int j = i + 1;j < n;j++){
            for(int a = 0;a < n;a++){
                for(int b = a+1;b < n;b++){
                    if(in[i][1] == in[j][1] && strcmp(in[i],out[b]) == 0 && strcmp(in[j],out[a]) == 0)return 0;
                }
            }
        }
    }
    return 1;
} 

void selectionSort(char cards[][max],int n){
    int minj;
    char tmp[max];
    int count = 0;
    int flag;

    for(int i = 0;i < n;i++){
        minj = i;
        flag = 0;
        for(int j = i;j < n;j++){
            if(atoi(&cards[j][1])< atoi(&cards[minj][1])){
                minj = j;
                flag = 1;
            }
        }
        if(flag == 1){
            strcpy(tmp,cards[minj]);
            strcpy(cards[minj],cards[i]);
            strcpy(cards[i],tmp);
        }
    }
}

void bubbleSort(char cards[][max],int n){
    char tmp[max];
    int i = 0;
    int flag = 1;
    while(flag){
        flag = 0;
        for(int j = n-1;j > i;j--){
            if(atoi(&cards[j][1]) < atoi(&cards[j-1][1])){
                strcpy(tmp,cards[j]);
                strcpy(cards[j],cards[j-1]);
                strcpy(cards[j-1],tmp);
                flag = 1;
            }
        }
        i++;
    }
}

