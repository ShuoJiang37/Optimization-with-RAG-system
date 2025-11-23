#include <stdio.h>

void Print(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(i>0)
            printf(" ");
        printf("%d",a[i]);
    }
    printf("\n");
}

void InsertionSort(int a[],int n)
{
    int i,temp,j;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0;j--)
        {
            if(a[j]>temp)
               {
                   a[j+1]=a[j];
                   a[j]=temp;
               }

        }
        Print(a,n);
    }
}

int main()
{
    int a[100];
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {
        if(i>0)
            scanf(" ");
        scanf("%d",&a[i]);
    }
    Print(a,n);
    InsertionSort(a,n);
    return 0;
}