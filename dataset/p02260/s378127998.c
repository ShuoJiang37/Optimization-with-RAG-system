#include<stdio.h>
int main()
{
    int i,j,num[101],n;
    while(scanf("%d",&n)!=EOF)
    {
        int s=0;
        for(i=1;i<=n;i++)
            scanf("%d",&num[i]);
        for(i=1;i<=n;i++)
        {
            int min=i;
            for(j=i;j<=n;j++)
            {
                if(num[j]<num[min])
                    min=j;
            }
            if(i!=min)
            {
                int t=num[i];
                num[i]=num[min];
                num[min]=t;
                s++;
            }
        }
        for(i=1;i<n;i++)
            printf("%d ",num[i]);
        printf("%d\n",num[n]);
        printf("%d\n",s);
    }
}

