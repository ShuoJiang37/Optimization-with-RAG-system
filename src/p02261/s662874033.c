#include<stdio.h>

struct Card{
  char suit;
  char value;
};


int main(){
  struct Card C1[101], C2[101];
  int n, i,j,tmpn,min,count=0;
  char ch,tmpc;

  scanf("%d%c", &n,&ch);
  for ( i = 0; i < n; i++ ){
    scanf("%c%c%c", &C1[i].suit, &C1[i].value, &ch);
  }

  for(i=0; i<n; i++){
    C2[i].suit=C1[i].suit;
    C2[i].value=C1[i].value;
  }

  for(i=0; i<n-1; i++){
    for(j=n-1; j>i;j--){
      if(C1[j].value<C1[j-1].value){
	tmpn=C1[j-1].value;
	tmpc=C1[j-1].suit;

	C1[j-1].value=C1[j].value;
	C1[j-1].suit=C1[j].suit;

	C1[j].value=tmpn;
	C1[j].suit=tmpc;
      }
    }
  }

  for(i=0; i<n-1; i++){
    min=i;
    for(j=i; j<n; j++){
      if(C2[j].value<C2[min].value)
	min=j;
    }
    tmpn=C2[i].value;
    tmpc=C2[i].suit;

    C2[i].value=C2[min].value;
    C2[i].suit=C2[min].suit;

    C2[min].value=tmpn;
    C2[min].suit=tmpc;
  }
 

	for(i=0; i<n-1; i++)
	  printf("%c%c ",C1[i].suit,C1[i].value);
	printf("%c%c\nStable\n",C1[n-1].suit,C1[n-1].value);

	for(i=0; i<n-1; i++)
	  printf("%c%c ",C2[i].suit,C2[i].value);
	printf("%c%c",C2[n-1].suit,C2[n-1].value);
       
	for(i=0; i<n; i++){
	  if(C1[i].suit==C2[i].suit && C1[i].value==C2[i].value)
	    count++;
	}

	if(count==n)printf("\nStable\n");
	else printf("\nNot stable\n");      

  return 0;
}