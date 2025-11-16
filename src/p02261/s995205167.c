#include <stdio.h>

#define N 36

typedef struct{
  char mark[N];
  int value[N];
}Card;

Card BubbleSort(Card , int);
Card SelectionSort(Card , int);

int main() {
  Card data[3];
  int n, i, j;
  
  scanf("%d", &n);
  
  for (i = 0; i < n; i++) {
    scanf("%*c%c%d", &data[0].mark[i], &data[0].value[i]);
  }

  data[1] = BubbleSort(data[0], n);
  data[2] = SelectionSort(data[0], n);

  for (i = 0; i < n; i++) {
    printf("%c%d", data[1].mark[i], data[1].value[i]);
    if (i == n-1) printf("\n");
    
    else printf(" ");
  }

  printf("Stable\n");

  for (i = 0; i < n; i++) {
    printf("%c%d", data[2].mark[i], data[2].value[i]);
    if (i == n-1) printf("\n");
    
    else printf(" ");
  }

  for (i = 0; i < n; i++) {
    if (data[1].mark[i] != data[2].mark[i]) {
      printf("Not stable\n");
      break;
    }
    else if (i == n-1) printf("Stable\n");
  }


  return 0;
}

Card BubbleSort(Card c, int n) {
  int i, j, tempn;
  char tempc;
  
  for (i = 0; i < n; i++) {
    for (j = n-1; j > i; j--) {
      if (c.value[j] < c.value[j-1]) {
	tempn = c.value[j];
  tempc = c.mark[j];
	c.value[j] = c.value[j-1];
  c.mark[j] = c.mark[j-1];
	c.value[j-1] = tempn;
  c.mark[j-1] = tempc;
      }
    }
  }
  return c;
}


Card SelectionSort(Card c, int n) {
  int i, j, minj, tempn;
  char tempc;
  
  for (i = 0; i < n; i++) {
    minj = i;
    for (j = i; j < n; j++) {
      if (c.value[j] < c.value[minj]) {
	      minj = j;
      }
    }
    if (minj != i) {
      tempn = c.value[i];
      tempc = c.mark[i];
      c.value[i] = c.value[minj];
      c.mark[i] = c.mark[minj];
      c.value[minj] = tempn;
      c.mark[minj] = tempc;
    }
  }
  return c;
}

