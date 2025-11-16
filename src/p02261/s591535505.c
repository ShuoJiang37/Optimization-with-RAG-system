#include <stdio.h>
 
typedef struct {
  char mark;
  int num;
  int order;
} Card;
 
void BubbleSort(Card *A, int N);
void SelectionSort(Card *A, int N);
 
int main() {
  int n;
  Card C1[36], C2[36];
  int i,j;
 
  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    scanf(" %c%d", &C1[i].mark, &C1[i].num);
    C1[i].order = i;
    C2[i] = C1[i];
  }
 
  BubbleSort(C1, n);
  SelectionSort(C2, n);
 
  return 0;
}
//
void BubbleSort(Card *A, int n) {
  Card tmp;
  int stable;
  int i,j;
  int flag=1;

  while(flag){
    flag=0;
    for(j=n-1;j>=1;j--){
      if(A[j].num<A[j-1].num){
	tmp=A[j];
	A[j]=A[j-1];
	A[j-1]=tmp;
	flag=1;
      }
    }
  }
  ////
  stable = 1;
  for(i=0; i<n-1;i++) {
    printf("%c%d ", A[i].mark, A[i].num);
    if(i>0 && A[i].num==A[i-1].num && A[i].order<A[i-1].order) stable = 0;
  }
  printf("%c%d\n", A[i].mark,A[i].num);
  if(i>0 && A[i].num==A[i-1].num && A[i].order<A[i-1].order) stable = 0;
   
  if(stable==1)
    printf("Stable\n");
  else
    printf("Not stable\n");
}
 
void SelectionSort(Card A[], int n) {
  Card tmp;
  int minj;
  int stable;
  int i, j;

  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(A[j].num<A[minj].num){
	minj=j;
      }
    }
    tmp=A[i];
    A[i]=A[minj];
    A[minj]=tmp;
  }
  ////
  stable = 1;
  for(i=0;i<n-1;i++) {
    printf("%c%d ", A[i].mark,A[i].num);
    if(i>0 && A[i].num==A[i-1].num && A[i].order<A[i-1].order) stable = 0;
  }
  printf("%c%d\n", A[i].mark,A[i].num);
  if(i>0 && A[i].num==A[i-1].num && A[i].order<A[i-1].order) stable = 0;
  
  if(stable==1)
    printf("Stable\n");
  else
    printf("Not stable\n");
}
 

