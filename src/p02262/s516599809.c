#include<stdio.h>
int cnt=0,m=0,G[100];
void insertionsort(int a[],int n,int g){
    int i,j,v;
    for(i=g;i<n;i++){
        v=a[i];
        j=i-g;
        while(j>=0&&a[j]>v){
            a[j+g]=a[j];
            j=j-g;
            cnt++;
        }
        a[j+g]=v;
    }
}
void makeg(int n){
    int i;
    G[0]=1;
    for(i=0;G[i]<=n;i++){
        G[i+1]=G[i]*3+1;
        m++;
    }
}
void shellsort(int a[],int n){
  int i;
  makeg(n);
  for(i=m-1;i>=0;i--)insertionsort(a,n,G[i]);
}
int main(){
    int n,i,a[1000000];
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    shellsort(a,n);
    printf("%d\n",m);
    for(i=m-1;i>0;i--)printf("%d ",G[i]);
    printf("%d\n%d\n",G[0],cnt);
    for(i=0;i<n;i++)printf("%d\n",a[i]);
    return 0;
}
