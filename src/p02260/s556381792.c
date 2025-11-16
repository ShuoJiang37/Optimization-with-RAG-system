#include<stdio.h>
int main()
{
    int a[100];
    int n,i,j,x=0,mini;
    int temp;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        x=0;
        for(i=0; i<n-1; i++)
        {
            mini=i;
            for(j=i+1; j<n; j++)
            {
                if(a[j]<a[mini])
                {
                    mini=j;
                }
            }
            if(mini!=i)
            {
                temp=a[i];
                a[i]=a[mini];
                a[mini]=temp;
                x++;
            }
        }
         for(i=0; i<n-1; i++)
                printf("%d ",a[i]);
            printf("%d\n",a[n-1]);
            printf("%d\n",x);
    }
    return 0;
}

