#include<stdio.h>
int main()
{
    int N,A[110],i,j,temp,count=0,mini=0;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%d",&A[i]);
    }
    for(i=0;i<N;i++)
    {
        mini=i;
        for(j=i;j<N;j++)
        {
           if (A[j]<A[mini])
           {
               mini=j;
           }
        }
           if(i!=mini)
           {
               temp = A[i];
               A[i] = A[mini];
               A[mini] = temp;
               count++;
           }
        }
    for(i=0;i<N-1;i++)
        printf("%d ",A[i]);
        printf("%d",A[N-1]);

    printf("\n%d\n",count);
    return 0;
}