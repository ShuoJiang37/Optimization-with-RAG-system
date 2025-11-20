#include<stdio.h>
#include <stdlib.h>

typedef struct {
  char suit;
  int value;
}card;

void BubbleSort(card*, int);
void SelectionSort(card*, int);
int Stable(card*, card*, int);

int main(){
  int i,j,n;

  scanf("%d", &n);
  card tp[n], antp[n];

  for (i = 0 ; i < n ; i++) {
    scanf(" %c%d", &tp[i].suit, &tp[i].value);
    antp[i].suit = tp[i].suit;
    antp[i].value = tp[i].value;
  }

  BubbleSort(tp, n);
  SelectionSort(antp, n);

  for(i=0; i < n; i++){
    if(i){
      printf(" ");
    }
    printf("%c%d", tp[i].suit, tp[i].value);
  }
  printf("\nStable\n"); // バブルソートは安定なソート

  for(i = 0; i < n; i++){
    if(i){
      printf(" ");
    }
    printf("%c%d", antp[i].suit, antp[i].value);
  }
  // 安定なソートであるバブルソートから実行した選択ソートが安定であったかどうかを判定
  if(Stable(tp, antp, n)){
    printf("\nStable\n");
  }
  else{
    printf("\nNot stable\n");
  }

  return 0;
}

void BubbleSort(card *C, int N){
  int i,j,f=1;
  card tem;

  while(f){
    f = 0;
    for(j = N-1 ; j > 0 ;j--){
      if(C[j].value < C[j-1].value){
        tem  = C[j];
        C[j] = C[j-1];
        C[j-1] = tem;
        f = 1;
      }
    }
  }
}

void SelectionSort(card *C, int N){
  int i,j;
  int minj;
  card tem;

   for(i = 0 ; i < N ; i++){
     minj = i;
     for(j = i ; j < N ; j++){
      if(C[j].value < C[minj].value){
        minj = j;
      }
    }
    tem = C[i];
    C[i] = C[minj];
    C[minj] = tem;
  }
}

int Stable(card *A, card *B, int N){
  int i;
  for(i = 0; i < N ; i++){
    if(A[i].suit != B[i].suit)return 0;
  }
  return 1;
}

