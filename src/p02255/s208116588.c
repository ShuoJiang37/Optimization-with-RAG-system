#include<stdio.h>

void print(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(i)printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");
}

void insertsort(int A[],int n)
{
   int i,j,tmp;
   for(i=0;i<n-1;i++)
   {
       j=i+1;
       tmp=A[j];
       while(j>0 && A[j-1]>tmp)
       {
           A[j]=A[j-1];
           j--;
       }
       A[j]=tmp;
       print(A,n);
   }

}

int main()
{
    int n;
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++)scanf("%d",&A[i]);
    print(A,n);
    insertsort(A,n);

    return 0;
}

