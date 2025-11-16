#include<stdio.h>
int main()
{
    int n,a[100],key,i,j,l,d=0;
     scanf("%d",&n);

        for (i=0;i<n;i++)
        scanf("%d",&a[i]);
        for(i=0;i<n-1;i++)
        {
           for(j=0;j<n-i-1;j++)
           {
               if(a[j]>a[j+1])
               {
                   key=a[j];
                   a[j]=a[j+1];
                   a[j+1]=key;
                   d++;
               }
           }
        }
        printf("%d",a[0]);
        for(l=1;l<n;l++)
            printf(" %d",a[l]);
        printf("\n");
        printf("%d\n",d);
    return 0;
}
