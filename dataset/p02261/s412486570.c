#include <stdio.h>

typedef struct {
    char suit, value; 
} Card;

void bubbleSort(Card a[], int n);
void selectionSort(Card a[], int n);
void print(Card a[], int n);
void strCastCard(Card *t,char str[]);
int checkStable(Card c1[], Card c2[], int n);

int main(void) {
  Card c1[100], c2[100];
  int n, i;
  char str[3];

  scanf("%d", &n);
  for(i=0; i < n; i++) {
    scanf("%s", str);
    strCastCard(&c1[i], str);
  }

  for(i = 0; i < n; i++) c2[i] = c1[i];

  bubbleSort(c1, n);
  selectionSort(c2, n);

  print(c1, n);
  printf("Stable\n");
  print(c2, n);
  if(checkStable(c1, c2, n)) {
    printf("Stable\n");
  }
  else {
    printf("Not stable\n");
  }

  return 0;
}


void bubbleSort(Card a[], int n) {
  int i,j;
  Card t;

  for(i = 0; i < n; i++) {
    for(j = n-1; j >= i; j--) {
      if(a[j].value < a[j-1].value) {
        t = a[j];
        a[j] = a[j-1];
        a[j-1] = t;
      }
    }
  }
}

void selectionSort(Card a[], int n) {
  int i, j, minj;
  Card t;

  for(i = 0; i < n; i++) {
    minj = i;
    for(j = i; j < n; j++) {
      if(a[j].value < a[minj].value) minj = j;
    }
    t = a[i];
    a[i] = a[minj];
    a[minj] = t;
  }
  return;
}

void print(Card a[], int n) {
  int i;

  for(i = 0; i < n; i++) {
    if(i > 0) printf(" ");
    printf("%c%d", a[i].suit, a[i].value);
  }
  printf("\n");
  return;
}

void strCastCard(Card *t, char str[]) {
    t->suit  = str[0];
    t->value = str[1] - '0';
    return;
}

int checkStable(Card c1[], Card c2[], int n) {
  int i;

  for(i = 0; i < n; i++) {
    if(c1[i].suit != c2[i].suit) return 0;
  }
  return 1;
}
