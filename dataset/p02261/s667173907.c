#include<stdio.h>

typedef struct{
  char pics;
  int num;
}Card;

void BubbleSort(Card *, int);
void SelectionSort(Card *, int);
void Print(Card *, int);
int Compare(Card *, Card *, int);


void change(Card *a, Card *b){
  Card c;

  c = *a;
  *a = *b;
  *b = c;
}


int main(){
  int n,i,c;
  Card T1[100];
  Card T2[100];

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++){
    scanf(" %c%d",&T1[i].pics,&T1[i].num);
    T2[i] = T1[i];
  }

  BubbleSort(T1,n);
  SelectionSort(T2,n);

  c = Compare(T1,T2,n);

  Print(T1,n);
  printf("Stable\n");
  Print(T2,n);
  if(c == 1) printf("Stable\n");
  else printf("Not stable\n");

 return 0;
}


void BubbleSort(Card A[], int x){
  int i,j;
  Card a;
  for(i = 0 ; i < x ; i++){
    for(j = x - 1 ; j >= i + 1 ; j--){
      if(A[j].num < A[j-1].num) change(&A[j],&A[j-1]);
    }
  }
}

void SelectionSort(Card A[], int x){
  int i,j,minj;
  Card a;

  for(i = 0 ; i < x ; i++){
    minj = i;
    for(j = i ; j < x ; j++){
      if(A[j].num < A[minj].num) minj = j;
    }
    change(&A[i],&A[minj]);
  }
}

void Print(Card A[], int x){
  int i;

  for(i = 0 ; i < x ; i++){
    if(i > 0) printf(" ");
    printf("%c%d",A[i].pics, A[i].num);
  }
  printf("\n");
}

int Compare(Card A1[], Card A2[], int x){
  int i;

  for(i = 0 ; i < x ; i++){
    if(A1[i].pics != A2[i].pics) return 0;
  }
  return 1;
}

