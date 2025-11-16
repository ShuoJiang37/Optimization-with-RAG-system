#include<stdio.h>

struct Card{
  char s;
  char v;
};

void bubble(struct Card A[], int n);
void selection(struct Card A[], int n);
void printer(struct Card A[], int n);
int isstable(struct Card C1[], struct Card C2[], int n);

int main(){
  struct Card C1[101], C2[101];
  int n, i;
  char ch;

  scanf("%d\n", &n);
  for ( i = 0; i < n; i++ ){
    scanf("%c%c ", &C1[i].s, &C1[i].v);
  }

  for ( i = 0; i < n; i++ ) C2[i] = C1[i];

  bubble(C1, n);
  selection(C2, n);

  printer(C1, n);
  printf("Stable\n");
  printer(C2, n);
  if ( isstable(C1, C2, n) ){
    printf("Stable\n");
  } else {
    printf("Not stable\n");
  }

  return 0;
}

void bubble(struct Card A[], int n){
  int i, j;
  struct Card t;
  for ( i = 0; i < n; i++ ){
    for ( j = n-1; j >= i+1; j-- ){
      if ( A[j].v < A[j-1].v ){
        t = A[j]; A[j] = A[j-1]; A[j-1] = t;
      }
    }
  }
}

void selection(struct Card A[], int n){
  int i, j, mini;
  struct Card t;
  for ( i = 0; i < n; i++ ){
    mini = i;
    for ( j = i; j < n; j++ ){
      if ( A[j].v < A[mini].v ) mini = j;
    }
    t = A[i]; A[i] = A[mini]; A[mini] = t;
  }
}

void printer(struct Card A[], int n){
  int i;
  for ( i = 0; i < n; i++ ){
    if ( i ) printf(" ");
    printf("%c%c", A[i].s, A[i].v);
  }
  printf("\n");
}

int isstable(struct Card C1[], struct Card C2[], int n){
  int i;
  for ( i = 0; i < n; i++ ){
    if ( C1[i].s != C2[i].s ) return 0;
  }
  return 1;
}

