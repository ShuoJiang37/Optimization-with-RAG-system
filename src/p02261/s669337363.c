#include <stdio.h>

typedef struct{
  char value;
  char mark;
}Card;

int main(){
  int i, j, length, mini, flag = 0;
  char emp; 
  Card C1[36],C2[36],swap;

  scanf("%d%c",&length, &emp);
  for(i = 0; i < length; i++){
    scanf("%c%c%c",&C1[i].mark, &C1[i].value, &emp);
    C2[i] = C1[i];
  }
    /*BubbleSort*/
  for(i = 0; i < length; i++){
    for(j = length-1; j > i; j--){
      if(C2[j].value < C2[j-1].value){
	swap = C2[j];
	C2[j] = C2[j-1];
	C2[j-1] = swap;
      }
    }
  }
  for(i = 0; i < length; i++){
    printf("%c%c",C2[i].mark,C2[i].value);
    if(i <= length-2) printf(" ");
  }
  printf("\n");
  printf("Stable\n");

  /*SelectionSort*/
  for(i = 0; i < length; i++){
    mini = i;
    for(j = i; j < length; j++){
      if(C1[j].value < C1[mini].value){
      	mini = j;
      }
    }
    swap = C1[i];
    C1[i] = C1[mini];
    C1[mini] = swap;
  }
  for(i = 0; i < length; i++){
    printf("%c%c",C1[i].mark, C1[i].value);
    if(i <= length-2) printf(" ");
    if(C1[i].mark != C2[i].mark || C1[i].value != C2[i].value) flag = 1;
  }
  printf("\n");
  if(flag == 1) printf("Not stable\n");
  else printf("Stable\n");

  return 0;
}