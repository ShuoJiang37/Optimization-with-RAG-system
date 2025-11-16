#include <stdio.h>
 
typedef struct{
  char suit;
  char value;
} Card;

void Bubble(Card *, int);
void Selection(Card *, int);
int TorF(Card *, Card *, int);
void Print(Card *, int);

int main()
{
  int n, i;
  Card c1[100], c2[100];
 
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf(" %c%c",&c1[i].suit,&c1[i].value);
    c2[i] = c1[i];
  }
 
  Bubble(c1, n);
  Selection(c2, n);
 
  Print(c1, n);
  printf("Stable\n");
  Print(c2, n);
  if(TorF(c1, c2, n) == n) printf("Stable\n");
  else printf("Not stable\n");
   
  return 0;
}

void Bubble(Card *X, int n)
{
  int i, j;
  Card card1;
  for(i = 0; i < n; i++){
    for(j = n-1; j >= i; j--){
      if(X[j].value < X[j-1].value){
    card1 = X[j];
    X[j] = X[j-1];
    X[j-1] = card1;
      }
    }
  }
}
 
void Selection(Card *X, int n)
{
  int i, j, k;
  Card card2;
  for(i = 0; i < n; i++){
    k = i;
    for(j = i; j < n; j++) if(X[j].value < X[k].value) k = j;
    card2 = X[i];
    X[i] = X[k];
    X[k] = card2;
  }
}
 
int TorF(Card *X, Card *Y, int n)
{
  int i, count=0;
  for(i = 0; i < n; i++) if(X[i].suit == Y[i].suit) count++;
  return count;
}
 
void Print(Card *X, int n)
{
  int i;
  for(i = 0; i < n; i++){
    if(i != n-1) printf("%c%c ", X[i].suit, X[i].value);
    else printf("%c%c", X[i].suit, X[i].value);
  }
  printf("\n");
}