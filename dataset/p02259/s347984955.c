#include<stdio.h>
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int a[102];
        int i,j,t,sum=0;
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0; i<n-1; i++)
        {
            for(j=0; j<n-1-i; j++)
            {
                if(a[j]>a[j+1])
                {
                    t=a[j];
                    a[j]=a[j+1];
                    a[j+1]=t;
                    sum++;
                }
            }
        }
        for(i=0; i<n; i++)
        {
            if(i==n-1)
                printf("%d\n%d\n",a[i],sum);
            else
                printf("%d ",a[i]);
        }
    }
    return 0;
}

