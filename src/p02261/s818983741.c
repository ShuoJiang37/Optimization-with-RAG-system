#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 36

typedef struct{
  char c;
  int value;
} Card;

Card card1[N], card2[N];

void BubbleSort(Card C[], int n){

  int i, j, temp=0;
  char ctemp;
  
  for(i=0; i<n; i++){
    for(j=n-1; j>=i+1; j--){
      if(C[j].value < C[j-1].value){
	temp = C[j].value;
	ctemp = C[j].c;
	C[j].value = C[j-1].value;
	C[j].c = C[j-1].c;
	C[j-1].value = temp;
	C[j-1].c = ctemp;
      }
    }
  }
}

void SelectionSort(Card C[], int n){

  int i, j, minj=0, temp=0;
  char ctemp;

  for(i=0; i<n; i++){
    minj = i;
    for(j=i; j<n; j++){
      if(C[j].value < C[minj].value){
	minj = j;
      }
    }
    temp = C[i].value;
    ctemp = C[i].c;
    C[i].value = C[minj].value;
    C[i].c = C[minj].c;
    C[minj].value = temp;
    C[minj].c = ctemp;
  }
}

int isStable(Card c1[], Card c2[], int n){
  int i;

  for(i=0; i<n; i++){
  if(c1[i].c != c2[i].c) return 0;
  }

  return 1;
}

int main() {

  int i, n, v;
  char S[N];

  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%s", S);
    card1[i].c = S[0];
    card1[i].value = atoi(&S[1]);
  }

  for(i=0; i<n; i++){
    card2[i].c = card1[i].c;
    card2[i].value = card1[i].value;
  }

  BubbleSort(card1, n);
  for(i=0; i<n; i++){
    printf("%c%d",card1[i].c, card1[i].value);
    if(i!=n-1) printf(" ");
  }
  printf("\n");
  printf("Stable\n");

  SelectionSort(card2, n);
  for(i=0; i<n; i++){
    printf("%c%d",card2[i].c, card2[i].value);
    if(i!=n-1) printf(" ");
  }
  printf("\n");

  if(isStable(card1, card2, n)){
    printf("Stable\n");
  } else {
    printf("Not stable\n");
  }

  return 0;
}