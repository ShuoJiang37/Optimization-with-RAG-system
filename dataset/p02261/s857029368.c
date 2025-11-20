#include<stdio.h>

struct Card{
  char suit;
  char value;
};



int main(){
  struct Card C1[100], C2[100],f;
  int n, i,j,mini,x=0;
  char ch;

  scanf("%d%c", &n, &ch);
  for ( i = 0; i < n; i++ ){
    scanf("%c%c%c", &C1[i].suit, &C1[i].value, &ch);
  }
  for ( i = 0; i < n; i++ ){
    C2[i] = C1[i];
  }
  for(i = 0; i < n; i++){
    for(j = n-1; j >= i+1; j--){
      if(C1[j].value < C1[j-1].value){
	f = C1[j];      
	C1[j] = C1[j-1]; 
	C1[j-1] = f;
      }
    }
  }
  
  for(i = 0; i < n; i++){
    printf("%c%c",C1[i].suit,C1[i].value);
    if(i< n-1){
      printf(" ");
    }
  } 
  printf("\n");
  
  printf("Stable\n");
  
  for(i = 0; i <= n-1; i++){
    mini = i;
    for(j = i; j <= n-1; j++){
      
      if(C2[j].value < C2[mini].value){
	mini = j;
      }
    } 
    
    f = C2[i];      
    C2[i] = C2[mini]; 
    C2[mini] = f; 
  }
  for(i = 0; i < n; i++){
    if(C1[i].suit != C2[i].suit){
      x = 1;
    }
  }
  
  for(i = 0; i < n; i++){
    printf("%c%c",C2[i].suit,C2[i].value);
    if(i<n-1){
      printf(" ");
    }
    
  }   
  printf("\n");

  if(x == 1){
    printf("Not stable\n");
  }
  else {
    printf("Stable\n");
  }
  
  return 0;
}