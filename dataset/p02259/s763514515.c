#include<stdio.h>
#define PI 100
int main()
{
    int i,j,t,k;
    int n;
    int a[PI];
    while(scanf("%d",&n)==1)
     {
         k=0;
         for(i=0;i<n;i++)
          scanf("%d",&a[i]);
        for(i=0;i<n-1;i++)
        {
           for(j=1;j<n-i;j++)
            {
                if(a[j]<a[j-1])
                {
                   t=a[j];
                   a[j]=a[j-1];
                   a[j-1]=t;
                    k++;
                }
            }
        }
        for(i=0;i<n-1;i++)
         {
            printf("%d ",a[i]);
         }
         printf("%d\n",a[n-1]);
        printf("%d\n",k);
     }
     return 0;
}

