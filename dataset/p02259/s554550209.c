#include<stdio.h>
int main(){
  int i, j, N, A[100]={0}, cnt = 0, temp;

  scanf("%d", &N);
  
  for(i = 0; i < N; i++)
    scanf("%d", &A[i]);

  for(i = 0; i < N - 1; i++){
    for(j = N - 1; j >= i + 1; j--){
      if(A[j] < A[j-1]){
	temp = A[j];
	A[j] = A[j-1];
	A[j-1] = temp;
	cnt++;
      }
    }
  }

  for(i = 0; i < N; i++){
    if(0 < i)   printf(" %d", A[i]);
    else        printf("%d", A[i]);
  }
  printf("\n%d\n", cnt);

  return 0;
}