#include <stdio.h>

typedef struct{
  char suit;
  int value;
} Card;

void bubbleSort(Card*,int);
void selectionSort(Card* ,int);
void printSort(Card*,int);
int stableSort(Card*,Card*,int);

void bubbleSort(Card A[], int N){
  int i, j;
  Card t;
  for(i=0; i<N; i++){
    for(j=N-1; j>=i+1; j--){
      if(A[j].value<A[j-1].value){
        t = A[j];
        A[j] = A[j-1];
        A[j-1] = t;
      }
    }
  }
}

void selectionSort(Card A[], int N){
  int i, j, minj=0;
  Card t;
  for(i=0; i<N; i++){
    minj = i;
    for(j=i; j<N; j++){
      if(A[j].value < A[minj].value)
        minj = j;
    }
    t = A[i];
    A[i] = A[minj];
    A[minj] = t;
  }
}

void printSort(Card A[], int N){
  int i;
  for(i=0; i<N; i++){
    if(i>0) printf(" ");
    printf("%c%d", A[i].suit, A[i].value);
  }
  printf("\n");
}

int stableSort(Card c1[], Card c2[], int N){
  int i;
  for(i=0; i<N; i++){
    if(c1[i].suit != c2[i].suit) return 0;
  }
  return 1;
}

int main(){
  Card c1[100], c2[100];
  int N, i, x=999;
  char ch[2];

  scanf("%d", &N);
  for(i=0; i<N; i++){
    scanf("%s", ch);
    c1[i].suit = ch[0];
    c1[i].value = (int)(ch[1]-48);
    }
  for(i=0; i<N; i++) c2[i] = c1[i];

  bubbleSort(c1,N);
  selectionSort(c2,N);

  printSort(c1,N);
  printf("Stable\n");
  printSort(c2,N);
  if(stableSort(c1,c2,N) == 1){
    printf("Stable\n");
  } else {
    printf("Not stable\n");
  }

  return 0;
}