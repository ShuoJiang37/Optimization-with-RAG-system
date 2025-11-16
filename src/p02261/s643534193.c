#include <stdio.h>
#include <stdlib.h>

#define MIN 1
#define MAX 36

struct Card{
  char s;
  char v;
};



void bubble(struct Card C[],int N){
  int i,j;
  struct Card t;
  for(i=0;i<=N-1;i++){
    for(j=N-1;j>=i;j--){
      if(C[j].v<C[j-1].v){
	t=C[j];
	C[j]=C[j-1];
	C[j-1]=t;
      }
    }
  }
}



void selection(struct Card C[],int N){
  int i,j,minj;
  struct Card t;
  for(i=0;i<=N-1;i++){
    minj=i;
    for(j=i;j<=N-1;j++){
      if(C[j].v<C[minj].v)
	minj=j;
    }
    t=C[i];
    C[i]=C[minj];
    C[minj]=t;
  }
}



void print(struct Card C[],int N){
  int i;
  for(i=0;i<=N-1;i++){
    if(i>0){
      printf(" ");
    }
    printf("%c%c",C[i].s,C[i].v);
  }
  printf("\n");
}



int isStable(struct Card C1[],struct Card C2[], int N){
  int i;
  for(i=0;i<=N-1;i++){
    if(C1[i].s!=C2[i].s)
      return 0;
  }
  return 1;
}




int main(){
  int i,j,N;
  struct Card C1[MAX],C2[MAX];
  char ch;
  
  scanf("%d",&N);
  if(N<MIN||N>MAX){
    exit(1);
  }
  for(i=0;i<=N-1;i++){
    scanf(" %c%c",&C1[i].s,&C1[i].v);
  }
  for(i=0;i<=N-1;i++){
    C2[i]=C1[i];
  }
  bubble(C1,N);
  selection(C2,N);
  
  print(C1,N);
  printf("Stable\n");
  print(C2,N);
  if(isStable(C1,C2,N)==1){
    printf("Stable\n");
  }
  else{
    printf("Not stable\n");
  }
  return 0;
}

