// Stable Sort
#include <stdio.h>
#include <stdlib.h>

#define MAX 36

typedef struct{
  char suit;
  int value;
}card;

void BubbleSort(card*, int);
void SelectionSort(card*, int);
int isStable(card*, card*, int);

int main(){
  int i, n;
  card StableA[MAX], NonStableA[MAX];

  scanf("%d", &n);
  for(i=0; i < n; i++){
    scanf(" %c%d", &StableA[i].suit, &StableA[i].value);
    NonStableA[i].suit = StableA[i].suit;
    NonStableA[i].value = StableA[i].value;
  }
  BubbleSort(StableA, n); // バブルソートを実行
  SelectionSort(NonStableA, n); // 選択ソートを実行
  
  for(i=0; i < n; i++){
    if(i)printf(" ");
    printf("%c%d", StableA[i].suit, StableA[i].value);
  }
  printf("\nStable\n"); // バブルソートは安定なソート
  
  for(i=0; i < n; i++){
    if(i)printf(" ");
    printf("%c%d", NonStableA[i].suit, NonStableA[i].value);
  }
  // 安定なソートであるバブルソートから実行した選択ソートが安定であったかどうかを判定
  if(isStable(StableA, NonStableA, n))printf("\nStable\n");
  else printf("\nNot stable\n");
  
  return 0;
}

void BubbleSort(card *A, int n){
  int i, flag;
  card swp;
  flag = 1; // 逆の隣接要素が存在する
  while(flag){
    flag = 0;
    for(i=n-1; i > 0; i--){
      if(A[i].value < A[i-1].value){ // A[i]とA[i-1]を交換する
      swp = A[i];  A[i] = A[i-1];  A[i-1] = swp;
      flag = 1;
      }
    }
  }
}

void SelectionSort(card *A, int n){
  int i, j, min;
  card swp;
  for(i=0; i < n; i++){
    min = i;
    for(j=i; j < n; j++){
      if(A[j].value < A[min].value)min = j;
    }
    swp = A[i];  A[i] =A[min];  A[min] = swp;
  }
}

// ソートの結果が安定であったか調べる(A、Bの少なくともどちらか１つは安定なソートであることが前提)
int isStable(card *A, card *B, int n){
  int i;
  for(i=0; i < n; i++){
    if(A[i].suit != B[i].suit)return 0;
  }
  return 1;
}
