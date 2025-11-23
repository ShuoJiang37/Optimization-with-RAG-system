#include<stdio.h>
int main()
{
  int n,i,j, a[110],temp,cnt,mini;
    while(scanf("%d",&n)==1)
    {
      cnt=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n;i++)
        {
            mini=i;
            for(j=i;j<n;j++)
            if(a[j]<a[mini])
            {
                mini=j;
            }
                if(i!=mini)
                {
                 temp=a[i];
                a[i]=a[mini];
                a[mini]=temp;
                cnt++;
                }
        }
        for(i=0;i<n;i++)
           {
             printf("%d",a[i]);
             if(i<n-1)
                printf(" ");
           }
           printf("\n%d\n",cnt);
    }
    return 0;
    }