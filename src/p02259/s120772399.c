#include <stdio.h>
#include <stdlib.h>

int main(){
  int A[100];
  int N, i, j, temp, number=0, flag=1;

  scanf("%d", &N);
  if(N < 1 || 100 < N)
    exit(1);

  for(i = 0; i < N; i++){
    scanf("%d", &A[i]);
    if(A[i] < 0 || 100 < A[i])
      exit(2);
  }

  while(flag){
    flag = 0;
    for(j = N - 1; 0 < j; j--){
      if(A[j] < A[j-1]){
	temp = A[j];
	A[j] = A[j-1];
	A[j-1] = temp;
	flag = 1;
	number++;
      }
    }
  }

  for(i = 0; i < N-1; i++)
    printf("%d ", A[i]);
  printf("%d\n", A[i]);
  printf("%d\n", number);

  return 0;
}