#include<stdio.h>
int main(){
  int i, j, N, A[100], mini, temp, cnt = 0, flag;
  
  scanf("%d", &N);
  
  for(i = 0; i < N; i++)
    scanf("%d", &A[i]);
  
  for(i = 0; i < N - 1; i++){
    mini = i;
    flag = 0;
    for(j = i; j < N; j++){
      if(A[j] < A[mini]){
	mini = j;
	flag = 1;
      }
    }
    temp = A[i];
    A[i] = A[mini];
    A[mini] = temp;
    if(flag == 1)   cnt++;
  }

  for(i = 0; i < N; i++){
    if(0 < i)   printf(" %d", A[i]);
    else        printf("%d", A[i]);
  }
  printf("\n%d\n", cnt);
  
  return 0;
}