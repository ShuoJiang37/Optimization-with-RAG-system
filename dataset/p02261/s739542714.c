#include <stdio.h>

 typedef struct Card {char suit; int value;} CARD;

void printStructArray(CARD var[], int num) {
  int i;
  for (i = 0; i < num; i++) {
      if (i > 0) printf(" ");
      printf("%c%d", var[i].suit, var[i].value);
  }
  printf("\n");
}

void bubbleSort(CARD var[], int num) {
  int i, j;
  CARD tmp;

  for (i = 0; i < num; i++) {
    for (j = num -1; j > i; j--) {
        if (var[j].value < var[j - 1].value) {
            tmp = var[j];
            var[j] = var[j - 1];
            var[j - 1] = tmp;
        }
    }
  }
}

void selectionSort(CARD var[], int num) {
  int i, j, iMin;
  CARD tmp;
  for (i = 0; i < num; i++) {
    iMin = i;
    for (j = i; j < num; j++) {
      if (var[iMin].value > var[j].value) {
        iMin = j;
      }
    }
    tmp = var[i];
    var[i] = var[iMin];
    var[iMin] = tmp;
  }
}

int isStable(CARD var1[], CARD var2[], int num) {
  for (int i = 0; i < num; i++) {
    if (var1[i].suit != var2[i].suit) {
      return -1;
    } 
  }
  return 0;
}

int main(void) {
  int i, num;
  scanf("%d", &num);
  CARD varBubble[num];
  CARD varSelection[num];
  getchar();
  for (i = 0; i < num; i++) {
    scanf("%c%d", &varBubble[i].suit, &varBubble[i].value);
    varSelection[i] = varBubble[i];
    getchar();
  }
  
  bubbleSort(varBubble, num);
  printStructArray(varBubble, num);
  printf("Stable\n");
  
  selectionSort(varSelection, num);
  printStructArray(varSelection, num);
  if (isStable(varBubble, varSelection, num) < 0) {
    printf("Not stable\n");
  } else {
    printf("Stable\n");
  }

  return 0;
}
