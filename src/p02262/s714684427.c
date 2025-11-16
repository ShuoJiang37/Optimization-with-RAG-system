#include <stdio.h>
int g[]={1,4,13,40,121,364,1093,3280,9841,29524,88573,265720,797161,2391484};
int i,n,A[1000000],m,cnt;
void f(int g){
    int i,j,v;
    for(i=g;i<n;i++){
        v=A[i];
        for(j=i-g;j>=0&&A[j]>v;j-=g){
            A[j+g]=A[j];
            cnt++;
        }
        A[j+g]=v;
    }
}
int main(){
    for(scanf("%d",&n);i<n;scanf("%d",A+i++));
    for(m=0;g[m]<=n;m++);
    printf("%d\n",m);
    for(i=0;i<m;f(g[m-i-1]),printf("%d ",g[m-i++-1]));
    printf("\n%d\n",cnt);
    for(i=0;i<n;printf("%d\n",A[i++]));
}