#include<stdio.h>
int main()
{
    int i,j,k,n,temp,num,a[101];
    while(scanf("%d",&n)!=EOF)
    {
        num=0;
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(i=0; i<n; i++)
        {
            j=i;
            for(k=i+1; k<n; k++)
            {
                if(a[j]>a[k])
                {
                    j=k;
                }
            }
            if(j!=i)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
                num++;
            }

        }
        for(j=0; j<n-1; j++)
            printf("%d ",a[j]);
        printf("%d\n",a[n-1]);
        printf("%d\n",num);
    }
    return 0;
}

