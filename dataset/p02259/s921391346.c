#include<stdio.h>
int main()
{
    int a[100];
    int n,i,j,x,temp;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        x=0;
        for(i=n-1; i>0; i--)
        {
            for(j=0; j<i; j++)
            {
                if(a[j]>a[j+1])
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                    x++;
                }
            }
        }
        for(i=0; i<n-1; i++)
            printf("%d ",a[i]);
        printf("%d\n",a[n-1]);
        printf("%d\n",x);
    }
    return 0;
}

