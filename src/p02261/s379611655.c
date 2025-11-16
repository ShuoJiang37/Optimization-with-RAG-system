#include <stdio.h>
#include <stdlib.h>
typedef struct{
  char suit;
  int number;
}Card;
Card *BubbleSort(Card *,int);
Card *SelectionSort(Card *,int);
void isStable(Card *,Card *,int);
int main(void){
  int N,i;
  Card C[36];
  Card *Cbub,*Csel;
  scanf("%d",&N);
  for(i=0;i<N;i++)
    scanf(" %c%d",&C[i].suit,&C[i].number);
  Cbub=BubbleSort(C,N);
  for(i=0;i<N;i++){
    printf("%c%d",Cbub[i].suit,Cbub[i].number);
    if(i!=N-1)printf(" ");
  }
  printf("\nStable\n");
  Csel=SelectionSort(C,N);
  for(i=0;i<N;i++){
    printf("%c%d",Csel[i].suit,Csel[i].number);
    if(i!=N-1)printf(" ");
  }
  isStable(Cbub,Csel,N);
  return 0;
}
Card *BubbleSort(Card *C,int N){
  Card *Cbub;
  int flag=1,j,temp;
  char c;
  Cbub=(Card *)malloc(sizeof(Card)*N);
  for(j=0;j<N;j++)
    Cbub[j]=C[j];
  while(flag){
    flag=0;
    for(j=N-1;j>0;j--){
      if(Cbub[j].number<Cbub[j-1].number){
        temp=Cbub[j].number;
        Cbub[j].number=Cbub[j-1].number;
        Cbub[j-1].number=temp;
        c=Cbub[j].suit;
        Cbub[j].suit=Cbub[j-1].suit;
        Cbub[j-1].suit=c;
        flag=1;
      }
    }
  }
  return Cbub;
}
Card *SelectionSort(Card *C,int N){
  Card *Csel;
  int i,j,minj,temp;
  char c;
  Csel=(Card *)malloc(sizeof(Card)*N);
  for(i=0;i<N;i++)
    Csel[i]=C[i];
  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++)
      if(Csel[j].number<Csel[minj].number)minj=j;

    if(minj!=i){
      temp=Csel[i].number;
      Csel[i].number=Csel[minj].number;
      Csel[minj].number=temp;
      c=Csel[i].suit;
      Csel[i].suit=Csel[minj].suit;
      Csel[minj].suit=c;
    }
  }
  return Csel;
}
void isStable(Card *Cbub,Card *Csel,int N){
  int i=0,check=0;
  while(i<N){
    if(Cbub[i].suit!=Csel[i].suit || Cbub[i].number!=Csel[i].number){
      check=1;
      break;
    }
    i++;
  }
  if(check==0)printf("\nStable\n");
  else printf("\nNot stable\n");
}
