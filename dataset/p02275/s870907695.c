#include<stdio.h>
#include<stdlib.h>

#define MAX 10000

int C[MAX+1];

void CountingSort(int A[],int B[],int num);

int main(void)
{
  int *A,*B;
  int i,j,num;

  scanf("%d",&num);

  A=calloc(num+1,sizeof(int));
  B=calloc(num+1,sizeof(int));

  CountingSort(A,B,num);

  for(i=1;i<=num;i++)
    {
      printf("%d",B[i]);

      if(i!=num)
	{
	  putchar(' ');
	}
      else
	{
	  putchar('\n');
	}
    }

  free(A);
  free(B);
  
  return 0;

}

void CountingSort(int A[],int B[],int num)
{
  int i,j;
  
  for(i=0;i<MAX;i++)
    {
      C[i]=0;
    }

  for(i=0;i<num;i++)
    {
      scanf("%d",&A[i+1]);
      C[A[i+1]]++;
    }

  for(i=1;i<MAX;i++)
    {
      C[i]=C[i]+C[i-1];
    }

  for(j=1;j<=num;j++)
    {
      B[C[A[j]]]=A[j];
      C[A[j]]--;
    }
}

