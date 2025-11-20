#include<stdio.h>

typedef struct{
  char p;
  int nu;
}Trump;

void change(Trump *, Trump *);
void BubbleSort(Trump *, int);
void SelectionSort(Trump *, int);
void Print(Trump *, int);
int Compare(Trump *, Trump *, int);


int main(){
  int h,i,com;
  Trump P1[100];
  Trump P2[100];

  scanf("%d",&h);

  for(i = 0 ; i < h ; i++){
    scanf(" %c%d",&P1[i].p,&P1[i].nu);
    P2[i] = P1[i];
  }

  BubbleSort(P1,h);
  SelectionSort(P2,h);

  com = Compare(P1,P2,h);

  Print(P1,h);
  printf("Stable\n");
  Print(P2,h);
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
      if(A[j].nu < A[j-1].nu) change(&A[j],&A[j-1]);
    }
  }
}

void SelectionSort(Trump A[], int x){
  int i,j,minj;
  Trump a;

  for(i = 0 ; i < x ; i++){
    minj = i;
    for(j = i ; j < x ; j++){
      if(A[j].nu < A[minj].nu) minj = j;
    }
    change(&A[i],&A[minj]);
  }
}

void Print(Trump A[], int x){
  int i;

  for(i = 0 ; i < x ; i++){
    if(i > 0) printf(" ");
    printf("%c%d",A[i].p, A[i].nu);
  }
  printf("\n");
}

int Compare(Trump A1[], Trump A2[], int x){
  int i;

  for(i = 0 ; i < x ; i++){
    if(A1[i].p != A2[i].p) return 0;
  }
  return 1;
}

