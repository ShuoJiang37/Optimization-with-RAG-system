#include<stdio.h>
#include<stdbool.h>

#define MAX 1000
#define VMAX 10000

int n, A[MAX], s;
int B[MAX], T[VMAX+1];

int min(int a, int b){
    if(a>b) return b;
    else return a;
}


int solve(){
    int ans=0,i,j;
    bool V[MAX];
    
    for( i=0; i<n; i++){
        B[i]=A[i];
        V[i]=false;
    }
    
    for (i=0; i<n; i++) {
        for (j=i+1; j<n; j++) {
            if (B[i] > B[j]) {
                 int tmp =  B[i];
                B[i] = B[j];
                B[j] = tmp;
            }
        }
    }

    
    for(int i=0; i<n; i++) T[B[i]] =i;
    for(int i=0; i<n; i++){
        if(V[i]) continue;
        int cur=i;
        int S=0;
        int m=VMAX;
        int an=0;
        while(1){
            V[cur]=true;
            an++;
            int v=A[cur];
            m=min(m,v);
            S += v;
            cur=T[v];
            if( V[cur] ) break;
        }
        ans += min(S + (an-2) * m, m+S+ (an+1) * s);
    }
    return ans;
}



int main(){
    scanf("%d",&n);
    s=VMAX;
    for(int i=0; i<n; i++){
        scanf("%d",&A[i]);
        s=min(s,A[i]);
    }
    int ans = solve();
    printf("%d\n",ans);
    
    return 0;
}
