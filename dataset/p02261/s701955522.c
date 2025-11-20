#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 64
#define CHK 16

typedef struct {
  char mark;
  int num;
} card_t;

void BubbleSort(card_t* C, int N);
void SelectionSort(card_t* C, int N);
int verifyStab(card_t* C, card_t* Ccopy, int N);

int main(void){
  int N, i;
  char tmp[4];
  card_t C[SIZE], Ccopy[SIZE];
  
  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    scanf("%s", tmp);
    C[i].mark = tmp[0];
    C[i].num = atoi(&tmp[1]);
  }
  for (i = 0; i < N; i++)
    Ccopy[i] = C[i];

  BubbleSort(C, N);
  for (i = 0; i < N; i++) {
    printf("%c%d", C[i].mark, C[i].num);
    if (i < N - 1)
      printf(" ");
  }
  printf("\n");

  // verify a bubble stability
  if (verifyStab(C, Ccopy, N))
    printf("Stable\n");
  else
    printf("Not stable\n");

  // set back a array unsorted
  for (i = 0; i < N; i++)
    C[i] = Ccopy[i];
  
  SelectionSort(C, N);
  for (i = 0; i < N; i++) {
    printf("%c%d", C[i].mark, C[i].num);
    if (i < N - 1)
      printf(" ");
  }
  printf("\n");

  // verify a selection stability
  if (verifyStab(C, Ccopy, N))
    printf("Stable\n");
  else
    printf("Not stable\n");

  return 0;
}

void BubbleSort(card_t* C, int N){
  int i, j;
  card_t tmp;
  for (i = 0; i < N; i++) {
    for (j = N - 1; i < j; j--) {
      if (C[j].num < C[j - 1].num) {
	// swap mark
	tmp.mark = C[j].mark;
	C[j].mark = C[j - 1].mark;
	C[j - 1].mark = tmp.mark;
	// swap num
	tmp.num = C[j].num;
	C[j].num = C[j - 1].num;
	C[j - 1].num = tmp.num;
      }
    }
  }
}

void SelectionSort(card_t* C, int N){
  int i, j, minj;
  card_t tmp;
  for (i = 0; i < N; i++) {
    minj = i;
    for (j = i; j < N; j++) {
      if (C[j].num < C[minj].num)
	minj = j;
    }
    // swap mark
    tmp.mark = C[i].mark;
    C[i].mark = C[minj].mark;
    C[minj].mark = tmp.mark;
    // swap num
    tmp.num = C[i].num;
    C[i].num = C[minj].num;
    C[minj].num = tmp.num;
  }
}

int verifyStab(card_t* C, card_t* Ccopy, int N){
  int stbFlg = 1, skipFlg, i, j, k = 0, checkNum[CHK] = {0};
  char markOri[SIZE] = {0}, markSort[SIZE] = {0};
  
  for (i = 0; i < N - 1; i++) {
    // confirm whether a number is checked
    skipFlg = 0;
    for (j = 0; j < k; j++) {
      if (Ccopy[i].num == checkNum[j]) {
	skipFlg = 1;
	break;
      }
    }

    if (!skipFlg) {
      // create a original mark array
      strncat(markOri, &Ccopy[i].mark, 1);
      for (j = i + 1; j < N; j++) {
	if (Ccopy[j].num == Ccopy[i].num)
	  strncat(markOri, &Ccopy[j].mark, 1);
      }
      // create a sorted mark array
      for (j = 0; j < N; j++) {
	if (C[j].num == Ccopy[i].num)
	  strncat(markSort, &C[j].mark, 1);
      }

      // comapare Original with Sorted
      if (strcmp(markOri, markSort) != 0) {
	stbFlg = 0;
	break;
      }

      // add a checked number to array
      checkNum[k] = Ccopy[i].num;
      k++;
    
      // initializing mark array
      memset(markOri, 0, sizeof(markOri));
      memset(markSort, 0, sizeof(markSort));
    }
  }
  return stbFlg;
}