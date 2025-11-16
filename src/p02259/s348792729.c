#include<stdio.h>
main()
{
    int n,i,j,k,temp,swap=0,a[105];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<n;i++)
        for(j=0;j<n-i;j++)
    {
        if(a[j]>a[j+1])
        {
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
            swap++;
        }
    }
    for(i=0;i<n-1;i++)
        printf("%d ",a[i]);
    printf("%d\n",a[n-1]);

    printf("%d\n",swap);
    return 0;
}