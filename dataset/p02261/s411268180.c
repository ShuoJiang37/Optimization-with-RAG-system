#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
  char pattern;
  int value;
}Card;

void BubbleSort(Card C[], int N);
void SelectionSort(Card C[], int N);
void Bubblecheck(Card C[]);

int main(){
  int i;
  int N;
  Card C1[36], C2[36];

  scanf("%d", &N);
  for(i = 0; i < N; i++){
    if(i == N-1){
      scanf(" %c%d", &C1[i].pattern, &C1[i].value);
    }else{
      scanf(" %c%d ", &C1[i].pattern, &C1[i].value);
    }
  }
  memcpy(C2, C1, sizeof(Card)*N);

  BubbleSort(C1, N);
  for(i = 0; i < N; i++){
    if(i == N-1){
      printf("%c%d\n", C1[i].pattern, C1[i].value);
    }else{
      printf("%c%d ", C1[i].pattern, C1[i].value);
    }
  }
  printf("Stable\n");

  SelectionSort(C2, N);
  for(i = 0; i < N; i++){
    if(i == N-1){
      printf("%c%d\n", C2[i].pattern, C2[i].value);
    }else{
      printf("%c%d ", C2[i].pattern, C2[i].value);
    }
  }
  int count = 0;
  for(i = 0; i < N; i++){
    if(C1[i].pattern != C2[i].pattern){
      count++;
    }
  }

  if(count != 0){
    printf("Not stable\n");
  }else{
    printf("Stable\n");
  }

  return 0;
}

void BubbleSort(Card C[], int N){
  int i, j;
  Card tmp;

  for(i = 0; i < N; i++){
    for(j = N-1; j > i; j--){
      if(C[j].value < C[j-1].value){
        tmp = C[j];
        C[j] = C[j-1];
        C[j-1] = tmp;
      }
    }
  }
}

void SelectionSort(Card C[], int N){
  int i, j;
  int minj;
  Card tmp;

  for(i = 0; i < N; i++){
    minj = i;
    for(j = i; j < N; j++){
      if(C[j].value < C[minj].value){
        minj = j;
      }
    }
    tmp = C[i];
    C[i] = C[minj];
    C[minj] = tmp;
  }
}

