#include<stdio.h>
int main(){
  int i, j, flag, A[100], n, temp, cnt = 0;
  
  scanf("%d", &n);
  for(i = 0; i < n; i++)
    scanf("%d", &A[i]);
  
  flag = 1;
  i = 0;
  while(flag){
    flag = 0;
    for(j = n-1; j >= i+1; j--){
      if(A[j] < A[j-1]){
	temp = A[j];
	A[j] = A[j-1];
	A[j-1] = temp;
	flag = 1;
	cnt++;
      }
    }
    i++;
  }
  for(i = 0; i < n; i++){
    if(0 < i)   printf(" %d", A[i]);
    else        printf("%d", A[i]);
  }
  printf("\n%d\n", cnt);

  return 0;
}