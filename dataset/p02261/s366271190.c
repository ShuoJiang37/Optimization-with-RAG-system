#include<stdio.h>
#include<string.h>

typedef struct{
  int val;
  char pattern;
}Card;

void BubbleSort(Card *, int);
void SelectionSort(Card *, int);

int main(){

  int n, i, flagb=1, flags=1;
  char tmp;
  Card cb[36], cs[36];

  scanf("%d%c",&n, &tmp);

  for(i = 0; i < n; i++)
    scanf("%c%d%c",&cb[i].pattern, &cb[i].val, &tmp);


  for(i = 0; i < n; i++)
    cs[i] = cb[i];

  SelectionSort(cs, n);
  BubbleSort(cb, n);

  for(i = 0; i < n; i++){
    printf("%c%d",cb[i].pattern, cb[i].val);
    if(i != n - 1) printf(" ");
    if(cb[i].pattern != cb[i].pattern || cb[i].val != cb[i].val) flagb = 0;
  }

  printf("\n");

  if(flagb == 1) printf("Stable\n");
  else printf("Not stable\n");

  for(i = 0; i < n; i++){
    printf("%c%d",cs[i].pattern, cs[i].val);
    if(i != n-1) printf(" ");
    if(cs[i].pattern != cb[i].pattern || cs[i].val != cb[i].val) flags = 0;
  }

  printf("\n");

  if(flags == 1) printf("Stable\n");
  else printf("Not stable\n");

  return 0;
}

void BubbleSort(Card *c, int n){

  int i, j;
  Card tmp;

  for(i = 0; i <= n-1; i++){
    for(j = n-1 ; j > i ; j--){
      if(c[j].val < c[j-1].val){
        tmp = c[j];
        c[j] = c[j-1];
        c[j-1] = tmp;
      }
    }
  }

  return;
}

void SelectionSort(Card *c, int n){

  int i, j, minj;
  Card tmp;

  for(i = 0; i <= n-1; i++){
    minj = i;
    for(j = i ; j <= n-1 ; j++){
      if(c[j].val < c[minj].val){
        minj = j;
      }
    }
    tmp = c[i];
    c[i] = c[minj];
    c[minj] = tmp;
  }

  return;
}