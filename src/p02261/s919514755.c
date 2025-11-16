#include<stdio.h>
#include<stdlib.h>

typedef struct{
  char mark;
  int value;
} card;

#define MAX 36

int N;

int isStable(card *,card *);

int main(){
  int i,j,minj,is;
  card C1[MAX],C2[MAX],temp;

  scanf("%d",&N);
  if(N<1 || N>MAX){
    exit(1);
  }
  for(i=0;i<N;i++){
    scanf(" %c%d",&C1[i].mark,&C1[i].value);
  }

  for(i=0;i<N;i++){
    C2[i]=C1[i];
  }

  //BubbleSort
  for(i=0;i<N;i++){
    for(j=N-1;j>=i+1;j--){
      if(C1[j].value<C1[j-1].value){
	temp=C1[j];
	C1[j]=C1[j-1];
	C1[j-1]=temp;
      }
    }
  }

  //SelectionSort
  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(C2[j].value<C2[minj].value){
	minj=j;
      }
    }
    temp=C2[i];
    C2[i]=C2[minj];
    C2[minj]=temp;
  }

  //BubbleSort output
  for(i=0;i<N-1;i++){
    printf("%c%d ",C1[i].mark,C1[i].value);
  }
  printf("%c%d\n",C1[N-1].mark,C1[N-1].value);
  printf("Stable\n");

  is=isStable(C1,C2); //SelectionSort isStable

  //SelectionSort output
  for(i=0;i<N-1;i++){
    printf("%c%d ",C2[i].mark,C2[i].value);
  }
  printf("%c%d\n",C2[N-1].mark,C2[N-1].value);
  if(is==1){
    printf("Stable\n");
  }else{
    printf("Not stable\n");
  }

  return 0;
}

int isStable(card *in,card *out){
  int i;

  for(i=0;i<N;i++){
    if(in[i].mark!=out[i].mark){
      return 0; //false
    }
  }

  return 1; //true
}