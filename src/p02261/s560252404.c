#include<stdio.h>
#include<string.h>

struct Card{
  char suit;
  int value;
};


int main(){
  struct Card C1[36],C2[36];
  int n,i,j,tmp1,flag=0,mini,mini2,y=0;
  char x; /*null*/
  char tmp2;
  
  scanf("%d%c", &n, &x);
  for (i=0;i<n;i++){
    scanf("%c%d%c", &C1[i].suit, &C1[i].value, &x);
  }
  
  /*ばぶる*/
  
  for(i=0;i<n;i++){
    C2[i].suit=C1[i].suit;
    C2[i].value=C1[i].value;
  }
  
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(C1[j].value<C1[j-1].value){
	tmp1=C1[j].value;
	C1[j].value=C1[j-1].value;
	C1[j-1].value=tmp1;
	tmp2=C1[j].suit;
	C1[j].suit=C1[j-1].suit;
	C1[j-1].suit=tmp2;

      }
    }
  }
  for(i=0;i<n;i++){
    printf("%c%d",C1[i].suit,C1[i].value);
    if(i<n-1) printf(" ");
    else if(i==n-1) printf("\n");
  }
 
 printf("Stable\n");

  
  /*せれくしょん*/
  
  
  for(i=0;i<n;i++){
    mini=i;
    for(j=i;j<=n-1;j++){
      if(C2[j].value<C2[mini].value){
	mini=j;
	flag=1;    
      }
    }
    if(flag==1){
    tmp1=C2[i].value;
    C2[i].value=C2[mini].value;
    C2[mini].value=tmp1; 
    
    tmp2=C2[i].suit;
    C2[i].suit=C2[mini].suit;
    C2[mini].suit=tmp2;
    mini2=C2[i+1].suit;
    }
  }
  
  for(i=0;i<n;i++){
    printf("%c%d",C2[i].suit,C2[i].value);
 if(i<n-1) printf(" ");
 else if(i==n-1) printf("\n");
 if(C1[i].suit!=C2[i].suit) y=1;

  }
if(y==1) printf("Not stable\n");
 else printf("Stable\n");
  
  return 0;
}