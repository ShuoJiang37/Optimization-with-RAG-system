#include<stdio.h>
#include<stdlib.h>

void merge(int A[],int n,int left,int mid,int right);
void mergeSort(int A[],int n,int left,int right);

int count=0;
int L[500000],R[500000];

int main(void)
{
  int n,i;
  int *A;

  scanf("%d",&n);

  A=calloc(n,sizeof(int));

  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
    }

  mergeSort(A,n,0,n);

  for(i=0;i<n;i++)
    {
      printf("%d",A[i]);

      if(i!=n-1)
	{
	  putchar(' ');
	}
      
      else
	{
	  putchar('\n');
	}
    }
  
   printf("%d\n",count);

   free(A);
  
  return 0; 
}

void merge(int A[],int n,int left,int mid,int right)
{
  int n1=mid-left;
  int n2=right-mid;
  int i,j,k;
    
  for(i=0;i<n1;i++)
    {
      L[i]=A[left+i];
    }
  
  for(i=0;i<n2;i++)
    {
      R[i]=A[mid+i];
    }
      
  L[n1]=1000000000;
  R[n2]=1000000000;
      
  i = 0;
  j = 0;
      
  for(k=left;k<right;k++)
    {
      count++;
	
      if (L[i]<=R[j])
	{
	  A[k]=L[i];
	  i=i+1;
	}
      
      else
	{
	  A[k]=R[j];
	  j=j+1;
	}
    }
}
  
void mergeSort(int A[],int n,int left,int right)
{
  if (left+1<right)
    {
      int mid=(left+right)/2;
	
      mergeSort(A,n,left,mid);
      mergeSort(A,n,mid,right);
      merge(A,n,left,mid,right);
    }
}

