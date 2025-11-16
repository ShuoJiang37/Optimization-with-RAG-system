#include <stdio.h>
#include <stdlib.h>

#define N 36

typedef struct card{
  int num;
  char mark;
}Card;

void BubbleSort(Card *a, int n);
void SelectionSort(Card *a, int n);

int main(void){
  int i, n, check = 0;
  Card a[N], b[N];

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf(" %c%d", &(a[i].mark), &(a[i].num));
    b[i] = a[i];
  }
  BubbleSort(a, n);
  SelectionSort(b, n);

  for(i = 0; i < n; i++){
    printf("%c%d", a[i].mark, a[i].num);
    if(i < n-1){
      printf(" ");
    }
    if(a[i].mark != b[i].mark){
      check++;
    }
  }
  printf("\nStable\n");
  for(i = 0; i < n; i++){
    printf("%c%d", b[i].mark, b[i].num);
    if(i < n-1){
      printf(" ");
    }
  }
  if(check == 0){
    printf("\nStable\n");
  }else{
    printf("\nNot stable\n");
  }
  return 0;
}

void BubbleSort(Card *a, int n){
  int flag, i, j;
  Card temp;

  for(i = n; i > 0; i--){
    flag = 0;
    for(j = 1; j < i; j++){
      if(a[j-1].num > a[j].num){
	temp = a[j-1];
	a[j-1] = a[j];
	a[j] = temp;
	flag = 1;
      }
    }
    if(flag == 0)  break;
  }
}


void SelectionSort(Card *a, int n){
  int min, i, j;
  Card temp;

  for(i = 0; i < n-1; i++){
    min = i;
    for(j = i+1; j < n; j++){
      if(a[min].num > a[j].num){
	min = j;
      }
    }
    if(min != i){
      temp = a[i];
      a[i] = a[min];
      a[min] = temp;
    }
  }
}