#include<stdio.h>

#define MAX 100

int main(){
  int i,flag,n,count,A[MAX + 1];

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);

  count = 0;
  flag = 1;

  while(flag){
    flag = 0;
    for(i=n-1;i>=0;i--){
      if(A[i] < A[i - 1]){
	A[n] = A[i];
	A[i] = A[i - 1];
	A[i - 1] = A[n];
	count++;
	flag = 1;
      }
    
    }

  }
  for(i=0;i<n;i++){
    if(i < n - 1)printf("%d ",A[i]);
    else printf("%d\n%d\n",A[i],count);
  }

  return 0;
}