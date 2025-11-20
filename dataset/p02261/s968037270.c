#include<stdio.h>

struct Card{
  char suit;
  char value;
};

void bubbleSort(struct Card C[], int);
void selectionSort(struct Card C[], int n);
void print(struct Card C[], int n);
int isStable(struct Card C1[], struct Card C2[], int n);

int main(){
  struct Card C1[101], C2[101];
  int n, i;

  scanf("%d\n", &n);
  for ( i = 0; i < n; i++ ){
    scanf("%c%c ", &C1[i].suit, &C1[i].value);
  }

  for ( i = 0; i < n; i++ ) C2[i] = C1[i];

  bubbleSort(C1, n);
  selectionSort(C2, n);

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

void bubbleSort(struct Card C[], int n){
  int i, j;
  struct Card t;
  for ( i = 0; i < n; i++ ){
    for ( j = n-1; j >= i+1; j-- ){
      if ( C[j].value < C[j-1].value ){
	    t = C[j];
	    C[j] = C[j-1];
	    C[j-1] = t;
      }
    }
  }
}

void selectionSort(struct Card C[], int n){
  int i, j, mini;
  struct Card t;
  for ( i = 0; i < n; i++ ){
    mini = i;
    for ( j = i; j < n; j++ ){
      if ( C[j].value < C[mini].value )
        mini = j;
    }
    t = C[i];
    C[i] = C[mini];
    C[mini] = t;
  }
}

void print(struct Card C[], int n){
  int i;
  for ( i = 0; i < n; i++ ){
    if ( i ) printf(" ");
    printf("%c%c", C[i].suit, C[i].value);
  }
  printf("\n");
}

int isStable(struct Card C1[], struct Card C2[], int n){
  int i;
  for ( i = 0; i < n; i++ ){
    if ( C1[i].suit != C2[i].suit ) return 0;
  }
  return 1;
}
