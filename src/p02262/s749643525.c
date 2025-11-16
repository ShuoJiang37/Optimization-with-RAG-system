#include <stdio.h>
long long cnt=0;
int l;
int a[1000000];
int n=0;
int m=0;
int G[100]={1};


void insertionsort(int a[],int n,int g){
    for(int i=g;i<n;i++){
        int v=a[i];
        int j=i-g;
        while(j>=0&&a[j]>v){
            a[j+g]=a[j];
            j=j-g;
            cnt++;
        }
        a[j+g]=v;
    }
}
void shellsort(int a[], int n){
  
    int i=1;
    
    while(3*G[i-1]+1<n){
        G[i]=G[i-1]*3+1;
        i++;
    }
    m=i;
    
    for(int i=m-1;i>=0;i--)
        insertionsort(a,n,G[i]);
    
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    cnt=0;
    
    shellsort(a,n);
    printf("%d\n",m);
    for(int i=1;i<=m;i++){
        if(i!=1)
            printf(" ");
        printf("%d",G[m-i]);
    }
    printf("\n");
    printf("%lld\n",cnt);
    for(int i=0;i<n;i++)
        printf("%d\n",a[i]);
    return 0;
    
    
}

