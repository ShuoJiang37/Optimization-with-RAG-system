#include <stdio.h>
#define n 36

struct Card{
    
  char suit;
  char value;
};

void BubbleSort(struct Card C[],int N){
  int i,j;
  struct Card a;

  for(i=0;i<N;i++){
    for(j=N-1;j>=i+1;j--){
      if(C[j].value < C[j-1].value){
        a = C[j];
        C[j] = C[j-1];
        C[j-1] = a;
      }
    }
  }
}

void SelectionSort(struct Card C[],int N){
  int i,j,minj;
  struct Card a;

  for(i=0;i<N;i++){
    minj = i;
    for(j=i;j<N;j++){
      if(C[j].value < C[minj].value){
        minj = j;
      }
    }
    a = C[i];
    C[i] = C[minj];
    C[minj] = a;
  }
}

int isStable(struct Card C1[],struct Card C2[],int N){
  int i,j;

  for(i=0;i<N;i++){
    if(C1[i].suit != C2[i].suit)return 0;
  }
  return 1;
}
  /*for(i=0;i<N;i++){                                                           
    for(j=i+1;j<N;j++){                                                         
      for(a=0;a<N;a++){                                                         
        for(b=a+1;b<N;b++){                                                     
        if(in[i] == in[j] && )*/
int main(){
  struct Card C1[101],C2[101];
  int i,N;
  scanf("%d\n",&N);
  for(i=0;i<N;i++){
    if(i!=N-1)scanf("%c%c ",&C1[i].suit,&C1[i].value);
    else scanf("%c%c",&C1[i].suit,&C1[i].value);
  }

  for(i=0;i<N;i++)C2[i] = C1[i];

  BubbleSort(C1,N);
  SelectionSort(C2,N);

  for(i=0;i<N;i++){
    if(i)printf(" ");
    printf("%c%c",C1[i].suit,C1[i].value);
  }
  printf("\nStable\n");
  for(i=0;i<N;i++){
    if(i)printf(" ");
    printf("%c%c",C2[i].suit,C2[i].value);
 }
  if(isStable(C1,C2,N)){
    printf("\nStable\n");
  }
  else printf("\nNot stable\n");

  return 0;
}

