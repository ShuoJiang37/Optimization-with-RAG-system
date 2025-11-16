#include<stdio.h>
#include<stdlib.h>

struct Card {
  char suit;
  char value;
};

void bubble(struct Card *C, int n) {
  int i, j;
  char temp;

  for(i = 0; i < n; i++) {
    for(j = n-1; j > i; j--) {
      if(C[j-1].value > C[j].value) {
	temp = C[j].value;
	C[j].value = C[j-1].value;
	C[j-1].value = temp;
	temp = C[j].suit;
	C[j].suit = C[j-1].suit;
	C[j-1].suit = temp;
      }
    }
  }
}

void selection(struct Card *C, int n) {
  int i, j, min;
  char temp;

  for(i = 0; i < n; i++) {
    min = i;
    for(j = i; j < n; j++) {
      if(C[j].value < C[min].value) {
	min = j;
      }
    }
    if(min != i) {
	temp = C[i].value;
	C[i].value = C[min].value;
	C[min].value = temp;
	temp = C[i].suit;
	C[i].suit = C[min].suit;
	C[min].suit = temp;
    }
  }
}

int main() {
  struct Card *C1, *C2;
  int n, i;
  char ch;
  int stab = 1;

  scanf("%d%c", &n, &ch);
  C1 = malloc(n*sizeof(struct Card));
  C2 = malloc(n*sizeof(struct Card));
  for(i = 0; i < n; i++) {
    scanf("%c%c%c", &C1[i].suit, &C1[i].value, &ch);
  }
  for(i = 0; i < n; i++) {
    C2[i].suit = C1[i].suit;
    C2[i].value = C1[i].value;
  }

  bubble(C1, n);
  selection(C2, n);

  for(i = 0; i < n; i++) {
    printf("%c%c", C1[i].suit, C1[i].value);
    if(i != n-1) {
      printf(" ");
    }
  }
  printf("\n");

  printf("Stable\n");

  for(i = 0; i < n; i++) {
    printf("%c%c", C2[i].suit, C2[i].value);
    if(i != n-1) {
      printf(" ");
    }
  }
  printf("\n");

  for(i = 0; i < n; i++) {
    if(C1[i].suit != C2[i].suit) {
      stab = 0;
    }
  }
  if(stab > 0) {
    printf("Stable\n");
  } else {
    printf("Not stable\n");
  }

  return 0;
}