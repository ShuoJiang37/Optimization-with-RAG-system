

#include<stdio.h>

struct Card{
  char suit;
  char value;
};


int main(){
  struct Card C1[100], C2[100],l;
  int n, i,j,mini,k=0;
  char ch;
  
  scanf("%d%c", &n, &ch);
  for ( i = 0; i < n; i++ ){
    scanf("%c%c%c", &C1[i].suit, &C1[i].value, &ch);
  }
  
  for(i=0;i<n;i++){
    C2[i]= C1[i];
  }
  //B
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--)
      {
	if(C1[j].value<C1[j-1].value){
	  l=C1[j];
	  C1[j]=C1[j-1];
	  C1[j-1]=l;
	}
      }
  }
  //S
  for(i=0;i<n;i++){
    mini = i;
    for(j=i;j<n;j++){
      if(C2[j].value<C2[mini].value) mini=j;
    }
    
    l=C2[i];
    C2[i]=C2[mini];
    C2[mini]=l;
  }
  for(i=0;i<n-1;i++){
    printf("%c%c ",C1[i].suit,C1[i].value);
  }
  
  
  printf("%c%c\n",C1[i].suit,C1[i].value);
  printf("Stable\n");
  
 
 for(i=0;i<n-1;i++){
    printf("%c%c ",C2[i].suit,C2[i].value);
  }
  printf("%c%c\n",C2[i].suit,C2[i].value);
  
  
  for(i=0;i<n;i++){
    if(C1[i].suit!=C2[i].suit)k=1;
  }
  
  
  if(k==0)printf("Stable\n");
  else printf("Not stable\n");
  return 0;
}