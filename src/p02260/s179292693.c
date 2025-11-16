#include<stdio.h>

int sort(int R[],int n)
{
    int count=0;
    int tmp,min;
    for(int i=0;i<n-1;i++)
    {
        min=i;
        for(int j=i;j<n;j++)
        {
            if(R[j]<R[min])min=j;
        }
        tmp=R[i];
        R[i]=R[min];
        R[min]=tmp;
        if(i!=min)count++;
    }
    return count;
}

void print(int R[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(i>0)printf(" ");
        printf("%d",R[i]);
    }
    printf("\n");
}
int main()
{
    int n;
    scanf("%d",&n);
    int R[n];
    for(int i=0;i<n;i++)scanf("%d",&R[i]);
    int count=sort(R,n);
    print(R,n);
    printf("%d\n",count);
}

