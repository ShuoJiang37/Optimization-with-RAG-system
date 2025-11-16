#include <stdio.h>

#define MAX_N 100

typedef struct{
  char Mark;
  int num;
} Card;

void swap(int*,int*);
void swap2(char*,char*);
void bubbleSort(Card*,int);
void selectionSort(Card*,int);
void print(Card*,int);
int isStable(Card*,Card*,int);

int main(){
  int N,i;
  char ch;
  Card a[MAX_N],b[MAX_N];
  scanf("%d\n",&N);
  for(i = 0 ; i < N ; i++){
    scanf("%c%d%c",&a[i].Mark,&a[i].num,&ch);
    b[i] = a[i];
  }
  bubbleSort(a,N);  
  selectionSort(b,N);
  print(a,N);
  puts(isStable(a,a,N) ? "Stable" : "Not stable");
  print(b,N);
  puts(isStable(a,b,N) ? "Stable" : "Not stable");
  return 0;
}

void swap(int *a,int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void swap2(char *a,char *b){
  char temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(Card *c,int N){
  int i,j;
  for(i = 0 ; i < N ; i++){
    for(j = N-1 ; j > i ; j--){
      if(c[j].num < c[j-1].num){
        swap(&c[j].num,&c[j-1].num);
        swap2(&c[j].Mark,&c[j-1].Mark);
      }
    }
  }
}

void selectionSort(Card *c,int N){
  int i,j,min;
  for(i = 0 ; i < N ; i++){
    min = i;
    for(j = i+1 ; j < N ; j++){
      if(c[j].num < c[min].num){
        min = j;
      }
    }
    swap(&c[i].num,&c[min].num);
    swap2(&c[i].Mark,&c[min].Mark);
  }
}

void print(Card *c,int N){
  int i;
  for(i = 0 ; i < N ; i++){
    printf("%c%d%c",
           c[i].Mark,c[i].num,(i < N-1 ? ' ' : '\n'));
  }
}

int isStable(Card *a,Card *b,int N){
  int i,flag = 1;
  for(i = 0 ; i < N ; i++){
    if(a[i].Mark != b[i].Mark){
      flag = 0;
      break;
    }
  }
  return flag;
}