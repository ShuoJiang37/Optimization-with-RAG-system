#include<stdio.h>
int a[100];
int j,n;
void output()
{
    int i;
    printf("%d",a[0]);
    for(i=1;i<n;i++)
    {
        printf(" %d",a[i]);
    }
    printf("\n");
}
int main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    output();
    for(i=1;i<n;i++)
    {
        int key=a[i];
        j=i-1;
        while(j>=0&&a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
        output();
    }
    return 0;
}
