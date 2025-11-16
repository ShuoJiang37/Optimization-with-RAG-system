#include <stdio.h>
#include <string.h>
#define MAX 10000
int B[MAX],T[MAX+1];

void sort(int A[], int n){
	int f=1;
	int tmp;
	while(f==1){
		f = 0;
		for(int j=n-1;j>=1;j--){
			if(A[j]<B[j-1]){
				tmp=A[j-1];
				A[j-1]=A[j];
				A[j]=tmp;
				f=1;
			}
		}
	}
}

int min(int a,int b){
    if(a<b){
    	return a;
    }
    return b;
}

int solve(int A[], int n, int s){
	
	int ans=0;
	int V[MAX];
	for(int i=0;i<n;i++){
		B[i]=A[i];
		V[i]=0;
	}
	
	sort(B ,n);
	
	for(int i=0;i<n;i++){
		T[B[i]]=i;
	}
	for(int i=0;i<n;i++){
		if(V[i]==1){
			continue;
		}
		int cur=i;
		int S=0;
		int m=MAX;
		int an=0;
		
		while(1){
			V[cur]=1;
			an++;
			int v=A[cur];
			m=min(m,v);
			S+=v;
			cur=T[v];
			if(V[cur]){
				break; 
			}
		}
		ans+=min(S+(an-2)*m,m+S+(an+1)*s);
		
	}
	
	return ans;
	
}


int main(void){
	int n, s=MAX;
	scanf("%d", &n);
	int A[n];
	for(int i=0 ; i<n ; i++){
		scanf("%d",&A[i]);
		s = min(s,A[i]);
	}
	printf("%d\n",solve(A, n, s));
	return 0;
}
