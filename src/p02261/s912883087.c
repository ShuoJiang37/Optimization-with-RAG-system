#include <stdio.h>

struct Card {
  char mark;
  int value;
};

void BubbleSort(struct Card*,int);
void SerectionSort(struct Card*,int);
int hantei(struct Card*,struct Card*,int);

int main(){
  struct Card card1[100],card2[100]; 
  int i,n;

  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf(" %c%d",&card1[i].mark,&card1[i].value);
  }

  for(i = 0;i < n;i++)
    card2[i] = card1[i];

  BubbleSort(card1,n);

  for(i = 0;i < n;i++){
    if(i > 0) printf(" ");
    printf("%c%d",card1[i].mark,card1[i].value);
  }
  printf("\nStable\n");
  
  SerectionSort(card2,n);
  
  for(i = 0;i < n;i++){
    if(i > 0) printf(" ");
    printf("%c%d",card2[i].mark,card2[i].value);
  }

  if(hantei(card1,card2,n) == 1)
    printf("\nStable\n");
  else printf("\nNot stable\n");
  
  return 0;
}
  
void BubbleSort(struct Card *c,int n){
  int i,j;
  
  for(i = 0;i < n ;i++){
    for(j = n - 1;j > i ; j--){
      if(c[j].value < c[j-1].value){
        struct Card C = c[j];
        c[j] = c[j-1];
        c[j-1] = C;
      }
    }
  }
}

void SerectionSort(struct Card *c,int n){
  int i,j,minj;

  for(i = 0;i < n;i++){
    minj = i;
    for(j = i;j < n;j++){
      if(c[j].value < c[minj].value)
        minj = j;
    }
    struct Card C = c[i];
    c[i] = c[minj];
    c[minj] = C;
  }
}

int hantei(struct Card *c1,struct Card *c2,int n){
  int i;

  for(i = 0;i < n;i++)
    if(c1[i].mark != c2[i].mark) return 0;

  return 1;
}
