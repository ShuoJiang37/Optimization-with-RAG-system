#include<stdio.h>
void InsertionSort(int A[],int length)
{
    int i,j,key,k;
    for(k=0; k<length-1; k++)
        printf("%d ",A[k]);
    printf("%d\n",A[k]);
    for(i=1; i<=length-1; i++)
    {
        key=A[i];
        j=i-1;
        while(j>=0&&A[j]>key)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
        for(k=0; k<length-1; k++)
            printf("%d ",A[k]);
        printf("%d\n",A[k]);
    }
}
int main()
{
    int a[10000],i,n;
    scanf("%d",&n);
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    InsertionSort(a,n);
    return 0;
}
