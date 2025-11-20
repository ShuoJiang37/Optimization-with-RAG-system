#include<stdio.h>
#include<malloc.h>
int main()
{
    int n,i,j,t,*s,x=0;
    scanf("%d",&n);
    s=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        scanf("%d",&s[i]);
    for(i=0;i<n-1;i++)
        for(j=0;j<n-1-i;j++)
            if(s[j]>s[j+1])
            {
                t=s[j];
                s[j]=s[j+1];
                s[j+1]=t;
                x++;
            }
    for(i=0;i<n-1;i++)
        printf("%d ",s[i]);
    printf("%d\n%d\n",s[n-1],x);

    return 0;
}
