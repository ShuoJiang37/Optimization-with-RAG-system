#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
  char suit;
  char value;
}Card;

void swap(Card *,Card *);

int main(){
  Card C1[100], C2[100];
  int n, i,j,c1,c2,mini,sum=0;
  char a;
  scanf("%d%c", &n,&a);
  for ( i = 0; i < n; i++ ){
    scanf("%c%c%c",&C1[i].suit,&C1[i].value,&a);
  }
  for(i=0;i<n;i++){
  strcpy(&C2[i].suit,&C1[i].suit);
  strcpy(&C2[i].value,&C1[i].value);
  }

  for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      c1 = atoi(&C1[j].value);
      c2 = atoi(&C1[j-1].value);
      if(c1 < c2) {
	swap(&C1[j],&C1[j-1]);
      }
    }
  }
  for(i=0;i<n-1;i++)printf("%c%c ",C1[i].suit,C1[i].value);
  printf("%c%c\n",C1[n-1].suit,C1[n-1].value);
  printf("Stable\n");

  for(i=0;i<n;i++){
    mini=i;
    for(j=i;j<n;j++){
      c1 = atoi(&C2[j].value);
      c2 = atoi(&C2[mini].value);
      if(c1 < c2){
	mini = j;
      }
    }
    swap(&C2[i],&C2[mini]);
  }

  for(i=0;i<n-1;i++)printf("%c%c ",C2[i].suit,C2[i].value);
  printf("%c%c\n",C2[n-1].suit,C2[n-1].value);

  for(i=0;i<n;i++){
    if(strcmp(&C1[i].suit,&C2[i].suit)!=0 && strcmp(&C1[i].value,&C2[i].value)!=0){
      printf("Not stable\n");
      sum=1;
      break;
    }
  }
  if(sum!=1) printf("Stable\n");
  return 0;
}

void swap(Card *a,Card *b){
  Card temp;
  temp = *a;
  *a = *b;
  *b = temp;
}