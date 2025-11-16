#include <stdio.h>
 
typedef struct{
  char suit;
  char value;
} Card;
 
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
 
int main()
{
 
  int n, i;
  Card C1[100], C2[100];
 
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf(" %c%c",&C1[i].suit,&C1[i].value);
    C2[i] = C1[i];
  }
 
  Bubble(C1, n);
  Selection(C2, n);
 
  Print(C1, n);
  printf("Stable\n");
  Print(C2, n);
  if(TorF(C1, C2, n) == n) printf("Stable\n");
  else printf("Not stable\n");
   
  return 0;
}