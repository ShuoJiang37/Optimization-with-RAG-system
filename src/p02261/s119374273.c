#include<stdio.h>

typedef struct{
  char pic;
  int num;
}Trump;

void change(Trump *, Trump *);
void BubbleSort(Trump *, int);
void SelectionSort(Trump *, int);
void Print(Trump *, int);
int Compare(Trump *, Trump *, int);


int main(){
  int n,i,com;
  Trump T1[100];
  Trump T2[100];

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++){
    scanf(" %c%d",&T1[i].pic,&T1[i].num);
    T2[i] = T1[i];
  }

  BubbleSort(T1,n);
  SelectionSort(T2,n);

  com = Compare(T1,T2,n);

  Print(T1,n);
  printf("Stable\n");
  Print(T2,n);
  if(com == 1) printf("Stable\n");
  else printf("Not stable\n");

 return 0;
}

void change(Trump *x, Trump *y){
  Trump z;

  z = *x;
  *x = *y;
  *y = z;
}

void BubbleSort(Trump A[], int x){
  int i,j;
  Trump a;
  for(i = 0 ; i < x ; i++){
    for(j = x - 1 ; j >= i + 1 ; j--){
      if(A[j].num < A[j-1].num) change(&A[j],&A[j-1]);
    }
  }
}

void SelectionSort(Trump A[], int x){
  int i,j,minj;
  Trump a;

  for(i = 0 ; i < x ; i++){
    minj = i;
    for(j = i ; j < x ; j++){
      if(A[j].num < A[minj].num) minj = j;
    }
    change(&A[i],&A[minj]);
  }
}

void Print(Trump A[], int x){
  int i;

  for(i = 0 ; i < x ; i++){
    if(i > 0) printf(" ");
    printf("%c%d",A[i].pic, A[i].num);
  }
  printf("\n");
}

int Compare(Trump A1[], Trump A2[], int x){
  int i;

  for(i = 0 ; i < x ; i++){
    if(A1[i].pic != A2[i].pic) return 0;
  }
  return 1;
}

