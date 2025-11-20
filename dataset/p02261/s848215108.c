#include<stdio.h>

struct Card{
  char suit;
  char value;
};

void sum(struct Card xu[], int n){
  int i, j;
  struct Card t;
  for ( i = 0; i < n; i++ ){
    for ( j = n-1; j >= i+1; j-- ){
      if ( xu[j].value < xu[j-1].value ){
	t = xu[j]; xu[j] = xu[j-1]; xu[j-1] = t;
      }
    }
  }
}

void num(struct Card xu[], int n){
  int i, j, min;
  struct Card t;
  for ( i = 0; i < n; i++ ){
    min = i;
    for ( j = i; j < n; j++ ){
      if ( xu[j].value < xu[min].value ) min = j;
    }
    t = xu[i];xu[i] = xu[min]; xu[min] = t;
  }
}

void tum(struct Card xu[], int n){
  int i;
  for ( i = 0; i < n; i++ ){
    if ( i ) printf(" ");
    printf("%c%c", xu[i].suit, xu[i].value);
  }
  printf("\n");
}

int rum(struct Card fan[], struct Card malon[], int n){
  int i;
  for ( i = 0; i < n; i++ ){
    if ( fan[i].suit != malon[i].suit ) return 0;
  }
  return 1;
}

#define N 110
int main(){
  struct Card fan[N], malon[N];
  int n, i;
  char ch;

  scanf("%d%c", &n, &ch);
 for ( i = 0; i < n; i++ ){
    scanf("%c%c%c", &fan[i].suit, &fan[i].value, &ch);
  }

  for ( i = 0; i < n; i++ ) malon[i] = fan[i];

  sum(fan, n);
  num(malon, n);

  tum(fan, n);
  printf("Stable\n");
  tum(malon, n);
  if ( rum(fan, malon, n) ){
    printf("Stable\n");
  } else {
    printf("Not stable\n");
  }

  return 0;
}

