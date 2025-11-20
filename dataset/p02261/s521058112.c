#include<stdio.h>
int main()
{
    int m,mi;
    int a[40],b[40],c[40],d[40];
    char ac[40],bc[40],t;
    while(scanf("%d",&m)!=EOF)
    {
        int i,j,x;
        int r=1,flag=1;
        getchar();
        for(i=0; i<m; i++)
        {
            c[i]=i;
            d[i]=i;
            scanf("%c%d",&ac[i],&a[i]);
            getchar();
            b[i]=a[i];
            bc[i]=ac[i];
        }
        for(i=0; i<m; i++)
        {
            for(j=m-1; j>=i+1; j--)
                if(a[j]<a[j-1])
                {
                    x=a[j-1];
                    a[j-1]=a[j];
                    a[j]=x;
                    x=c[j-1];
                    c[j-1]=c[j];
                    c[j]=x;
                    t=ac[j-1];
                    ac[j-1]=ac[j];
                    ac[j]=t;
                }
        }
        for(i=0; i<m-1; i++)
        {
            printf("%c%d ",ac[i],a[i]);
            if(a[i]==a[i+1]&&c[i]>c[i+1])
                r=0;
        }
        printf("%c%d\n",ac[i],a[i]);
        if(flag)
            printf("Stable\n");
        else
            printf("Not stable\n");
        for(i=0; i<m; i++)
        {
            mi=i;
            for(j=i; j<m; j++)
                if(b[j]<b[mi])
                {
                    mi=j;
                }
            if(b[i]>b[mi])
            {
                x=b[i];
                b[i]=b[mi];
                b[mi]=x;
                x=d[i];
                d[i]=d[mi];
                d[mi]=x;
                t=bc[i];
                bc[i]=bc[mi];
                bc[mi]=t;
            }
        }
        for(i=0; i<m-1; i++)
        {
            printf("%c%d ",bc[i],b[i]);
            if(b[i]==b[i+1]&&d[i]>d[i+1])
                flag=0;
        }
        printf("%c%d\n",bc[i],b[i]);
        if(flag)
            printf("Stable\n");
        else
            printf("Not stable\n");
    }
}
