#include <stdio.h>
#include <stdlib.h>
int main()
{
  int *A;
  int N,p,q,r,key;

  scanf("%d",&N);
  A=(int *)malloc(N*sizeof(int));

  for(p=0; p<=N-1; p++)
    {
      scanf("%d",&A[p]);
    }

  for(p=1; p<=N-1;p++)
    {
      for(r=0; r<=N-2; r++)
	{
	  printf("%d ",A[r]);
	}
      printf("%d",A[r]);
      printf("\n");
      key=A[p];
      q=p-1;
      while(q>=0 && A[q]>key)
	{
	  A[q+1]=A[q];
	  q--;
	}
      A[q+1]=key;
    }

  for(r=0; r<=N-2; r++)
	{
	  printf("%d ",A[r]);
	}
  printf("%d",A[r]);
  printf("\n");

  return 0;
}

      

