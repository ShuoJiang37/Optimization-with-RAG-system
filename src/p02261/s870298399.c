#include <stdio.h>
#include <stdlib.h>
struct Card{
  char EGARA;
  int NUM;
};
void BubbleSort(struct Card *);
void SelectionSort(struct Card *);
int isStable(struct Card *,struct Card *);
void print(struct Card *);


int n;

int main(){
  int i;
 struct Card A[1000], B[1000];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c",&A[i].EGARA);
    scanf("%d",&A[i].NUM);
  }
  for(i=0;i<n;i++){
    B[i]=A[i];
  }
  BubbleSort(A);
  SelectionSort(B);
  print(A);
  printf("Stable\n");
  print(B);
  if(isStable(A,B)==1)
    printf("Stable\n");
  else
    printf("Not stable\n");
    return 0;
}

void BubbleSort(struct Card *A){
  int i,j;
  struct Card m;
  for(i=0;i<n;i++){
    for(j=n-1;j>=i+1;j--){
      if(A[j].NUM<A[j-1].NUM){
	m=A[j];
	A[j]=A[j-1];
	A[j-1]=m;
      }
    }
  }
}

void SelectionSort(struct Card *B){
  int i,minj,j;
  struct Card m;
  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(B[j].NUM<B[minj].NUM){
	minj=j;
      }
    }
    m=B[i];
    B[i]=B[minj];
    B[minj]=m;
  }
}

void print(struct Card *A){
  int i;
  for(i=0;i<n;i++){
    if(i>0)
      printf(" ");
    printf("%c%d",A[i].EGARA,A[i].NUM);
  }
  printf("\n");
}

int isStable(struct Card *A,struct Card *B){
  int i;
  for(i=0;i<n;i++){
    if(A[i].EGARA!=B[i].EGARA)
      return 0;
  }
  return 1;
}
    
	
	

