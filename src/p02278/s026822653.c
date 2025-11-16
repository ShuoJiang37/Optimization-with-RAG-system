#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
#define N 1001
#define MAX 10001
 
#define min(x,y) ( (x) < (y) ? (x) : (y) )
 
int compare (const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}
 
int main () {
  int n;
  int array[N];
  int sortedArray[N];
   
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &array[i]);
    sortedArray[i] = array[i];
  }
  qsort(sortedArray, n, sizeof(int), compare);
  int gMin = sortedArray[0];
 
  int index[MAX];
  for (int i = 0; i < n; i++) {
    index[sortedArray[i]] = i;
  }
 
  bool isUsed[N];  
  for (int i = 0; i < n; i++) {
    isUsed[i] = false;
  }
 
  int totalCost = 0;
  for (int i = 0; i < n; i++) {
    if (isUsed[i]) {
      continue;
    }
 
    int cycleSum  = 0;
    int cycleCard = 0;
    int cycleMin  = MAX;
    int pos = i;
    while (1) {
      isUsed[pos] = true;
 
      cycleCard++;      
      cycleSum += array[pos];
      cycleMin  = min(cycleMin, array[pos]);
 
      pos = index[array[pos]];
 
      if (isUsed[pos]) {
    break;
      }
    }
 
    if ( 2*(cycleMin + gMin) < (cycleCard - 1)*(cycleMin - gMin) ) {
      totalCost += cycleSum + cycleMin + (cycleCard + 1)*gMin;
    } else {
      totalCost += cycleSum + (cycleCard - 2)*cycleMin;
    }
  }
 
  printf("%d\n", totalCost);
   
  return 0;
}
