#include<stdio.h>
void BubbleSort(int A[],int length)
{
    int i,j,t,count=0;
    for(i=0;i<=length-1;i++)
    {
        for(j=length-1;j>=i+1;j--)
        {
            if(A[j]<A[j-1])
            {
                t=A[j];
                A[j]=A[j-1];
                A[j-1]=t;
                count++;
            }
        }
    }
    for(i=0;i<length-1;i++)
    {
        printf("%d ",A[i]);
    }
    printf("%d\n",A[i]);
    printf("%d\n",count);
}
int main()
{
    int a[10000],n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    BubbleSort(a,n);
}

