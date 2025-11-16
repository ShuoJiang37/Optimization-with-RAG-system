#include <stdio.h>
#include <string.h>

int main()
{
  int N, i, j, x=0, minj;
  char A[36][2], C[36][2], a[2];

  scanf("%d",&N);
  for(j = 0 ; j < N ; j++){
    scanf("%s",A[j]);
  }

  for(j = 0 ; j < N ; j++){
    strcpy(C[j],A[j]);
  }
  
  for(i = 0 ; i < N-1 ; i++){
    for(j = N-1 ; j > i ; j--){
      if(A[j][1] < A[j-1][1]){
	a[0] = A[j][0];
	a[1] = A[j][1];
	A[j][0] = A[j-1][0];
	A[j][1] = A[j-1][1];
	A[j-1][0] = a[0];
	A[j-1][1] = a[1];
      }
    }
  }

  for(i = 0 ; i <= N-1 ; i++){
    for(j = 0 ; j < 2 ; j++){
      printf("%c",A[i][j]);
    }
    if(i < N-1){
    printf(" ");
    }
  }
  printf("\n");
  printf("Stable\n");
  
  for(i = 0 ; i < N-1 ; i++){
    minj = i;
    for(j = i ; j <= N-1 ; j++){
      if(C[j][1] < C[minj][1]){
	minj = j;
      }
    }
    a[0] = C[i][0];
    a[1] = C[i][1];
    C[i][0] = C[minj][0];
    C[i][1] = C[minj][1];
    C[minj][0] = a[0];
    C[minj][1] = a[1];
  }

  for(i = 0 ; i <= N-1 ; i++){
    for(j = 0 ; j < 2 ; j++){
      printf("%c",C[i][j]);
    }
    if(i < N-1){
    printf(" ");
    }
  }
  printf("\n");
  
  for(i = 0 ; i <= N-1 ; i++){
    for(j = 0 ; j < 2 ; j++){
      if(A[i][j] != C[i][j]){
	x = 1;
      }
    }
  }
  if(x == 0){
    printf("Stable\n");
  }
  else {
    printf("Not stable\n");
  }
 
  return 0;
}