#include<stdio.h>
int main()
{
    int i,j,n,a[100],t,s,mini,p;
    while(scanf("%d",&n)!=EOF)
    {
        s=0;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++)
        {
            mini=i;p=0;
            for(j=i;j<n;j++)
                if(a[j]<a[mini])
                    {mini=j;p=1;}
            if(p==1)
            {t=a[i];a[i]=a[mini];a[mini]=t;s++;}
        }
        for(i=0;i<n-1;i++)
            printf("%d ",a[i]);
        printf("%d\n%d\n",a[n-1],s);
    }
    return 0;
}

