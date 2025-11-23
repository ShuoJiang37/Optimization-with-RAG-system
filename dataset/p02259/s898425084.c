#include <stdio.h>
int main(void){

  int i,j,a,n,count= 0;
  int A[100];
  int temp = 0;

  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }


  for(i = 0; i < n-1; i++){
    for(j = n-1; j >= i+1; j--){
      if(A[j] < A[j-1]){
        temp = A[j];
        A[j] = A[j-1];
        A[j-1] = temp;
        count++;
      }
    }
  }
  for(i = 0; i < n; i++){
    printf("%d",A[i]);
    if(i != n - 1){
      printf(" ");
    }
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}