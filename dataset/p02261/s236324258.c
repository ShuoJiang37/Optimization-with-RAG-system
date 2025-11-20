#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char suit;
  int value;
}AAA;

void BubbleSort(AAA *, int);
void SelectionSort(AAA *, int);
void output(AAA *, int);

int main(){
  int N, i;
  AAA *C, *C_B, *C_S;
  
  scanf("%d",&N);
  C = malloc(sizeof(AAA) * N);
  C_B = malloc(sizeof(AAA) * N);
  C_S = malloc(sizeof(AAA) * N);
  for(i = 0; i < N; i++){
    scanf(" %c%d", &C[i].suit, &C[i].value);
  }
  for(i = 0; i < N; i++){
    C_B[i] = C[i];
    C_S[i] = C[i];
  }

  
  
  BubbleSort(C_B, N);
  output(C_B, N);
  printf("Stable\n");
  
  SelectionSort(C_S, N);
  output(C_S, N);
  
  for(i = 0; i < N; i++){
    if(C_B[i].suit != C_S[i].suit){
      break;
    }
  }
  if(i == N){
    printf("Stable\n");
  }
  else{
    printf("Not stable\n");
  }

  return 0;
}

void BubbleSort(AAA * C, int N){
  int i, j;
  AAA temp;
  for(i = 0; i < N - 1; i++){
    for(j = N - 1; j > i; j--){
      if(C[j - 1].value > C[j].value){
	temp = C[j];
	C[j] = C[j - 1];
	C[j - 1] = temp;
      }
    }
  }
}

void SelectionSort(AAA * C, int N){
  int i, j, minj, flag;
  AAA temp;

  for(i = 0; i < N - 1; i++){
    minj = i;
    for(j = i + 1; j < N; j++){
      if(C[minj].value > C[j].value){
	minj = j;
      }
    }
    temp = C[i];
    C[i] = C[minj];
    C[minj] = temp;
  }
}

void output(AAA * C, int N){
  int i;
  
  for(i = 0; i < N - 1; i++){
    printf("%c%d ", C[i].suit, C[i].value);
  }
  printf("%c%d\n", C[N - 1].suit, C[N - 1].value);
}
