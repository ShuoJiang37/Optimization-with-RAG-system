#include<stdio.h>

struct Card{
  char suit;
  char value;
};

int main(){

  struct Card C1[101], C2[101],C3;
  int n,i,j,mini,hantei = 0;
  char ch;
  
  scanf("%d%c", &n, &ch);

  for ( i = 0; i < n; i++ ){
    scanf("%c%c%c", &C1[i].suit, &C1[i].value,&ch);
  }
  
  
  for(i = 0 ; i < n  ; i++ ){
    C2[i] = C1[i];
  }
  
  
  //for(i=0;i<n;i++)printf("%c%c ",C1[i].suit,C1[i].value);
  
  
  for(i = 0 ; i <= n - 1 ; i++){
    
    for(j = n - 1 ; j >= i + 1 ; j--){
      
      if(C1[j].value < C1[j - 1].value){
	
      	C3 = C1[j];
	C1[j] = C1[j - 1];
      	C1[j - 1] = C3;
	
      }
    }
  }
  
  
  for(i = 0 ; i <= n - 1 ; i++){
    mini = i;
    for(j = i ; j <= n - 1 ; j++){
      
      if(C2[j].value < C2[mini].value){

	mini = j;
	
      }
    }
    if(mini != i) {
      
      C3 = C2[i];
      C2[i] = C2[mini];
      C2[mini] = C3;
      
    }
  }

  for(i = 0 ; i < n  ;i++ ){
    if(i) printf(" ");    
    printf("%c%c",C1[i].suit,C1[i].value);
  }
  printf("\n");
  printf("Stable\n");

  for(i = 0 ; i < n  ;i++ ){
    if(i) printf(" ");    
    printf("%c%c",C2[i].suit,C2[i].value);
    if(C1[i].suit == C2[i].suit) hantei++;
  }
  if(hantei == n) printf("\nStable\n");
  else printf("\nNot stable\n");
  
  
  return 0;
}