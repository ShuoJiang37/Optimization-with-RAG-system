#include <stdio.h>

typedef struct{
  char a;
  int b;
}trump;

void BubbleSort(trump card[],int n){
  int i,j;
  trump temp;

  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(card[j-1].b>card[j].b){
        temp=card[j];
        card[j]=card[j-1];
        card[j-1]=temp;
      }
    }
  }
  for(i=0;i<n;i++){
    if(i>0)printf(" ");
    printf("%c%d",card[i].a,card[i].b);
  }
  printf("\n");
}

void SelectionSort(trump card[],int n){
  int i,min,j;
trump temp;

  for(i=0;i<n;i++){
    min=i;
    for(j=i+1;j<n;j++){
      if(card[j].b<card[min].b){
        min=j;
      }
    }
    temp=card[i];
    card[i]=card[min];
    card[min]=temp;
  }
  for(i=0;i<n;i++){
    if(i>0)printf(" ");
    printf("%c%d",card[i].a,card[i].b);
  }
  printf("\n");
}

int main(void){
  int n,i,flag;
  trump card_1[36]={},card_2[36]={};

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf(" %c%d",&card_1[i].a,&card_1[i].b);
    card_2[i].a=card_1[i].a;
    card_2[i].b=card_1[i].b;
    //printf("%c%d\n",card_2[i].a,card_2[i].b);
  }

  BubbleSort(card_1,n);
  printf("Stable\n");
  SelectionSort(card_2,n);
  for(i=0;i<n;i++){
    if(card_2[i].a!=card_1[i].a){
      flag=0;
      break;
    }
    else flag=1;
  }
  if(flag==0)printf("Not stable\n");
  if(flag==1)printf("Stable\n");

  return 0;
}