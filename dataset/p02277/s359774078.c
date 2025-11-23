#include <stdio.h>

typedef struct card {
  char suit;
  int value;
} card;

int numberOfCards;
card original[100000];
card sorted[100000];

void printCards(card array[100000]) {
  int i;
  for ( i = 0; i < numberOfCards; i++ )
    printf("%c %d\n", array[i].suit, array[i].value);
}

void swap(card array[100000], int i, int j) {
  int valholder;
  char suitholder;
  valholder = array[i].value;
  suitholder = array[i].suit;
  array[i].value = array[j].value;
  array[i].suit = array[j].suit;
  array[j].value = valholder;
  array[j].suit = suitholder;
}

int partition(card array[100000], int p, int r) {
  int x = array[r].value, i = p-1, j, valholder;
  char suitholder;
  for ( j = p; j < r; j++ )
    if ( array[j].value <= x )
      swap(array, ++i, j);
  swap(array, ++i, r);
  return i;
}

void quicksort(card array[100000], int p, int r) {
  if ( p < r ) {
    int q = partition(array, p, r);
    quicksort(array, p, q-1);
    quicksort(array, q+1, r);
  }
}

int ifstable() {
  int i, j, prevVal = -1;
  for ( i = 0; i < numberOfCards; i++ ) {
    int currVal = sorted[i].value;
    for ( j = (prevVal==currVal ? j+1 : 0); j < numberOfCards; j++ ) {
      if ( (original[j].value == sorted[i].value) &&
	   (original[j].suit == sorted[i].suit) )
	break;
      else if ( j == numberOfCards-1 )
	return 0;
    }
    prevVal = currVal;
  }
  return 1;
}

int main(void) {
  int i;
  scanf(" %d", &numberOfCards);
  for ( i = 0; i < numberOfCards; i++ ) {
    scanf(" %c %d", &original[i].suit, &original[i].value);
    sorted[i].suit = original[i].suit;
    sorted[i].value = original[i].value;
  }
  quicksort(sorted, 0, numberOfCards-1);
  printf("%s\n", ifstable() ? "Stable" : "Not stable");
  printCards(sorted);
  return 0;
}

