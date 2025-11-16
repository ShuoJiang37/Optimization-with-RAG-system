#include <stdio.h>
#include <string.h>

struct Card{
  char suit;
  char value;
};

int main(){
  struct Card C1[101],C2[101],a;
  int n,i,j,mini;
  char ch;

  scanf("%d%c",&n,&ch);
  for(i=0;i<n;i++){
    scanf("%c%c%c",&C1[i].suit,&C1[i].value,&ch);
    C2[i]=C1[i];
  }

  for(i=0;i<n;i++){
    for(j=n-1;j>=i+1;j--){
      if(C1[j].value<C1[j-1].value){
	a=C1[j];
	C1[j]=C1[j-1];
	C1[j-1]=a;
      }
    }
  }
  
  for(i=0;i<=n-1;i++){
    mini=i;
    for(j=i;j<n;j++){
      if(C2[j].value<C2[mini].value)
	mini=j;
    }
    a=C2[i];
    C2[i]=C2[mini];
    C2[mini]=a;
  }

  for(i=0;i<n-1;i++){
    printf("%c%c ",C1[i].suit,C1[i].value);
  }
  printf("%c%c\n",C1[n-1].suit,C1[n-1].value);
  printf("Stable\n");

  for(i=0;i<n-1;i++){
    printf("%c%c ",C2[i].suit,C2[i].value);
  }
  printf("%c%c\n",C2[n-1].suit,C2[n-1].value);

  for(i=0;i<n;i++){
    if(C2[i].suit!=C1[i].suit){
      printf("Not stable\n");
      break;
    }
  }
  if(i==n)
    printf("Stable\n");
  return 0;
}