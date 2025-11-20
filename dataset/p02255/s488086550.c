#include<stdio.h>
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int a[102];
        int i,j;
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        int k;
        for(k=0; k<n; k++)
        {
            if(k==n-1)
                printf("%d\n",a[k]);
            else
                printf("%d ",a[k]);
        }
        for(i=1; i<n; i++)
        {
            int key=a[i];
            j=i-1;
            while(j>=0&&key<a[j])
            {
                a[j+1]=a[j];
                j--;
            }
            a[j+1]=key;
            for(k=0; k<n; k++)
            {
                if(k==n-1)
                    printf("%d\n",a[k]);
                else
                    printf("%d ",a[k]);
            }
        }

    }
    return 0;
}

