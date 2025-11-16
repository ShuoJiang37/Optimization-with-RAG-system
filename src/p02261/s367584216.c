#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char suit;
  int num;
  int order;
} Card;

void bub_sort(Card *,int );
void selec_sort(Card * ,int );

int main(){
  int n,i,j,a=0;
  Card c1[36],c2[36];

  scanf("%d",&n);

  if(1>n || n > 36 ) exit(8);

  for(i=0;i<n;i++){
    scanf(" %c%d",&c1[i].suit,&c1[i].num);
    c1[i].order = i;
    c2[i] = c1[i];
  }
  bub_sort(c1,n);
  selec_sort(c2,n);
 

  return 0;
}



void bub_sort(Card c[],int n){
  int k,i,stable=0,j;
  Card a;
  for(i = 0; i < n-1; ++i){
    for(j=n-1;j>=1;j--){
      if(c[j].num<c[j-1].num){
	a=c[j];
	c[j]=c[j-1];
	c[j-1]=a;
      }
    }
  }
  stable = 1;
  for(i = 0; i < n; i++){
    if(i)printf(" ");
    printf("%c%d",c[i].suit,c[i].num);
    if(i > 0 && c[i].num == c[i-1].num && c[i].order < c[i-1].order) stable=0;
  }
  printf("\n");
  puts((stable ? "Stable" : "Not stable"));
}
  

void selec_sort(Card c[] ,int n){
  int i,j,minj,stable;
  Card a;
  for(i=0; i<n; i++){
    minj = i;
    for(j = i; j < n; j++){
      if(c[j].num < c[minj].num)
	minj = j;
    }
    a = c[i];
    c[i]=c[minj];
    c[minj]=a;
  }
  stable = 1;
  for(i=0; i < n; i++){
    if(i)printf(" ");
    printf("%c%d",c[i].suit,c[i].num);
    if(i > 0 && c[i].num == c[i-1].num && c[i].order < c[i-1].order) stable=0;
  }
  printf("\n");
  puts((stable ? "Stable" : "Not stable"));
}
 





