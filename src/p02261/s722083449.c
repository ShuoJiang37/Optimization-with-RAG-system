#include<stdio.h>
#include <stdlib.h>

#define false 0
#define true 1

void BubbleSort(int);
void SelectionSort(int);
int isStable(int);

struct tranp{
  char picture;
  int value;
};

struct tranp card[36],bub[36],sel[36];

int main(){
  int N,i;

  scanf("%d",&N);

  for(i=0;i<N;i++){
    //while(1){
      scanf(" %c",&card[i].picture);
  //    if((card[i].picture<'A')&&('Z'<card[i].picture))
    //  continue;
  //    else
  //    break;
  //}
    scanf("%d",&card[i].value);
    bub[i]=sel[i]=card[i];
  }
/*  for(i=0;i<N;i++){
  bub[i].picture=sel[i].picture=card[i].picture;
  bub[i].value=sel[i].value=card[i].value;
}*/

  BubbleSort(N);
  SelectionSort(N);

  for(i=0;i<N-1;i++)
  printf("%c%d ",bub[i].picture,bub[i].value);

  printf("%c%d\n",bub[i].picture,bub[i].value);
  printf("Stable\n");


  for(i=0;i<N-1;i++)
  printf("%c%d ",sel[i].picture,sel[i].value);

  printf("%c%d\n",sel[i].picture,sel[i].value);

  if(isStable(N)==true)
  printf("Stable\n");
  else
  printf("Not stable\n");

  return 0;
}

void BubbleSort(int N){
  int i,j;
  struct tranp x;
  for(i=0;i<N;i++){
    for(j=N-1;j>0;j--){
      if(bub[j].value<bub[j-1].value){
        x=bub[j];
        bub[j]=bub[j-1];
        bub[j-1]=x;
      }
    }
  }
}

void SelectionSort(int N){
  int i,j,minj;
  struct tranp x;
  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(sel[j].value<sel[minj].value)
      minj=j;
    }
    if(minj!=i){
    x=sel[i];
    sel[i]=sel[minj];
    sel[minj]=x;
  }
  }
}

int isStable(int N){
  int i;
  for(i=0;i<N;i++){
    if((bub[i].picture!=sel[i].picture)||(bub[i].value!=sel[i].value))
    return false;
  }
  return true;
}

