#include<stdio.h>
int a[105];
int main()
{
    int m;
    while(scanf("%d",&m)!=EOF)
    {
        int i,j,min,x,t=0;
        for(i=0; i<m; i++)scanf("%d",&a[i]);
        for(i=0;i<m;i++)
            for(j=m-1; j>=0; j--)
                if(a[j]<a[j-1])
                {
                    x=a[j-1];
                    a[j-1]=a[j];
                    a[j]=x;
                    t++;
                }
        for(i=0; i<m-1; i++)printf("%d ",a[i]);
        printf("%d\n%d\n",a[i],t);

    }
    return 0;
}
