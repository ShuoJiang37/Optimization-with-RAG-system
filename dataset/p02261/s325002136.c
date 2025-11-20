#include <stdio.h>

typedef struct {
  char character;
  int value;
} card;

void BubbleSort(card *, int);
void SelectionSort(card *, int);
int isStable(card *, card *, int);

int main()
{
  int n, i;
  card C[36], C_in[36];

  scanf("%d", &n);
  for(i=0; i<n; i++) {
    scanf(" %c%d", &C[i].character, &C[i].value);
  }

  for(i=0; i<n; i++) {
    C_in[i] = C[i];
  }
  BubbleSort(C, n);
  SelectionSort(C_in, n);

  return 0;
}

void BubbleSort(card *C, int n)
{
  int i, j;
  card C_in[n], tmp;

  for(i=0; i<n; i++) {
    C_in[i] = C[i];
  }

  for(i=0; i<n; i++) {
    for(j=n-1; j>i; j--) {
      if(C[j].value < C[j-1].value) {
	tmp = C[j];
	C[j] = C[j-1];
	C[j-1] = tmp;
      }
    }
  }
  for(i=0; i<n; i++) {
    printf("%c%d", C[i].character, C[i].value);
    if(i == n-1) break;
    printf(" ");
  }
  isStable(C_in, C, n);

  return ;
}

void SelectionSort(card *C, int n)
{
  int i, j, min;
  card C_in[n], tmp;

  for(i=0; i<n; i++) {
    C_in[i] = C[i];
  }

  for(i=0; i<n; i++) {
    min = i;
    for(j=i; j<n; j++) {
      if(C[j].value < C[min].value)
	min = j;
    }
    tmp = C[i];
    C[i] = C[min];
    C[min] = tmp;
  }

  for(i=0; i<n; i++) {
    printf("%c%d", C[i].character, C[i].value);
    if(i == n-1) break;
    printf(" ");
  }
  isStable(C_in, C, n);

  return ;
}

int isStable(card *C_in, card *C, int n)
{
  int i, j, a, b, check = 1;

  for(i=0; i<n; i++) {
    for(j=i+1; j<n; j++) {
      for(a=0; a<n; a++) {
	for(b=a+1; b<n; b++) {
	  if((C_in[i].value == C_in[j].value) && (C_in[i].value == C[b].value && C_in[i].character == C[b].character) && (C_in[j].value == C[a].value && C_in[j].character == C[a].character))
	    check = 0;
	}
      }
    }
  }
  if(check == 1)
    printf("\nStable\n");
  else
    printf("\nNot stable\n");

  return ;
}