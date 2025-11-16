#include<stdio.h>
#include<string.h>
int main()
{
    int m,i,j,count=0,a[100];
    scanf("%d",&m);
    for(i=0; i<m; i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0; i<=m-1; i++)
    {
        for(j=m-1; j>=i+1; j--)
        {
            if(a[j]<a[j-1])
            {
                int temp;
                temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
                count++;
            }
        }
    }
    for(i=0; i<m-1; i++)
        printf("%d ",a[i]);
    printf("%d",a[m-1]);
    printf("\n");
    printf("%d\n",count);
}
