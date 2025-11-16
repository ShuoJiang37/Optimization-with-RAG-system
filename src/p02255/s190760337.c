#include<stdio.h>
int main()
{
    int i,j,k,l,t,N,a[100];
    scanf("%d",&N);
    for(i=0;i<N;i++)
        scanf("%d",&a[i]);
    for(j=0;j<N;j++)
    {
        t=a[j];
        l=j-1;
        while(l>=0&&a[l]>t)
        {
            a[l+1]=a[l];
            l--;
        }
        a[l+1]=t;
        for(k=0;k<N;k++)
        {
            if(k==N-1)
                printf("%d\n",a[k]);
            else printf("%d ",a[k]);
        }
    }
    return 0;
}
