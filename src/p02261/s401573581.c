#include<stdio.h>
#define N 36

typedef struct{
  char mark;
  int num;
}Card;

void bubbleSort(Card *, int);
void selectionSort(Card *, int);

int main(){
  int i, n, count=0;
  Card cardb[N], cards[N];

  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf(" %c%d", &cardb[i].mark, &cardb[i].num);
    cards[i] = cardb[i];
  }

  bubbleSort(cardb, n);
  selectionSort(cards, n);

  for(i=0; i<n; i++){
    printf("%c%d", cardb[i].mark, cardb[i].num);
    if(i == n-1)printf("\n");
    else printf(" ");
  }
  printf("Stable\n");
  for(i=0; i<n; i++){
    printf("%c%d", cards[i].mark, cards[i].num);
    if(i == n-1)printf("\n");
    else printf(" ");
    if(cardb[i].mark == cards[i].mark && cardb[i].num == cards[i].num)count++;
  }
  if(count == n)printf("Stable\n");
  else printf("Not stable\n");

  return 0;
}

void bubbleSort(Card *A, int n){
  int i, flag=1;
  Card a;

  while(flag){
    flag = 0;
    for(i=n-1; i>0; i--){
      if(A[i].num < A[i-1].num){
	a = A[i];
	A[i] = A[i-1];
	A[i-1] = a;
	flag = 1;
      }
    }
  }
}

void selectionSort(Card *A, int n){
  int i, j, minj;
  Card a;

  for(i=0; i<n; i++){
    minj = i;
    for(j=i; j<n; j++){
      if(A[j].num < A[minj].num) minj = j;
    }

    if(A[i].num != A[minj].num){
      a = A[i];
      A[i] = A[minj];
      A[minj] = a;
    }
  }
}

