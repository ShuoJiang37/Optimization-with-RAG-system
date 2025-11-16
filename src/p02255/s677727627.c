#include<stdio.h>
int main()
{
    int n,i,j,k,key,s[100];
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0; i<n; i++)
            scanf("%d",&s[i]);
        for(i=0; i<n; i++)
        {
            key=s[i];
            j=i-1;
            while(j>=0&&s[j]>key)
            {
                s[j+1]=s[j];
                j--;
            }
            s[j+1]=key;
            for(k=0; k<n; k++)
            {
                printf("%d",s[k]);
                if(k!=n-1)
                    printf(" ");
                else
                    printf("\n");
            }
        }
    }
    return 0;
}

