#include <stdio.h>
#include <string.h>

typedef struct ray{
    char value[3];
}Ray;

void BubbleSort(Ray *C, int N){
    int i, j;
    Ray temp;
    for(i = 0; i < N; i++){
        for(j = N-1; j > i; j--){
            if(C[j].value[1] < C[j-1].value[1]){
                temp = C[j];
                C[j] = C[j-1];
                C[j-1] = temp;
            }
        }
    }
    for(i = 0; i < N-1; i++) printf("%s ", C[i].value);
    printf("%s\nStable\n", C[i].value);
}

void SelectionSort(Ray *D, int N){
    int i, j, minj;
    Ray temp;
    for(i = 0; i < N; i++){
        minj = i;
        for(j = i; j < N; j++){
            if(D[j].value[1] < D[minj].value[1]) minj = j;
        }
        temp = D[i];
        D[i] = D[minj];
        D[minj] = temp;
    }
    for(i = 0; i < N-1; i++) printf("%s ", D[i].value);
    printf("%s\n", D[i].value);
}

void compare(Ray *C, Ray *D, int N){
    int i;
    for(i = 0; i < N; i++){
        if(strcmp(C[i].value, D[i].value) != 0){
            printf("Not stable\n");
            return ;
        }
    }
    printf("Stable\n");
    return ;
}

int main(){
    int i, j, N;
    Ray C[36], D[36];
    scanf("%d", &N);
    for(i = 0; i < N; i++){
        scanf("%s", C[i].value);
        strcpy(D[i].value, C[i].value);
    } 
    BubbleSort(C, N);
    SelectionSort(D, N);
    compare(C, D, N);
    return 0;
}

