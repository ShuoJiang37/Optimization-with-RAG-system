#include <stdio.h>

void printArray(int var[], int num) {
  int i;
  for (i = 0; i < num; i++) {
      if (i > 0) printf(" ");
      printf("%d", var[i]);
  }
  printf("\n");
}

void selectionSort(int var[], int num) {
  int i, j;
  int iMin;
  int tmp;
  int counter = 0;
  for (i = 0; i < num; i++) {
    iMin = i;

    for (j = i; j < num; j++) {
      if (var[j] < var[iMin]) {
        iMin = j;
      }
    }
    if (iMin != i) counter++;
    tmp = var[i];
    var[i] = var[iMin];
    var[iMin] = tmp;
  }
  printArray(var, num);
  printf("%d\n", counter);

}

int main(void) {
    int i, num;
    scanf("%d", &num);
    int var[num];
    for (i = 0; i < num; i++) scanf("%d", &var[i]);

    selectionSort(var, num);

    return 0;
}
