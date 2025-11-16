#include<stdio.h>
#define MAX 36

typedef struct{
  char c;
  int n;
}Card;


int main(){
  int N,i,j,k=0;
  Card card1[MAX], card2[MAX], card3[MAX],cp;
  char c;
  int mini;
  
  scanf("%d\n",&N);
  for(i=0; i<N; i++){
    scanf("%c%d",&card1[i].c,&card1[i].n);
    scanf("%c",&c);
  }
  
  for(i=0; i<N; i++)card2[i]=card1[i];
  
  k=0;
  for(i=1;i<=9;i++){
    for(j=0;j<N;j++){
      if(card1[j].n==i){
	card3[k]=card1[j];
	k++;
      }
    }
  }
  
  for(i=0;i<N;i++){
    for(j=N-1;j>=i+1;j--){
      if(card1[j].n<card1[j-1].n){
	cp=card1[j];
	card1[j]=card1[j-1];
	card1[j-1]=cp;
      }
    }
  }
  
  for(i=0; i<N-1; i++) printf("%c%d ",card1[i].c,card1[i].n);
  printf("%c%d\n",card1[i].c,card1[i].n);
  
  
  k=0;
  for(i=0;i<N;i++){
    if(card1[i].c!=card3[i].c){
      printf("Not stable\n");
      k++;
      break;
    }
  }
  if(k==0)printf("Stable\n");
  
  
  for(i=0;i<N;i++){
    mini=i;
    for(j=i;j<N;j++){
      if(card2[j].n<card2[mini].n)mini=j;
    }
    cp=card2[i];
    card2[i]=card2[mini];
    card2[mini]=cp;
  }
  
  
  for(i=0;i<N-1;i++) printf("%c%d ",card2[i].c,card2[i].n);
  printf("%c%d\n",card2[i].c,card2[i].n);
  
  k=0;
  for(i=0; i<N; i++){
    if(card2[i].c!=card3[i].c){
      printf("Not stable\n");
      k++;
      break;
    }
  }
  if(k==0)printf("Stable\n");

  return 0;
}