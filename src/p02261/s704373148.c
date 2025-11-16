#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
  char suit,value;
}Card;

void Bubble(Card A[],int N){
  int i,j;
  Card f;
  for(i=0;i<=N-1;i++){
    for(j=N-1;j>i;j--){
      if(A[j].value<A[j-1].value){
          f = A[j];
          A[j]=A[j-1];
          A[j-1]=f;
        }
      }
    }
  }

void Selection(Card A[], int N){
  int i,j,minj,a,b;
  Card t;
  for(i=0;i<N;i++){
      minj=i;
      for(j=i;j<N;j++){
        if(A[j].value<A[minj].value){
          minj=j;
        }
      }
      t =A[i];A[i] = A[minj];A[minj]=t;
    }
  }

int isStable(Card C1[],Card C2[],int N){
  int i;
  for(i=0;i<N;i++){
    if(C1[i].suit!=C2[i].suit)return 0;
  }
  return 1;
}

int main(){
  int i,j,N;
  Card C1[100],C2[100];
  char as,s[3];
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%s",s);
    C1[i].suit=s[0];
    C1[i].value=s[1];
  }
  for(i=0;i<N;i++)C2[i]=C1[i];
  Bubble(C1,N);
  Selection(C2,N);
  for(i=0;i<N-1;i++){
    s[0]=C1[i].suit;
    s[1]=C1[i].value;
    printf("%s ",s);
  }
  s[0]=C1[i].suit;
  s[1]=C1[i].value;
  printf("%s\n",s);
  printf("Stable\n");
  for(i=0;i<N-1;i++){
    s[0]=C2[i].suit;
    s[1]=C2[i].value;
    printf("%s ",s);
  }
  s[0]=C2[i].suit;
  s[1]=C2[i].value;
  printf("%s\n",s);
  if(isStable(C1,C2,N)){
    printf("Stable\n");
  }
  else{
    printf("Not stable\n");
  }
  return 0;
}

