#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//define the structure of a card

struct _card{
  char suit;
  int value;
};

typedef struct _card card_t;

struct _deck{
  int size;
  card_t *cards;
};

typedef struct _deck deck_t;

deck_t *make_deck(int size)
{
  deck_t *Deck;
  Deck = malloc(sizeof(deck_t));
  Deck->size = size;
  Deck->cards = malloc(size*sizeof(card_t));
  int i;
  for(i = 0; i < size; i++)
  {
    Deck->cards[i].suit = 'S';
    Deck->cards[i].value = 1;
  }
  return Deck;
}

void swap(int i,int j,deck_t *Deck)
{
  char tmpsuit;
  int tmpvalue;

  tmpsuit = Deck->cards[i].suit;
  tmpvalue = Deck->cards[i].value;

  Deck->cards[i].suit = Deck->cards[j].suit;
  Deck->cards[i].value = Deck->cards[j].value;

  Deck->cards[j].suit = tmpsuit;
  Deck->cards[j].value = tmpvalue;
}

deck_t *deck_copy(deck_t *Deck)
{
  deck_t *OUT;
  OUT = make_deck(Deck->size);

  int i;
  for(i = 0; i < Deck->size; i++)
  {
    OUT->cards[i].suit = Deck->cards[i].suit;
    OUT->cards[i].value = Deck->cards[i].value;
  }
  return OUT;
}


deck_t *card_bubbleSort(deck_t *INPUT)
{
  int i,j;
  deck_t *OUT;
  OUT = deck_copy(INPUT);

  for(i = 0; i < INPUT->size; i++)
  {
    for(j = INPUT->size-1; j > i; j--)
    {
      if(OUT->cards[j].value < OUT->cards[j-1].value) swap(j,j-1,OUT);
    }
  }
  return OUT;
}

deck_t *card_SelectionSort(deck_t *INPUT)
{
  int i,j,mini;
  deck_t *OUT;
  OUT = deck_copy(INPUT);

  for(i = 0; i < INPUT->size; i++)
  {
    mini = i;
    for(j = i; j < INPUT->size; j++)
    {
      if(OUT->cards[j].value < OUT->cards[mini].value) mini = j;
    }
    swap(i,mini,OUT);
  }
  return OUT;
}

void print_deck(deck_t *Deck)
{
  int i;
  for(i = 0; i < Deck->size-1; i++)
  {
    printf("%c%d ",Deck->cards[i].suit,Deck->cards[i].value);
  }
  printf("%c%d",Deck->cards[i].suit,Deck->cards[i].value);
  printf("\n");
}

deck_t *read_deck()
{
  int i,size;
  if(scanf("%d", &size) != 1 ){
    printf("ERROR at read_deck:The size is not an integer\n");
    exit(1);
  }
  deck_t *Deck;
  Deck = make_deck(size);

  char dummy;
  scanf("%c",&dummy);

  for(i = 0; i < size; i++)
  {
    if(scanf("%c%d",&Deck->cards[i].suit,&Deck->cards[i].value) < 1)
    {
      printf("ERROR at read_deck:The %d-th card is not correct\n", i);
      exit(1);
    }
    scanf("%c",&dummy);
  }
  return Deck;
}

//judge the stability of the sort algorithm
//Use only if deck OUT is surely made from the values of the deck INPUT
int stability_check(deck_t *OUT,deck_t *INPUT)
{
  if(OUT->size != INPUT->size)
  {
    printf("ERROR at stability:Not the same size\n");
    exit(1);
  }

  int i,j;
  j = 0;
  for(i = 0; i < OUT->size-1; i++)
  {
    while(OUT->cards[i].value == OUT->cards[i+1].value)
    {
      while(INPUT->cards[j].value != OUT->cards[i].value){
        j++;
      }
      if(INPUT->cards[j].suit != OUT->cards[i].suit)
      {
        return 1;
      }
      j++;
      i++;
    }
    j = 0;
  }
  return 0;
}

void stability(deck_t *OUT,deck_t *INPUT)
{
  if(stability_check(OUT,INPUT) == 1)
  {
    printf("Not stable\n");
  } else {
    printf("Stable\n");
  }
}

int main()
{
  deck_t *Deck;
  Deck = read_deck();
  deck_t *BubbledDeck;
  BubbledDeck = card_bubbleSort(Deck);
  deck_t *SelectedDeck;
  SelectedDeck = card_SelectionSort(Deck);
  print_deck(BubbledDeck);
  stability(BubbledDeck,Deck);
  print_deck(SelectedDeck);
  stability(SelectedDeck,Deck);
  return 0;
}

