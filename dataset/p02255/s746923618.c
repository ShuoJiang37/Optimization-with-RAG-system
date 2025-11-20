#include<stdio.h>
int main()
{
    int i,t,a[100];
    while(scanf("%d",&t)!=EOF)
    {
        for(i=0;i<t;i++)
            scanf("%d",&a[i]);
        for(i=0;i<t-1;i++)
            printf("%d ",a[i]);
        printf("%d\n",a[t-1]);
        for(i=1;i<t;i++)
        {
            int temp=a[i];
            int j;
            for(j=i-1;j>=0&&temp<a[j];j--)
            {
                a[j+1]=a[j];
            }
            a[j+1]=temp;
            for(j=0;j<t-1;j++)
                printf("%d ",a[j]);
            printf("%d\n",a[t-1]);
        }

    }
    return 0;
}

