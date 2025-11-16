#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define N 1000000

void mergeSort(int [ ], int , int);
void merge(int [ ], int , int , int );

int cnt=0;

int main()
{
  int i,S[N],n;

  while(1)
    {
      scanf("%d",&n);
      if(n <= N && n > 0) break;
    }

  for(i=0;i<n;i++)
      scanf("%d",&S[i]);

  mergeSort(S,0,n);

  for(i=0;i<n-1;i++)
    printf("%d ",S[i]);
  
  printf("%d\n%d\n",S[i],cnt);
  
  return 0;
}

void mergeSort(int A[ ], int left, int right)
{
  int mid;
  if(left+1 < right)
    {   
      mid = (left + right) / 2;
      mergeSort(A,left,mid);
      mergeSort(A,mid,right);
      merge(A,left,mid,right);
    }
}

void merge(int A[ ], int left, int mid, int right)
{
int i,j,k,n1,n2;
int *sl,*sr;

  n1 = mid - left;
  n2 = right - mid;

  sl = malloc(sizeof(int) * n1 + 1);
  sr = malloc(sizeof(int) * n2 + 1);
  
  for (i = 0; i < n1; i++)
    sl[i] = A[left + i];
  
  sl[n1] = (int)INFINITY;
  
  for (j = 0; j < n2;j++)
    sr[j] = A[mid + j];
  
  sr[n2] = (int)INFINITY;
  i = 0;         
  j = 0;       

  for (k = left; k < right; k++)
    {
      if (sl[i] <= sr[j])
	{
	  A[k] = sl[i];
	  i++;
	}
      else
	{
	  A[k] = sr[j];
	  j++;
	}
      cnt++;
    }

  free(sl);
  free(sr);
}



