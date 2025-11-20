#include <stdio.h>
int SInsertSort(int A[],int n,int g)
{
    int k,c,cnt=0;
    for(int i=g-1;i<n;i++)
    {
        k=i;
        c=A[k];
        while (k>g-1 && c<A[k-g])
        {
            A[k]=A[k-g];
            k-=g;
            cnt++;
        }
        A[k]=c;
    }
    return cnt;
}
int A[1000010];
int main()
{
    int n,cnt=0,j,g[101];
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&A[i]);
    g[0]=1;
    for( j=0;g[j]<=n;j++) g[j+1]=g[j]*3+1;
    for(int i=j-1;i>-1;i--)cnt+=SInsertSort(A,n,g[i]);
    printf("%d\n",j);
    for(int i=j-1;i>-1;i--)printf("%d ",g[i]);
    printf("\n");
    printf("%d\n",cnt);
    for(int i=0;i<n;i++)printf("%d\n",A[i]);
    return 0;
}

