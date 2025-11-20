#include <stdio.h>
#include <stdlib.h>

int main () {
  int *a, i, j, k, n, key;
  
  scanf("%d", &n);
  a = (int *)malloc(sizeof(int) * n);
  
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  
  for (k = 0; k < n; k++) {
    if (k >= 1) printf(" ");
    printf("%d", a[k]);
  }
  printf("\n");
    
  for (i = 1; i < n; i++) {
    key = a[i];
    j = i - 1;
    
    while (j >= 0 && a[j] > key) {
      a[j + 1] = a[j];
      j--;
    }
    
    a[j + 1] = key;
      for (k = 0; k < n; k++) {
    if (k >= 1) printf(" ");
    printf("%d", a[k]);
  }
  printf("\n");
  }
    

  
  free(a);
  
  return 0;
}