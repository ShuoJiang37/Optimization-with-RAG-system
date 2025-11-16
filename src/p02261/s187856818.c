#include<stdio.h>
#define N 100
struct a{
  char m;
  int value;
  int bango;
};
void swap(struct a *x, struct a *y);
int main(){
  int n,i,j,flag=0;
  scanf("%d",&n);
  //BubbleSort card2
  struct a card1[n],card2[n],card3[n];
  for(i=0;i<n;i++){
    scanf(" %c",&card1[i].m);
    scanf("%d",&card1[i].value);
    card1[i].bango=i;
  }
  for(i=0;i<n;i++){
    card2[i].m=card1[i].m;
    card3[i].m=card1[i].m;
    card2[i].value=card1[i].value;
    card3[i].value=card1[i].value;
    card2[i].bango=card1[i].bango;
    card3[i].bango=card1[i].bango;
  }
  for(i=0;i<n-1;i++){
    for(j=n-1;j>=i+1;j--){
      if(card2[j].value<card2[j-1].value){
	swap(card2+j,card2+(j-1));
      }
    }
  }
  //SelectionSort card3
  int min=0;
  for(i=0;i<n-1;i++){
    min=i;
    for(j=i;j<=n-1;j++){
      if(card3[j].value<card3[min].value){
	min=j;
      }
    }
    swap(card3+i,card3+min);
  }
  //??¨??? card2
  for(i=0;i<n-1;i++){
    printf("%c%d ",card2[i].m,card2[i].value);
  }
  printf("%c%d\n",card2[n-1].m,card2[n-1].value);
  for(i=0;i<n;i++){
    if(card2[i].value==card2[i+1].value){
      if(card2[i].bango>card2[i+1].bango)flag++;
    }
  }
  if(flag!=0)printf("Not stable\n");
  else printf("Stable\n");
  //??¨??? card3
  flag=0;
  for(i=0;i<n-1;i++){
    printf("%c%d ",card3[i].m,card3[i].value);
  }
  printf("%c%d\n",card3[n-1].m,card3[i].value);
  for(i=0;i<n;i++){
    if(card3[i].value==card3[i+1].value){
      if(card3[i].bango>card3[i+1].bango)flag++;
    }
  }
  if(flag!=0)printf("Not stable\n");
  else printf("Stable\n");
  return 0;
}
void swap(struct a *x,struct a *y){
  struct a z;
  z= *x;
  *x=*y;
  *y=z;
}