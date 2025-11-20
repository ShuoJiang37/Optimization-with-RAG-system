#include <stdio.h>

int cnt=0;
int m=0;
int G[1000000]={};

void insertion(int N,int a[],int g){
    int i,j,v;
    
    for(i=g; i<N; i++){
        v = a[i];
        j=i-g;
         
        while(j>=0 && a[j]>v){
            a[j+g]=a[j];
            j-=g;
            cnt++;
            a[j+g]=v;
        }
    }
}


void shell(int N,int a[]){
    int i;
    
    G[0]=1;
    
    for(m=1;m<15;m++){
        G[m]=G[m-1]*3+1;
        if(G[m]>N)break;
    }
    
    for(i=m-1;i>=0;i--){
        insertion(N,a,G[i]);
    }
    
}

int main(void){
    int i,N,a[1000000]={};
    
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    
    shell(N,a);
    
    printf("%d\n",m);
    for(i=m-1;i>=0;i--){
        printf("%d",G[i]);
        if(i==0)puts("");
        else printf(" ");
    }
    printf("%d\n",cnt);
    
    for(i=0;i<N;i++){
        printf("%d\n",a[i]);
    }
    
    return 0;
}


