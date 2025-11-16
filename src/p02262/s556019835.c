#include <stdio.h>
int insertionSort(int *,int,int);
int main (){
    int n,x[1000000],i,j,cnt=0,m,g[100];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x[i]);
    }
    j=0;
    for(i=1;i<=n;i=3*i+1){
        g[j]=i;
        j++;
        cnt++;
    }
    m=cnt;
    cnt=0;
    for(i=1;i<=m;i++){
        cnt=insertionSort(x,n,g[m-i]);
    }
    printf("%d\n",m);
    for(i=1;i<=m;i++){
        if(i-1){
            printf(" ");
        }
        printf("%d",g[m-i]);
    }
    printf("\n");
    printf("%d\n",cnt);
    for(i=0;i<n;i++){
        printf("%d\n",x[i]);
    }
    return 0;

}

int insertionSort(int *x,int n,int g){
    int i,v,j;
    static int cnt;
    for(i=g;i<n;i++){
        v=x[i];
        j=i-g;
        while((j>=0) && (x[j]>v)){
            x[j+g]=x[j];
            j=j-g;
            cnt++;
        }
        x[j+g]=v;
    }
    return cnt;
}
