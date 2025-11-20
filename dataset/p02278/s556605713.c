#include <stdio.h>
int solve(int A[]);
int min(int a,int b);
void sort(int B[]);
#define MAX 10000
int A[MAX],B[MAX],T[MAX+1];
int n,s;

int main(void){
	int i;
	scanf("%d",&n);
	int A[n];
	s=MAX;
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
		s=min(s,A[i]);
	}
	
	int ans=solve(A);
	
	printf("%d\n",ans);
	return 0;
}


int solve(int A[]){
	
	int ans=0;
	int V[MAX];
	for(int i=0;i<n;i++){
		B[i]=A[i];
		V[i]=0;
	}
	
	sort(B);
	
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

int min(int a,int b){
    if(a<b){
    	return a;
    }
    return b;
}

void sort(int A[]){
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
