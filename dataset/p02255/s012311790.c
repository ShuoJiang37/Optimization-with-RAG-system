#include<stdio.h>
int main()
{
    int i,j,key,length,m;
    int A[100];
    while(scanf("%d",&length)!=EOF)
    {
        for(i=0; i<=length-1; i++)
            scanf("%d",&A[i]);
        for(i=1; i<=length-1; i++)
        {
            printf("%d",A[0]);
            for(m=1; m<length; m++)
                printf(" %d",A[m]);
            printf("\n");
            key=A[i];
            j=i-1;
            while(j>=0&&A[j]>key)
            {
                A[j+1]=A[j];
                j--;
                A[j+1]=key;
            }
        }
        printf("%d",A[0]);
        for(i=1; i<length; i++)
            printf(" %d",A[i]);
        printf("\n");
    }
    return 0;
}

