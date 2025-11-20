#include <stdio.h>

typedef struct {
  char mark;
  int num;
} card_t;


void BubbleSort(int n, card_t cards[]) {
  int i, j;

  for (i = 0; i < n-1; i++) {
    for (j = n-1; j >= i+1; j-- ) {
      if (cards[j-1].num > cards[j].num) {
	card_t tmp;
	tmp = cards[j-1];
	cards[j-1] = cards[j];
	cards[j] = tmp;
      }
    }
  }
  
}

void SelectSort(int n, card_t cards[]) {
  int i, j;
  int min;

  for (i = 0; i < n-1; i++) {
    min = i;
    for (j = i+1; j < n; j++) {
      if (cards[j].num < cards[min].num) {
	min = j;
      }
    }
    if (min != i) {
      card_t tmp;
      tmp = cards[i];
      cards[i] = cards[min];
      cards[min] = tmp;
    }
  }
    
}

int StableJudge(card_t A[], card_t B[], int n) {
  int i;

  for (i = 0; i < n; i++) {
    if (A[i].mark != B[i].mark) return 0;
  }

  return 1;
  
}

int main() {
  int n;
  card_t cards[36], cardsA[36], cardsB[36];
  int i;
  int judge;
  
  scanf("%d", &n);
  getchar();

  for (i = 0; i < n; i++) {
    scanf("%c%d", &(cards[i].mark), &(cards[i].num));
    getchar();
    cardsA[i] = cardsB[i] = cards[i];
  }
  
  BubbleSort(n, cardsA);
  SelectSort(n, cardsB);
  judge = StableJudge(cardsA, cardsB, n);

  for (i = 0; i < n; i++) {
    printf("%c%d", cardsA[i].mark, cardsA[i].num);
    if (i == n-1) break;
    putchar(' ');
  }
  putchar('\n');
  puts("Stable");

  for (i = 0; i < n; i++) {
    printf("%c%d", cardsB[i].mark, cardsB[i].num);
    if (i == n-1) break;
    putchar(' ');
  }
  putchar('\n');

  if (judge) {
    puts("Stable");
  }
  else {
    puts("Not stable");
  }
  
  return 0;
}

