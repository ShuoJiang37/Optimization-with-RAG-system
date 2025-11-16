#include<stdio.h>
int main()
{
    int n,i,j,mini,t,x=0;
    int a[100];
    while(scanf("%d",&n)!=EOF)
    {
        x=0;
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(i=0; i<n-1; i++)
        {
            mini=i;
            for(j=i; j<n; j++)
                if(a[j]<a[mini])
                    mini=j;
            if(i!=mini)
            {
                t=a[i];
                a[i]=a[mini];
                a[mini]=t;
                x++;
            }
        }
        printf("%d",a[0]);
        for(i=1; i<n; i++)
            printf(" %d",a[i]);
        printf("\n");
            printf("%d\n",x);
    }
    return 0;
}

