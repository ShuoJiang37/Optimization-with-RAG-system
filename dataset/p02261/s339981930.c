#include<stdio.h>

typedef struct{
  char suit;
  char value;
}Card;

int main(void){
  Card C[101];
  Card Select[101];
  int n,i,j;
  int flag = 0;
  int tmp;
  char ch;
  int mini;

  scanf("%d\n", &n);
  for ( i = 0; i < n; i++ )
    scanf("%c%c%c", &C[i].suit, &C[i].value,&ch);

  for(i=0;i<n;i++)
    Select[i] = C[i];

  //bubble sort
  for(i=0;i<n;i++){
    for(j=n-1;j>=i+1;j--){
      if(C[j].value < C[j-1].value){
	tmp = C[j-1].value;
	ch = C[j-1].suit;
	C[j-1] = C[j];
	C[j].value = tmp;
	C[j].suit = ch;
      }
    }
  }
  
  //selection sort
  for(i=0;i<n;i++){
    mini = i;
    for(j=i+1;j<n;j++){
      if(Select[j].value < Select[mini].value){
        mini = j;
      }   
    }
    tmp = Select[i].value;
    ch = Select[i].suit;
    Select[i] = Select[mini];
    Select[mini].value = tmp;
    Select[mini].suit = ch;
  }

  for(i=0;i<n-1;i++)
    printf("%c%c ",C[i].suit,C[i].value);
  printf("%c%c\n",C[i].suit,C[i].value);
  printf("Stable\n");

  for(i=0;i<n-1;i++)
    printf("%c%c ",Select[i].suit,Select[i].value);
  printf("%c%c\n",Select[i].suit,Select[i].value);

  for(i=0;i< n;i++){
    if(Select[i].suit != C[i].suit)
      flag++;
  }

  if(flag == 0)
    printf("Stable\n");
  else
    printf("Not stable\n");

  return 0;
}