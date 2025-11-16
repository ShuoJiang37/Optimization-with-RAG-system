#include<stdio.h>
#define N_MAX 40
 
typedef struct data
{
    int value;
    char mark;
}Data;
 
Data C[N_MAX], C1[N_MAX], C2[N_MAX];
 
void BubbleSort(Data C[N_MAX], int N);
void SelectionSort(Data C[N_MAX], int N);
  
void BubbleSort(Data C1[N_MAX], int N)
{   
    int i, j, flag=0;
    Data work;
 
    for(i=0; i<N; i++){
        for(j=N-1; j>i; j--){
            if(C1[j].value < C1[j-1].value){
                work=C1[j];
                C1[j]=C1[j-1];
                C1[j-1]=work;
            }
        }
    }
    for(i=0; i<N; i++){
        printf("%c%d", C1[i].mark, C1[i].value);
        if(i!=N-1) printf(" ");
    }
    printf("\nStable\n");
}
 
 
 
void SelectionSort(Data C2[N_MAX], int N)
{
    int i, j, flag=0;
    Data work;
    int minj;
 
    for(i=0; i<N; i++){
        minj=i;
        for(j=i; j<N; j++){
            if(C2[j].value < C2[minj].value){
                minj = j;
                }
        }
            work = C2[i];
            C2[i] = C2[minj];
            C2[minj] = work;
    }
 
    for(i=0; i<N; i++){
        printf("%c%d", C2[i].mark, C2[i].value);
        if(i!=N-1)printf(" ");
    }
         
    printf("\n");
 
    for(i=0; i<N; i++){
        if(C2[i].mark != C1[i].mark)
            flag = 1;
    }
 
    if(flag == 1)
        printf("Not stable\n");
    else
        printf("Stable\n");
}
 
int main()
{
    int N;
    int i;
 
    scanf("%d", &N);
 
    for(i=0; i<N; i++){
        scanf(" %c%d", &C[i].mark, &C[i].value);
    }   
 
    for(i=0; i<N; i++){
        C1[i] = C[i];
        C2[i] = C[i];
    }
 
 
    BubbleSort(C1, N);
    SelectionSort(C2, N);
 
    return 0;
 
}