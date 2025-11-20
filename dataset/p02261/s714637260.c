#include<stdio.h>
typedef struct{
  char suit;
    int value;
}Card;
void bubble(Card A[],int N){
  int i,j;
  Card t;
  for(i=0;i<N;i++){
    for(j=N-1;j>=i+1;j--){
      if(A[j].value<A[j-1].value){
	t=A[j];
	A[j]=A[j-1];
	A[j-1]=t;
      }
    }
  }
}

void selection(Card A[],int N){
  int i,j,minj;
  Card t;
  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j].value<A[minj].value)minj=j;
    }
    t=A[i];
    A[i]=A[minj];
    A[minj]=t;
  }
}

void print(Card A[],int N){
  int i;
  for(i=0;i<N;i++){
    if(i>0)printf(" ");
    printf("%c",A[i].suit);
    printf("%d",A[i].value);
  }
    printf("\n");
}
int flag(Card C1[],Card C2[],int N){
  int i,flag=0;
  for(i=0;i<N;i++){
    if(C1[i].suit != C2[i].suit){
      flag=1;
    }
  }
  return flag;
}

int main(){
  Card C1[100],C2[100];
  int N,i,a;
  char ch;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf(" %c",&C1[i].suit);
    scanf(" %d",&C1[i].value);
  }
  for(i=0;i<N;i++)C2[i]=C1[i];
  bubble(C1,N);
  selection(C2,N);
  print(C1,N);
  printf("Stable\n");
  print(C2,N);
  a=flag(C1,C2,N);
  if(a==1){
      printf("Not stable\n");
  }
      else printf("Stable\n");

  return 0;
}


