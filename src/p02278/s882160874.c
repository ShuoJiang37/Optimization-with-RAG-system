#include <stdio.h>

#define MAX 1000
#define VMAX 10001

int n,a[MAX],s;
int b[MAX],t[VMAX];

int min(int a,int b){
    if(a<b)return a;
    else return b;
}

int partition(int* a,int p,int r){
    int i,j,x,t;
    x=a[r];
    i=p-1;
    for(j=p;j<r;j++){
        if(a[j]<=x){
            i++;
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    t=a[i+1];
    a[i+1]=a[r];
    a[r]=t;
    return i+1;
}

void quicksort(int* a,int p,int r){
    int q;
    if(p<r){
        q=partition(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}

int solve(){
    int ans=0,v[MAX];
    for(int i=0;i<n;i++){
        b[i]=a[i];
        v[i]=0;
    }
    quicksort(b,0,n-1);
    for(int i=0;i<n;i++){
        t[b[i]]=i;
    }
    for(int i=0;i<n;i++){
        if(v[i])continue;
        int cur=i;
        int d=0;
        int m=VMAX;
        int an=0;
        while(1){
            v[cur]=1;
            an++;
            int e= a[cur];
            m=min(m,e);
            d+=e;
            cur=t[e];
            if(v[cur])break;
        }
        ans+=min(d+(an-2)*m,m+d+(an+1)*s);
    }
    return ans;
}

int main(void){

    scanf("%d",&n);
    s=VMAX;
    for(int  i=0;i<n;i++){
        scanf("%d",&a[i]);
        s=min(s,a[i]);
    }
    printf("%d\n",solve());

    return 0;
}
