#include<stdio.h>
#include<string.h>
#define N 36
#define False 0
#define True 1

typedef struct  {
  char picture[3];
  int value;
} cards;

void BubbleSort(cards *C, int n) {
  int i, j;
  cards tmp;

  for(i = 0; i < n; i++) {
    for(j = n-1; j > i; j--) {
      if(C[j].value < C[j-1].value) {
        tmp = C[j];
        C[j] = C[j-1];
        C[j-1] = tmp;
      }
    }
  }
  for(i = 0; i < n; i++) {
    if(i > 0) printf(" ");
    printf("%s", C[i].picture);
  }
  printf("\n");
}

void SelectionSort(cards *C, int n) {
  int i, j, mini;
  cards tmp;

  for(i = 0; i < n; i++) {
    mini = i;
    for(j = i; j < n; j++) {
      if(C[j].value < C[mini].value) mini = j;
    }
    tmp = C[i];
    C[i] = C[mini];
    C[mini] = tmp;
  }

  for(i = 0; i < n; i++) {
    if(i > 0) printf(" ");
    printf("%s", C[i].picture);
  }
  printf("\n");
}

int isStable(cards *A, cards *B, int n) {
  int i, j, a, b;

  for(i = 0; i < n; i++) {
    for(j = i+1; j < n; j++) {
      for(a = 0; a < n; a++) {
        for(b = a+1; b < n; b++) {
          if(A[i].value == A[j].value && strcmp(A[i].picture, B[b].picture) == 0
            && strcmp(A[j].picture, B[a].picture) == 0)
          return False;
        }
      }
    }
  }
  return True;
}



int main() {
  int i, j, n;
  cards C[N], C1[N], C2[N];

  scanf("%d",&n);
  for(i = 0; i < n; i++) {
    scanf("%s", C[i].picture);
    C[i].value = C[i].picture[1] - 48;
    strcpy(C1[i].picture, C[i].picture);
    strcpy(C2[i].picture, C[i].picture);
    C1[i].value = C[i].value;
    C2[i].value = C[i].value;
  }

  BubbleSort(C1, n);
  if(isStable(C, C1, n) == False) printf("Not stable\n");
  else printf("Stable\n");
  SelectionSort(C2, n);
  if(isStable(C, C2, n) == False) printf("Not stable\n");
  else printf("Stable\n");

  return 0;
}