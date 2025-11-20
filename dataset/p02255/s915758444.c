#include<stdio.h>
int main()
{
    int N,a[100],i,k,j,t;
    scanf("%d",&N);
    for(i=0;i<N;i++)
        scanf("%d",&a[i]);
    for(t=0;t<N-1;t++)
            printf("%d ",a[t]);
        printf("%d\n",a[t]);
    for(i=1;i<N;i++)
    {
        k=a[i];
        j=i-1;
        while(j>=0&&a[j]>k)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=k;
        for(t=0;t<N-1;t++)
            printf("%d ",a[t]);
        printf("%d\n",a[t]);
    }
    return 0;
}
