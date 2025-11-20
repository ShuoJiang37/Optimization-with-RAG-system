#include <stdio.h>
 
 
int main()
{
  int i,j,tmp,A[1000],n,count = 0;
 
  scanf("%d",&n);
 
  for(i =  0;i < n;i ++){

      scanf("%d",&A[i]);
    }
   
  for(i = 0;i < n;i ++){
      for(j = 0;j < n - i - 1;j ++)
    {
      if(A[j] > A[j + 1]){
        tmp = A[j];
      A[j] = A[j + 1];
      A[j + 1] = tmp;
      count ++;
      }
 
    }
    }
 
  for(i = 0;i < n -1 ;i ++)
    {
      printf("%d ",A[i]);
    }
  printf("%d\n",A[i]);

  printf("%d\n",count);
 
  return 0;
}