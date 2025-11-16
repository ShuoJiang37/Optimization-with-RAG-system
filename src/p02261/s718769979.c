#include<stdio.h>

struct Card{
  char suit;
  char value;
};

int main(){
  struct Card C1[101], C2[101],CC;
  int n, i,j,mini,flag=0;
  char ch;

  scanf("%d%c", &n, &ch);
  
  for ( i = 0; i < n; i++ ){
    scanf("%c%c%c", &C1[i].suit, &C1[i].value, &ch);
  }

  for(i=0;i<n;i++) C2[i]=C1[i];

  for(i=0;i<=n-1;i++){
    for(j=n-1;j>=i+1;j--){
      if(C2[j].value < C2[j-1].value){
	CC=C2[j];
	C2[j]=C2[j-1];
	C2[j-1]=CC;
      }
    }
  }
  for(i=0;i<n;i++)
    {
    if(i>0) printf(" ");
    printf("%c%c",C2[i].suit,C2[i].value);
  }
  printf("\n");
  printf("Stable\n");

  for(i=0;i<=n-1;i++){
    mini=i;
    for(j=i;j<=n-1;j++){
      if(C1[j].value < C1[mini].value){
	mini=j;
      }
    }
    CC=C1[i];
    C1[i]=C1[mini];
    C1[mini]=CC;
  }
  for(i=0;i<n;i++)
    {
    if(i>0) printf(" ");
    printf("%c%c",C1[i].suit,C1[i].value);
    if(!(C1[i].suit == C2[i].suit && C1[i].value == C2[i].value)) flag = 1;
  }
  printf("\n");

  if(flag == 1)
    {
    printf("Not stable\n");
    }
  else printf("Stable\n");



  return 0;
}