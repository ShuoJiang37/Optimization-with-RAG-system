#include <stdio.h>

#define MAX 36

typedef struct{
  char charcter;
  int number;
}Cards;

void BubbleSort(Cards [],int);
void SelectionSort(Cards [],int);
void swap_n(Cards [],int,int);
void swap_c(Cards [],int,int);
int judge(Cards [],Cards [],int);

int main(){
  Cards card[MAX],card2[MAX];
  int N;
  int i;

  scanf("%d",&N);

  for (i = 0;i < N;i++){
    scanf(" %c %d",&card[i].charcter,&card[i].number);
    card2[i] = card[i];
  }

  BubbleSort(card,N);
  SelectionSort(card2,N);
  
  for (i = 0;i < N;i++){
    if (i)
      printf(" ");
    
    printf("%c%d",card[i].charcter,card[i].number);

  }

  printf("\nStable\n");

   for (i = 0;i < N;i++){
    if (i)
      printf(" ");
    
    printf("%c%d",card2[i].charcter,card2[i].number);

  }
   
  if (judge(card,card2,N))
    printf("\nStable\n");

  else
    printf("\nNot stable\n");
  
  return 0;
}

void BubbleSort(Cards card[],int N){
  int i,j;
  int flag = 1;

  i = 0;
  
  while (flag){
    flag = 0;

    for (j = N - 1;j != i;j--)
      if (card[j].number < card[j - 1].number){
	swap_n(card,j - 1,j);
	swap_c(card,j - 1,j);
	flag = 1;
      }

    i++;
  }
  
}

void SelectionSort(Cards card[],int N){
  int i,j;
  int minj;

  for (i = 0;i < N - 1;i++){
    minj = i;

    for (j = i;j < N;j++)
      if (card[j].number < card[minj].number)
	minj = j;

    swap_n(card,minj,i);
    swap_c(card,minj,i);
  }
  
}

void swap_n(Cards card[],int a,int b){
  int temp;

  temp = card[a].number;
  card[a].number = card[b].number;
  card[b].number = temp;
}

void swap_c(Cards card[],int a,int b){
  char temp;

  temp = card[a].charcter;
  card[a].charcter = card[b].charcter;
  card[b].charcter = temp;
}

int judge(Cards card[],Cards card2[],int N){
  int i;

  for (i = 0;i < N;i++)
    if (card[i].charcter != card2[i].charcter)
      return 0;

  return 1;
}

