#include <stdio.h>
#define N 36

typedef struct{
  char suit;
  int num;
}Cardinfo;

int isStable(Cardinfo [],Cardinfo [],int);
int output_status(int);

int main(){
  int i,j,n,minj,status;
  Cardinfo card[N],sorted[N],alt;

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf(" %c%d",&card[i].suit,&card[i].num);

  // copy
  for(i=0;i<n;i++)sorted[i]=card[i];

  // Bubble Sort
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(sorted[j].num<sorted[j-1].num){
	alt=sorted[j];
	sorted[j]=sorted[j-1];
	sorted[j-1]=alt;
      }
    }
  }

  // output&copy
  status=isStable(card,sorted,n);
  for(i=0;i<n;i++){
    if(i==n-1)printf("%c%d\n",sorted[i].suit,sorted[i].num);
    else printf("%c%d ",sorted[i].suit,sorted[i].num);
    sorted[i]=card[i];
  }
  output_status(status);
  
  // Selection Sort
  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(sorted[minj].num>sorted[j].num)minj=j;
    }
    if(i!=minj){
      alt=sorted[minj];
      sorted[minj]=sorted[i];
      sorted[i]=alt;
    }
  }

  status=isStable(card,sorted,n);
  for(i=0;i<n-1;i++){
    printf("%c%d ",sorted[i].suit,sorted[i].num);
  }
  printf("%c%d\n",sorted[i].suit,sorted[i].num);
  output_status(status);

  return 0;
}

int isStable(Cardinfo card[],Cardinfo sorted[],int n){
  int i,j,k,l;
  for(i=0;i<n;i++)
    for(j=i+1;j<n;j++)
      for(k=0;k<n;k++)
	for(l=k+1;l<n;l++)
	  if(card[i].num==card[j].num && (card[i].num==sorted[l].num && card[i].suit==sorted[l].suit) && (card[j].num==sorted[k].num && card[j].suit==sorted[k].suit))
	    return 0;
  return 1;
}

int output_status(int status){
  if(status==0)printf("Not stable\n");
  else printf("Stable\n");
}
    

  
  