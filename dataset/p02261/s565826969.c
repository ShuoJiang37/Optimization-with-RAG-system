#include<stdio.h>
#include<string.h>

typedef struct{
  char suit;
  char value;
}Card;

void bubbleSort(Card [], int);
void selectionSort(Card [], int);
void swap(char *, char *);
void print(Card [], int);
int stable(Card [], Card [], int);

int main(){
  Card C1[101], C2[101];
  int n, i;
  char ch;

  scanf("%d%c", &n, &ch);
  for ( i = 0; i < n; i++ ){
    scanf("%c%c%c", &C1[i].suit, &C1[i].value, &ch);
    C2[i] = C1[i];
  }
  
  bubbleSort(C1, n);
  selectionSort(C2, n);
  if(stable(C1, C2, n) == 0) printf("Not stable\n");
  else printf("Stable\n");
  
  return 0;
}

void bubbleSort(Card C[], int n){
  int i, j;
  
  for(i = 0; i < n; i++){
    for(j = n - 1; j > i; j--){
      if (C[j].value < C[j - 1].value){
	swap(&C[j].suit, &C[j - 1].suit);
	swap(&C[j].value, &C[j - 1].value);
      }
    }
  }
  
  print(C, n);
  printf("Stable\n");
}

void selectionSort(Card C[], int n){
  int i, j, mini;

  for(i = 0; i < n; i++){
    mini = i;
    for(j = i; j < n; j++){
      if(C[j].value < C[mini].value) mini = j;
    }
    if(i != mini){
      swap(&C[i].suit, &C[mini].suit);
      swap(&C[i].value, &C[mini].value);
    }
  }

  print(C, n);
}

void swap(char *p, char *q){
  char swap;
  swap = *p;
  *p = *q;
  *q = swap;
}

int stable(Card C1[], Card C2[], int n){
  int i;
  char result;
  for(i = 0; i < n; i++){
    if(C1[i].suit != C2[i].suit) return 0;
  }
  return 1;
}

void print(Card C[], int n){
  int i;
  for(i = 0; i < n; i++){
    printf("%c%c", C[i].suit, C[i].value);
    if(i != n - 1)printf(" ");
  }
  printf("\n");
}