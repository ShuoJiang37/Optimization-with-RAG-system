#include <stdio.h>

void printArray(int array[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    if (i == n - 1) {
      printf("%d\n", array[i]);
    } else {
      printf("%d ", array[i]);
    }
  }
  return;
}

int main() {
  int i, n, array[100];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", array + i);
  }
  for (i = 1; i < n; i++) {
    printArray(array, n);
    int key = array[i];
    int j = i - 1;
    while (j >= 0 && array[j] > key) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = key;
  }
  printArray(array, n);
  return 0;
}
