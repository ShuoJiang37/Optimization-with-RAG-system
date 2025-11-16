#include<stdio.h>
int insSort(int *A,int n,int g)
{
    int i,cnt=0;
    for(i=g;i<n;i++){
        int v=A[i];
        int j=i-g;
        while(j>=0 && A[j]>v){
            A[j+g]=A[j];
            j=j-g;
            cnt++;
        }
       A[j+g]=v;
    }
    return cnt;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    int A[n];
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    int m=1, cnt=0;
    int G[13]={1};
    for(i=1;;i++){
        G[i]=G[i-1]*3+1;
        if(G[i]>n)break;
        m++;
    }
    printf("%d\n",m);
    for(i=m-1;i>=0;i--){
        if(i==0)printf("%d\n",G[i]);
        else printf("%d ",G[i]);
    }
    for(i=m;i>=0;i--){
        cnt += insSort(A,n,G[i]);
    }
    printf("%d\n",cnt);
    for(i=0;i<n;i++){
        printf("%d\n",A[i]);
    }
    return 0;
}