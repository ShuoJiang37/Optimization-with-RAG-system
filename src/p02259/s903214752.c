#include<stdio.h>
int main()
{
    int n,i,j,t,s[100];
    while(scanf("%d",&n)!=EOF)
    {
        int sum=0;
        for(i=0;i<n;i++)
            scanf("%d",&s[i]);
        for(i=0; i<n; i++)
        {
            for(j=n-1; j>i; j--)
            {
                if(s[j]<s[j-1])
                {
                    t=s[j];
                    s[j]=s[j-1];
                    s[j-1]=t;
                    sum++;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            printf("%d",s[i]);
            if(i!=n-1)
                printf(" ");
            else
                printf("\n");
        }
            
        printf("%d\n",sum);
    }
    return 0;
}
