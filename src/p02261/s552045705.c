#include<stdio.h>

struct Card{
  char suit;
  char value;
  int index;
};

/*

your codes

*/

void BubbleSort(struct Card* C, int lenght)
{
  int i, j;
  struct Card w;
  for(i = 1; i <= lenght; i++){
    for(j = lenght; i + 1 <= j; j--){
      if(C[j].value < C[j-1].value){
        w = C[j-1];
        C[j-1] = C[j];
        C[j] = w;
      }
    }
  }
  return;
}

void SelectionSort(struct Card* C, int lenght)
{
  int i, j, mini;
  struct Card w;
  for(i = 1; i <= lenght; i++){
    mini = i;
    for(j = i; j <= lenght; j++){
      if(C[j].value < C[mini].value){
        mini = j;
      }
    }
    w = C[i];
    C[i] = C[mini];
    C[mini] = w;
  }
  return;
}

void IsStable(struct Card* C, int lenght)
{
  int stable = 0;
  int i;
  for(i = 1; i < lenght; i++){
    if((C[i].value == C[i+1].value) && (C[i].index > C[i+1].index)){
      stable = 1;
      break;
    }
  }
  if(stable == 0){
    printf("Stable\n");
  }else{
    printf("Not stable\n");
  }
  return;
}

void d(struct Card* C, int lenght)
{
  int i;
  for(i = 1; i < lenght; i++){
    printf("%c%c ", C[i].suit, C[i].value);
  }
  printf("%c%c\n", C[i].suit, C[i].value);
  return;
}

int main(){
  struct Card C1[101], C2[101];
  int n, i;
  char ch;

  scanf("%d%c", &n, &ch);
  for ( i = 1; i <= n; i++ ){
    scanf("%c%c%c", &C1[i].suit, &C1[i].value, &ch);
    C1[i].index = i;
    C2[i] = C1[i];
  }

  /*

  your codes

  */
  BubbleSort(C1, n);
  d(C1, n);
  IsStable(C1, n);

  SelectionSort(C2, n);
  d(C2, n);
  IsStable(C2, n);

  return 0;
}