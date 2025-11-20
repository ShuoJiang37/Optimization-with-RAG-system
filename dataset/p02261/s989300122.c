#include<stdio.h>

struct Card{
  char suit;
  char value;
};

typedef struct Card Card;

void Bubble(Card *, int);
void Select(Card *, int);

int main(){
  struct Card C1[100], C2[100];
  int n, i,count=0;
  char ch;
  scanf("%d%c", &n,&ch);
  for ( i = 0; i < n; i++ ){
    scanf("%c%c%c", &C1[i].suit, &C1[i].value ,&ch);
  }
  for ( i = 0; i < n; i++ ){
    C2[i]=C1[i];
  }
  
  Bubble(C1,n);
  for ( i = 0; i < n; i++ ){
    printf("%c%c",C1[i].suit,C1[i].value);
    if(i<n-1)printf(" ");
  }
  printf("\nStable\n");

  Select(C2,n);
  for ( i = 0; i < n; i++ ){
    printf("%c%c",C2[i].suit,C2[i].value);
    if(i<n-1)printf(" ");
  }
  printf("\n");
  for(i=0;i<n;i++){
    if(C1[i].suit!=C2[i].suit)count=1;
  }
  if(count==0)printf("Stable\n");
  else printf("Not stable\n");
  
  return 0;
}

void Bubble(Card *A,int n){
  int i,j;
  Card tmp;
  for(i=0;i<n;i++){
    for(j=n-1;j>=1+i;j--){
      if(A[j].value<A[j-1].value){
	tmp=A[j];
	A[j]=A[j-1];
	A[j-1]=tmp;
      }
    }
  }
}

void Select(Card *A,int n){
  int i,j,min;
  Card tmp;
  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(A[j].value<A[min].value){
	min=j;
      }
    }
    if(A[i].value!=A[min].value){
      tmp=A[i];
      A[i]=A[min];
      A[min]=tmp;
    }
  }
}