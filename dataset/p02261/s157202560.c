#include<stdio.h>
#define N 36

typedef struct{
  char kind;
  int num;
}Card;

void bubblesort(Card * ,int);
void selectionsort(Card *,int);
int isStable(Card *,Card *,int n);

int main(){
  int a,i,f = 0;
  Card card1[N],card2[N];
  
  scanf("%d",&a);
  for(i = 0;i < a;i++){
    scanf(" %c%d",&card1[i].kind,&card1[i].num);
    card2[i]=card1[i];
  }
  
  
  bubblesort(card1,a);
  for(i = 0;i < a-1;i++){
    printf("%c%d ",card1[i].kind,card1[i].num);
  }
  printf("%c%d\n",card1[a-1].kind,card1[a-1].num);
  printf("Stable\n");
  
  selectionsort(card2,a);
  for(i = 0;i < a-1;i++){
    printf("%c%d ",card2[i].kind,card2[i].num);
  }
  printf("%c%d\n",card2[a-1].kind,card2[a-1].num);
  for(i = 0;i < a;i++){
    f = f+isStable(card1,card2,a);
  }
  if(f == 0)printf("Not stable\n");
  else printf("Stable\n");
  return 0;
}

void bubblesort(Card A[],int a){
  int i,j;
  Card temp;
  for(i = 0;i <= a-1;i++){
    for(j = a-1;j >= i+1;j--){
      if(A[j].num < A[j-1].num){
	temp = A[j];
	A[j] = A[j-1];
	A[j-1] = temp;
      }
    }
  }
}

void selectionsort(Card A[],int a){
  int i,j,min;
  Card temp;
  for(i = 0;i <= a-1;i++){
    min=i;
    for(j = i;j <= a-1;j++){
      if(A[j].num<A[min].num)
	min=j;
      }
      temp=A[i];
      A[i]=A[min];
      A[min]=temp;
    } 
}
 
int isStable(Card *x,Card *y,int a){
  int i;

  for(i = 0;i < a;i++){
    if(x[i].kind != y[i].kind) return 0;
  }
  return 1;
}


