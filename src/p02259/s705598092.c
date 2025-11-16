#include<stdio.h>

int bubblesort(int A[],int n)
{
    int count=0;
    int flag=1;
    for(int i=0;flag;i++)
    {
        flag=0;
        for(int j=0;j<n-i-1;j++)
        {
          if(A[j]>A[j+1])
          {
              int tmp=A[j];
              A[j]=A[j+1];
              A[j+1]=tmp;
              count++;
              flag=1;
          }
        }
    }
    return count;
}

int main()
{
    int n;
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++)scanf("%d",&A[i]);
    int count = bubblesort(A,n);
    for(int i=0;i<n;i++)
    {
        if(i)printf(" ");
        printf("%d",A[i]);

    }
    printf("\n%d\n",count);
    return 0;
}

