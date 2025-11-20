#include <stdio.h>

/* トランプの絵柄と数字 */
typedef struct card{
  char suit;
  int value;
}CARD;

void BubbleSort(CARD*, int);
void SelectionSort(CARD*,int);
void swap(CARD*, CARD*);
int isStable(CARD*, CARD*);

main(){
  CARD c1[36], c2[36];
  int i, n;
  char dummy;

  scanf("%d%c", &n, &dummy);

  for( i = 0; i < n; i++){
    scanf("%c%d%c", &c1[i].suit, &c1[i].value, &dummy);
  }

  for( i = 0; i < n; i++) c2[i] = c1[i];

  BubbleSort(c1, n);
  printf("Stable\n");

  SelectionSort(c2, n);
  for( i = 0; i < n; i++){
    if( c1[i].value == c2[i].value && c1[i].suit != c2[i].suit ){
      printf("Not stable\n");
      break;
    }
    if( i == n-1 ) printf("Stable\n");
  }

  return 0;

}

void BubbleSort(CARD *c, int n){
  int i, j;

  for( i = 0; i < n; i++){

    for( j = n-1; i < j; j--){

      if( c[j].value < c[j-1].value ) swap(&c[j], &c[j-1]);

    }

  }

  for( i = 0; i < n; i++){
    if( i == n-1 ) printf("%c%d\n", c[i].suit, c[i].value);
    else printf("%c%d ", c[i].suit, c[i].value);
  }

}

void SelectionSort(CARD *c, int n){
  int i, j, minj;

  for( i = 0; i < n; i++){
    minj = i;

    for( j = i; j < n; j++){

      if( c[j].value < c[minj].value ) minj = j;

    }

    if( c[i].value != c[minj].value ) swap(&c[i], &c[minj]);

  }

  for( i = 0; i < n; i++){
    if( i == n-1 ) printf("%c%d\n", c[i].suit, c[i].value);
    else printf("%c%d ", c[i].suit, c[i].value);
  }

}

void swap(CARD *c1, CARD *c2){
  CARD c_ex;

  c_ex = *c1;
  *c1 = *c2;
  *c2 = c_ex;

}