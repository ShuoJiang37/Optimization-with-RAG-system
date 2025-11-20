#include<stdio.h>

struct Card{
  char suit;
  char value;
};

void bubblesort(struct Card *A,int n){
  int i,j;
  struct Card x;
  for(i=0;i<n;i++){
    for(j=n-1;j>=i+1;j--){
      if(A[j].value<A[j-1].value) {
	x=A[j];
	A[j]=A[j-1];
	A[j-1]=x;
      }
    }
  }
  for(i=0;i<n;i++){
    if(i==n-1){
      printf("%c%c\n",A[i].suit,A[i].value);
      break;
    }
    printf("%c%c ",A[i].suit,A[i].value);
  }
}

void selectionsort(struct Card *A,int n){
  int i,j,min;
  struct Card x;
  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(A[j].value<A[min].value) 
	min=j;
    }
    x=A[i];
    A[i]=A[min];
    A[min]=x;
  }
  
  for(i=0;i<n;i++){
    if(i==n-1){
      printf("%c%c\n",A[i].suit,A[i].value);
      break;
    }
    printf("%c%c ",A[i].suit,A[i].value);
  }
}


int main(){
  struct Card C1[101], C2[101],C3[101],C4[101];
  int n, i,a=0;
  char ch;

  scanf("%d%c", &n, &ch);
  for ( i = 0; i <n; i++ ){
    scanf("%c%c%c", &C1[i].suit, &C1[i].value, &ch);
    C2[i].suit=C1[i].suit;
    C2[i].value=C1[i].value;
  }
 
  bubblesort(C1,n);
  printf("Stable\n");
  selectionsort(C2,n);

  for(i=0;i<n;i++){
    if(C1[i].suit!=C2[i].suit) {
      printf("Not stable\n");
      a=1;
      break;
    }
  }
  if(a==0)printf("Stable\n");

  return 0;
}