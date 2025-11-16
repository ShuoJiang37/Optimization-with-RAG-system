#include <stdio.h>
struct cards {
  char suit;
  int  value;
};

void int_swap(int *, int *);
void char_swap(char *, char *);

int main() {
  int i,j,n,min;
  int stable = 1;

  scanf("%d", &n);

  struct cards card[n], bubble[n], selection[n];

  for (i = 0; i < n; i++) {
    scanf(" %c%d", &card[i].suit, &card[i].value);

    bubble[i].suit     = card[i].suit;
    bubble[i].value    = card[i].value;
    selection[i].suit  = card[i].suit;
    selection[i].value = card[i].value;
  }

  for (i = 0; i < n; i++){ 
    for (j = n - 1; j > i; j--){ 
      if (bubble[j].value < bubble[j - 1].value) {
	char_swap(&bubble[j].suit, &bubble[j - 1].suit);
	int_swap(&bubble[j].value, &bubble[j - 1].value);
      }
    }
  }
  

  for (i = 0; i < n; i++) {
    min = i;
    for (j = i; j < n; j++) 
      if (selection[j].value < selection[min].value) 
	min = j;
    if (min != i) {
      char_swap(&selection[i].suit, &selection[min].suit);
      int_swap(&selection[i].value, &selection[min].value);
    }
  }

  for (i = 0; i < n; i++) {
    if (bubble[i].suit != selection[i].suit) {
      stable = 0;
      break;
    }
  }

  for (i = 0; i < n - 1; i++) 
    printf("%c%d ", bubble[i].suit, bubble[i].value);
  printf("%c%d\n", bubble[n - 1].suit, bubble[n - 1].value);
  printf("Stable\n");
  for (i = 0; i < n - 1; i++) 
    printf("%c%d ", selection[i].suit, selection[i].value);
  printf("%c%d\n", selection[n - 1].suit, selection[n - 1].value);
  if (stable == 1) 
    printf("Stable\n");
  else 
    printf("Not stable\n");
  return 0;
}

void 
int_swap(int *x, int *y) {
  int tmp;
  tmp = *x;
  *x  = *y;
  *y  = tmp;
}

void char_swap(char *x, char *y) {
  char tmp;
  tmp = *x;
  *x  = *y;
  *y  = tmp;
}

