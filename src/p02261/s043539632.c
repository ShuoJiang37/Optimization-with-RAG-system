#include <stdio.h>

#define n 37

struct Card{
  char suit;
  char value;
};

void BubbleSort(struct Card C[],int N)
{
  int i,j;
  struct Card t;
  
  for(i = 0;i <= N-1;i++){
    for(j = N-1;j >= i+1;j--){
      if(C[j].value < C[j-1].value){
	t = C[j];
	C[j] = C[j-1];
	C[j-1] = t;
      }
    }
  }
}

void SelectionSort(struct Card C[],int N){
  int i,j,minj;
  struct Card t;
  
  for(i = 0;i <= N-1;i++){
    minj = i;
    for(j = i ;j <= N-1;j++){
      if (C[j].value < C[minj].value){
	minj = j;
      }
    }
      t = C[i];
      C[i] = C[minj];
      C[minj] = t;
  }
}



int isStable(struct Card in[],struct Card out[],int N)
{
  int i;
  for(i=0;i<N;i++){
    if(in[i].suit != out[i].suit){
      //printf("%c %c    %c %c",in[i].suit,in[i].value,out[i].suit,out[i].value);
      return 0;
    }
  }
  return 1;
}




int main(){
  struct Card C1[n],C2[n];
  int N,i;
  char ch;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf(" %c %c",&C1[i].suit,&C1[i].value);
  }
  for(i=0;i<N;i++){
    C2[i] = C1[i];
  }
  /*i=0;
  while(i<N){
    if(i){
      printf(" ");
    }
    printf("%c%c",C1[i].suit,C1[i].value);
    i++;
  }
  printf("\n");*/
  
  
  BubbleSort(C1,N);
  SelectionSort(C2,N);

  i=0;
  while(i<N){
    if(i){
      printf(" ");
    }
    printf("%c%c",C1[i].suit,C1[i].value);
    i++;
  }
  printf("\n");
  
  printf("Stable\n");

  i=0;
  while(i<N){
    if(i){
      printf(" ");
    }
    printf("%c%c",C2[i].suit,C2[i].value);
    i++;
  }
  printf("\n");

  if(isStable(C1,C2,N)){
    printf("Stable\n");
  }
  else{
    printf("Not stable\n");
  }

  return 0;

}

