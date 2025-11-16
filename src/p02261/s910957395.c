#include <stdio.h>
#include <string.h>

struct card {
  char suit;
  int number;
};

struct card a[37];
struct card b[37];

void swap(struct card *deck1, struct card *deck2) {
  struct card temp;
  int i;
  temp = *deck1;
  *deck1 = *deck2;
  *deck2 = temp;
}


void bubble(int n, struct card deck[]) {
  int i, j;
  int temp;

  for (i = 0; i < n; i++) {
    for (j = n - 1; j > i; j--) {
      if (deck[j].number < deck[j - 1].number) {
        swap(&deck[j], &deck[j - 1]);
      }
    }
  }
}


void selection(int n, struct card deck[]) {
  int i, j;
  int min;

  for (i = 0; i < n; i++) {
    min = i;
    for (j = i; j < n; j++) {
      if (deck[min].number > deck[j].number)
        min = j;
    }
    swap(&deck[min], &deck[i]);
  }
}


void print(int n, struct card deck[]) {
  int i;
  for (i = 0; i < n; i++) {
    if (i != n - 1) {
      printf("%c%d ", deck[i].suit, deck[i].number);
    } else {
      printf("%c%d\n", deck[i].suit, deck[i].number);
    }
  }
}


int check(int n, struct card deck1[], struct card deck2[]) {
  int i;
  for (i = 0; i < n; i++) {
    if (deck1[i].suit != deck2[i].suit)
      return -1;
  }
  return 1;
}


int main() {
  int num, result;
  int i;
  scanf("%d", &num);

  for (i = 0; i < num; i++) {
    scanf(" %c%d", &a[i].suit, &a[i].number);
    b[i].suit = a[i].suit;
    b[i].number = a[i].number;
  }

  bubble(num, a);
  print(num, a);
  printf("Stable\n");

  selection(num, b);
  print(num, b);
  result = check(num, a, b);
  if (result == -1) {
    printf("Not stable\n");
  } else {
    printf("Stable\n");
  }

  return 0;
}

