#include <stdio.h>
#include <stdlib.h>
#define swap(a, b, type) {type t; t=a; a=b; b=t;}

typedef struct {
  int num;
  char suit;
} CARD;

char getSuit(CARD *card);
int getNumber(CARD *card);
void setSuit(CARD *card, char suit);
void setNumber(CARD *card, int num);
void printCard(CARD *card);
int compCard(CARD *c1, CARD *c2);
CARD *createCard();
void deleteCard(CARD *card);

int main()
{
  int i, j, n, num, flg, min, stable;
  char suit;
  scanf("%d", &n);
  CARD **card1 = (CARD **)malloc(sizeof(CARD *) * n);
  CARD **card2 = (CARD **)malloc(sizeof(CARD *) * n);
  for(i=0; i<n; i++){
    scanf(" %c%d", &suit, &num);
    card1[i] = createCard();
    setSuit(card1[i], suit);
    setNumber(card1[i], num);
    card2[i] = createCard();
    setSuit(card2[i], suit);
    setNumber(card2[i], num);
  }

  //bubble sort
  flg=1;
  while(flg){
    flg=0;
    for(i=n-1; i>0; i--){
      int n1 = getNumber(card1[i-1]);
      int n2 = getNumber(card1[i]);
      if(n1 > n2){
        swap(card1[i-1], card1[i], CARD*);
        flg=1;
      }
    }
  }

  for(i=0; i<n; i++){
    if(i>0) putchar(' ');
    printCard(card1[i]);
  }
  printf("\nStable\n");

  //Selection sort
  for(i=0; i<n-1; i++){
    min = i;
    for(j=i; j<n; j++){
      int n1 = getNumber(card2[min]);
      int n2 = getNumber(card2[j]);
      if(n1 > n2){
        min = j;
      }
    }
    swap(card2[i], card2[min], CARD*);
  }

  stable = 1;
  for(i=0; i<n; i++){
    if(i>0) putchar(' ');
    printCard(card2[i]);
    if(!compCard(card1[i], card2[i])) stable = 0;
  }
  printf(stable ? "\nStable\n" : "\nNot stable\n");

  return 0;
}

char getSuit(CARD *card)
{
  return card->suit;
}
int getNumber(CARD *card)
{
  return card->num;
}

void setSuit(CARD *card, char suit)
{
  card->suit = suit;
  return;
}
void setNumber(CARD *card, int num)
{
  card->num = num;
  return;
}

void printCard(CARD *card)
{
  printf("%c%d", getSuit(card), getNumber(card));
  return;
}

int compCard(CARD *c1, CARD *c2)
{
  if(getSuit(c1) != getSuit(c2)) return 0;
  if(getNumber(c1) != getNumber(c2)) return 0;
  return 1;
}

CARD *createCard()
{
  CARD *new;
  new = (CARD *)malloc(sizeof(CARD));
  return new;
}
void deleteCard(CARD *card)
{
  if(card != (CARD *)NULL)
    free(card);
  return;
}