#include <stdio.h>
#include <stdlib.h>

#define N_MAX 36

struct Card {
  char suit;
  int value;
};

void bubbleSort(struct Card C[], int N) {
  int i, j;
  for (i = 0; i < N; i++) {
    for (j = N - 1; j > i; j--) {
      if (C[j].value < C[j - 1].value) {
        struct Card tmp = C[j];
        C[j] = C[j - 1];
        C[j - 1] = tmp;
      }
    }
  }
}

void selectionSort(struct Card C[], int N) {
  int i, j, minj;
  for (i = 0; i < N; i++) {
    minj = i;
    for (j = i; j < N; j++) {
      if (C[j].value < C[minj].value) {
        minj = j;
      }
    }
    struct Card tmp = C[i];
    C[i] = C[minj];
    C[minj] = tmp;
  }
}

int isStable(struct Card C1[], struct Card C2[], int N) {
  int i;
  for (i = 0; i < N; i++) {
    if (C1[i].suit != C2[i].suit) {
      return 0;
    }
  }
  return 1;
}

int main(void) {
  int i, N;
  char t[10];
  struct Card C1[N_MAX], C2[N_MAX];

  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    scanf("%s", &t);
    C1[i].suit = t[0];
    C1[i].value = atoi(&t[1]);
    C2[i].suit = t[0];
    C2[i].value = atoi(&t[1]);
  }

  bubbleSort(C1, N);
  selectionSort(C2, N);

  printf("%c%d", C1[0].suit, C1[0].value);
  for (i = 1; i < N; i++) {
    printf(" %c%d", C1[i].suit, C1[i].value);
  }
  printf("\n");
  printf("Stable\n");

  printf("%c%d", C2[0].suit, C2[0].value);
  for (i = 1; i < N; i++) {
    printf(" %c%d", C2[i].suit, C2[i].value);
  }
  printf("\n");
  if (isStable(C1, C2, N) == 1) {
    printf("Stable\n");
  } else {
    printf("Not stable\n");
  }

  return 0;
}