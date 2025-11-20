#include<stdio.h>
int main()
{
    int a[100];
    int i,j,t,n,count;
    while(~scanf("%d",&n))
    {
        count=0;
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(i=0; i<n-1; i++)
        {
            for(j=0; j<n-1-i; j++)
                if(a[j]>a[j+1])
                {
                    t=a[j];
                    a[j]=a[j+1];
                    a[j+1]=t;
                    count++;
                }

        }
        for(i=0; i<n-1; i++)
            printf("%d ",a[i]);
        printf("%d\n",a[i]);
        printf("%d\n",count);
    }
    return 0;
}

