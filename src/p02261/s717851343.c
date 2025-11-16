#include<stdio.h>

struct Card{
  char suit;
  char value;
};

void bubble(struct Card A[], int n){
  int l, j;
  struct Card t;
  for ( l = 0; l < n; l++ ){
    for ( j = n-1; j >= l+1; j-- ){
      if ( A[j].value < A[j-1].value ){
	t = A[j]; A[j] = A[j-1]; A[j-1] = t;
      }
    }
  }
}

void selection(struct Card A[], int n){
  int i, p, mini;
  struct Card t;
  for ( i = 0; i < n; i++ ){
    mini = i;
    for ( p = i; p < n; p++ ){
      if ( A[p].value < A[mini].value ) mini = p;
    }
    t = A[i]; A[i] = A[mini]; A[mini] = t;
  }
}

void print(struct Card A[], int n){
  int f;
  for ( f = 0; f < n; f++ ){
    if ( f ) printf(" ");
    printf("%c%c", A[f].suit, A[f].value);
  }
  printf("\n");
}

int isStable(struct Card C1[], struct Card C2[], int n){
  int b;
  for ( b = 0; b < n; b++ ){
    if ( C1[b].suit != C2[b].suit ) return 0;
  }
  return 1;
}

int main(){
  struct Card C1[101], C2[101];
  int n, i;
  char ch;

  scanf("%d\n", &n);
  for ( i = 0; i < n; i++ ){
    scanf("%c%c ", &C1[i].suit, &C1[i].value);
  }

  for ( i = 0; i < n; i++ ) C2[i] = C1[i];

  bubble(C1, n);
  selection(C2, n);

  print(C1, n);
  printf("Stable\n");
  print(C2, n);
  if ( isStable(C1, C2, n) ){
    printf("Stable\n");
  } else {
    printf("Not stable\n");
  }

  return 0;
}

