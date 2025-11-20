#include<stdio.h>
#define MAX 36

typedef struct {
  char suit;
  int value;
} Data;

int judge(Data *, Data *,int);
void bubbleSort(Data *, int);
void selectionSort(Data *, int);

int main(){
  int i,k,N;
  Data C1[MAX],C2[MAX];

  scanf("%d",&N);

  for(i = 0;i < N;i++){
    scanf(" %c%d",&C1[i].suit,&C1[i].value);
  }
  
  for(i = 0;i < N;i++){
    C2[i] = C1[i];
  }

  bubbleSort(C1,N);
  selectionSort(C2,N);

  if(judge(C1,C2,N)){
    printf("Not stable\n");
  } else {
    printf("Stable\n");
  }
  
  return 0;
}

int judge(Data C[], Data D[], int N){
  int i;
  
  for(i = 0;i < N;i++){
    if(C[i].suit != D[i].suit || C[i].value != D[i].value){
      return 1;
    }
  }
  return 0;
}

void bubbleSort(Data C[], int N){
  int i,j;
  Data a;

  for(i = 0;i < N;i++){
    for(j = N-1;j >= i+1;j--){
      if(C[j].value < C[j-1].value){
	a = C[j];
	C[j] = C[j-1];
	C[j-1]  = a;
      }
    }
  }
  for(i = 0;i < N;i++){
    printf("%c%c",C[i].suit,C[i].value+48);
    if(i == N-1)break;
    printf(" ");
  }
  printf("\nStable\n");
}

void selectionSort(Data C[], int N){
  int i,j,min;
  Data a; 

  for(i = 0;i < N;i++){
    min = i;
    for(j = i;j < N;j++){
      if(C[j].value < C[min].value){
	min = j;
      }
    }
    a = C[i];
    C[i] = C[min];
    C[min] = a;
  }
  for(i = 0;i < N;i++){
    printf("%c%c",C[i].suit,C[i].value+48);
    if(i == N-1)break;
    printf(" ");
  }
  printf("\n");
}

