#include<stdio.h>
#define N 36
typedef struct{
  char suit;
  char value;
}Card;

main(){
  Card C1[N], C2[N], change;
  int i, j, k, mini;
  char ch;
  scanf("%d%c", &k, &ch);
  for(i = 0;i < k;i++){
    scanf("%c%c%c", &C1[i].suit, &C1[i].value, &ch);
    C2[i] = C1[i];
  }
  for(i = 0;i < k;i++){
    for(j = k-1;j > i;j--){
      if(C1[j].value < C1[j-1].value){
	change = C1[j];
	C1[j] = C1[j-1];
	C1[j-1] = change;
      }
    }
  }
  for(i = 0;i < k-1;i++){
    printf("%c%c ", C1[i].suit, C1[i].value);
  }
  printf("%c%c\nStable\n", C1[k-1].suit, C1[k-1].value);
  
  for(i = 0;i < k;i++){
    mini = i;
    for(j = i;j < k;j++){
      if(C2[j].value < C2[mini].value){
	mini = j;
      }
    }
    if(mini != i){
      change = C2[i];
      C2[i] = C2[mini];
      C2[mini] = change;      
    }
  } 
  for(i = 0;i < k-1;i++){
    printf("%c%c ", C2[i].suit, C2[i].value);
  }
  printf("%c%c\n", C2[k-1].suit, C2[k-1].value);
  for(i = 0;i < k;i++){
    mini = 0;
    if(C1[i].suit != C2[i].suit){
      printf("Not stable\n");
      mini++;
      break;
    }
    else if(i == k-1&&mini == 0){
      printf("Stable\n");
    }
  }
  return 0;
}