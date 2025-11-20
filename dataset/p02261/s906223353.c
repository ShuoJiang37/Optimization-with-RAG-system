#include <stdio.h>

struct card {
  int value;
  char symbol;
};

void bubble_sort(struct card c[], int n) {
  struct card a;
  for (int i = 0; i < n; i++) 
    for (int j = n - 1; j > i; j--) 
      if (c[j].value < c[j - 1].value) {
	a = c[j];
	c[j] = c[j - 1];
	c[j - 1] = a;
      }
}

void selection_sort(struct card c[], int n) {
  int minj;
  struct card a;
  for (int i = 0; i < n - 1; i++) {
    minj = i;
    for (int j = i + 1; j < n; j++)
      if (c[j].value < c[minj].value)
	minj = j;
    a = c[i];
    c[i] = c[minj];
    c[minj] = a;
  }
}

int stable_check(struct card a[], struct card b[], int n) {
  for (int i = 0; i < n; i++) {
    if ((a[i].value != b[i].value) || (a[i].symbol != b[i].symbol))
      return 0;
  }
  return 1;
}

void print_card(struct card a[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%c%d", a[i].symbol, a[i].value);
    if (i != n - 1)
      printf(" ");
  }
  printf("\n");
}

int main(void) {
  int n;
  struct card c[36];
  struct card a[36];
  
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf(" %c%d", &c[i].symbol, &c[i].value);
    a[i] = c[i];
  }

  bubble_sort(c, n);
  selection_sort(a, n);

  print_card(c, n);
  printf("Stable\n");
  print_card(a, n);
  if (stable_check(c, a, n))
    printf("Stable\n");
  else
    printf("Not stable\n");
  
  return 0;
}

