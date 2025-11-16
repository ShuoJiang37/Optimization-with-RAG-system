#include<stdio.h>
#define N 1000000
 
int a[N];
int cnt=0;
int G[N];
int m=1;
 
void insertionSort(int n,int g){
    for(int i=g;i<n;i++){
        int v=a[i];
        int j=i-g;
        while(j>=0 && a[j] > v){
            a[j+g]=a[j];
            cnt++;
            j=j-g;
        }
        a[j+g]=v;
    }
    return;
}
 
 
void shellSort(int n){
    int temp=n;
     
    G[0]=1;
     
    while(1){
        G[m]=G[m-1]*3+1;
        if(G[m] > n)break;
        m++;
    }
     
    for(int i=m-1;i>=0;i--)
        insertionSort(n,G[i]);
     
    return;
}
 
 
 
int main(){
    int n,i;
     
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
     
    shellSort(n);
     
     
    printf("%d\n",m);
    for(i=m-1;i>0;i--)
        printf("%d ",G[i]);
    printf("%d\n",G[0]);
     
    printf("%d\n",cnt);
     
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);
     
    return 0;
}
