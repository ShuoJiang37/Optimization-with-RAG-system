#include<stdio.h>
#include<stdlib.h>

struct Card{
  char suit;
  int value;
};

int main(){
  struct Card C1[101], C2[101],tmp2;
  int n, i, j,min, tmp, flag=0,count=0;
  char ch;

  scanf("%d%c", &n,&ch);

  for ( i = 0; i < n; i++ ){
    scanf("%c%d%c", &C1[i].suit, &C1[i].value, &ch);
  }
  for(i=0;i<n;i++){
    C2[i]=C1[i];
  }
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(C1[j].value<C1[j-1].value){
	tmp=C1[j-1].value;
        C1[j-1].value=C1[j].value;
	C1[j].value=tmp;
	ch=C1[j-1].suit;
        C1[j-1].suit=C1[j].suit;
	C1[j].suit=ch;
      }   
    }
  }
  printf("%c%d",C1[0].suit,C1[0].value);

  for(i=1;i<n;i++){

    printf(" %c%d",C1[i].suit,C1[i].value);
  }
  printf("\nStable\n");

  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      if(C2[j].value==C2[i].value)flag=1;
      if(C2[j].value<C2[i].value&&flag==1){
	flag=2;
	count++;
	break;
      }
    }
    if(flag==1)flag=0;
    }
  for(i=0;i<n;i++){
    min=i;
    for(j=i+1;j<n;j++){
      if(C2[j].value<C2[min].value){
	min=j;
      }   
    }
    if(C2[i].value!=C2[min].value){
      tmp2=C2[i];
      C2[i]=C2[min];
      C2[min]=tmp2;
    } 
  }
  printf("%c%d",C2[0].suit,C2[0].value);

  for(i=1;i<n;i++){

    printf(" %c%d",C2[i].suit,C2[i].value);
  }
  if(count>0)printf("\nNot stable\n");
  else printf("\nStable\n");

  return 0;
}