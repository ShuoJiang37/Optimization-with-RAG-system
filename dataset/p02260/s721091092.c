#include<stdio.h>
int main()
{
    int i,c,r[100];
    int n,d,k,t,z=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&r[i]);
    }
    for(c=0;c<n-1;c++)
    {
        k=c;
        for(d=c+1;d<n;d++)
        {
            if(r[d]<r[k])
            {
                k=d;
            }
        }
        if(k!=c)
        {
            t=r[k];
            r[k]=r[c];
            r[c]=t;
            z++;
        }

    }
    for(c=0;c<n-1;c++)
    {
        printf("%d ",r[c]);
    }
    printf("%d\n",r[c]);
    printf("%d\n",z);
    return 0;
}


