#include <stdio.h>

typedef struct {
  char suit;
  int num;
  int idx;
} Card;

void BubbleSort(Card C[], int N){
Card tmp;
  int stable;
  int i, j;
  for(i = 0; i < N-1; ++i) {
    for(j = N-1; j > i; --j) {
      if(C[j].num < C[j-1].num) {
        tmp = C[j];
        C[j] = C[j-1];
        C[j-1] = tmp;
      }
       }
  }
  stable = 1;
  
  for(i = 0; i < N; ++i) {
    
    printf("%c%d%c", C[i].suit, C[i].num, " \n"[i==N-1]);
    
    if(i > 0 && C[i].num == C[i-1].num && C[i].idx < C[i-1].idx)
      stable = 0;
  }
  
  puts((stable ? "Stable" : "Not stable"));
}
void SelectionSort(Card C[], int N){
  
  Card tmp;
  int minj;
  int stable;
  int i, j;
  
  for(i = 0; i < N; ++i) {
    
    minj = i;
      
    for(j = i; j < N; ++j) {
      
      if(C[j].num < C[minj].num)
	minj = j;
    }
      
    tmp = C[i];
    C[i] = C[minj];
    C[minj] = tmp;
  }
  
  stable = 1;
  
  for(i = 0; i < N; ++i) {
    
    printf("%c%d%c", C[i].suit, C[i].num, " \n"[i==N-1]);
    
    if(i > 0 && C[i].num == C[i-1].num && C[i].idx < C[i-1].idx)
      stable = 0;
  }
  
  puts((stable ? "Stable" : "Not stable"));
}

int main() {
  
  int N;
  Card C1[36], C2[36];
  int i;

  scanf("%d", &N);
  
  for(i = 0; i < N; ++i) {
    
    scanf(" %c%d", &C1[i].suit, &C1[i].num);
    C1[i].idx = i;
    C2[i] = C1[i];
  }

  BubbleSort(C1, N);
  SelectionSort(C2, N);

  return 0;
}

