#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

int main(){
  unsigned int *A_array, *B_array;

  int C_array[VMAX+1];
  int n, i, j;
  scanf("%d", &n);

  A_array = malloc(sizeof(int)*n+1);
  B_array = malloc(sizeof(int)*n+1);

  for ( i = 0; i <= VMAX; i++ ) C_array[i] = 0;

  for ( i = 0; i < n; i++ ){
    scanf("%d", &A_array[i + 1]);
    C_array[ A_array[i + 1]]++;
  }

  for ( i = 1; i <= VMAX; i++ ) C_array[i] = C_array[i] + C_array[i - 1];

  for ( j = 1; j <= n; j++ ){
    B_array[ C_array[ A_array[j]]] = A_array[j];
    C_array[ A_array[j]]--;
  }

  for ( i = 1; i <= n; i++ ){
    if ( i > 1 ) printf(" ");
    printf("%d", B_array[i]);
  }
  printf("\n");

  return 0;
}