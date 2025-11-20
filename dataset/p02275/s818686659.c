#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define K 10005
#define LEN 2000005
int numbers[LEN];
int sortedNums[LEN];

void countingSort(int n){
  int C[K];
  for(int i = 0; i <= K; ++i){
    C[i] = 0;
  }
  for(int i = 0; i < n; ++i){
    ++C[numbers[i]];
  }
  for(int i = 1; i <= K; ++i){
    C[i] = C[i] + C[i - 1];
  }
  for(int i = 0; i < n; ++i){
    sortedNums[C[numbers[i]] - 1] = numbers[i];
    --C[numbers[i]];
  }
}
void printArray(int *array, int n){
  for(int i = 0; i < n; ++i){
    printf("%d", array[i]);
    if(i != n - 1)
      printf(" ");
  }
  printf("\n");
}
int main(){
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &numbers[i]);
  } 
  countingSort(n);
  printArray(sortedNums, n);
  return 0;
}

