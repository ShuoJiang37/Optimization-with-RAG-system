#include<stdio.h>
#include<stdbool.h>

#define MAX 1000
#define VMAX 10000

int j,n,s;
int A[MAX];
int B[MAX];
int T[VMAX+1];

void Sort(int C[]){
	int flag=1;
	int temp;
	while(flag==1){
		flag=0;
		for(j=n-1; j>=1;j--){
			if(C[j]<C[j-1]){
				temp=C[j-1];
				C[j-1]=C[j];
				C[j]=temp;
				flag=1;
			}
		}
	}
}

int min(int a, int b){
	if(a<b){return a;}
	else{return b;}
}

int solve(){
	int ans=0;
	int i;
	bool V[MAX];
	
	for(i=0;i<n;i++){
		B[i]=A[i];
		V[i]=false;
	}
	Sort(B);
	for(i=0;i<n;i++){
		T[B[i]]=i;
	}
	
	for(i=0;i<n;i++){
		if(V[i])continue;
		int cur=i;
		int S=0;
		int m=VMAX;
		int an=0;
		while(1){
			V[cur]=1;
			an++;
			int v=A[cur];
			m=min(m,v);
			S+=v;
			cur=T[v];
			if(V[cur]){break;}
		}
		ans+=min(S+(an-2)*m,m+S+(an+1)*s);
	}
	
	return ans;
}

int main(void){
	int i,ans;
	scanf("%d",&n);
	
	s=VMAX;
	
	for(i=0; i<n; i++){
		scanf("%d",&A[i]);
		s=min(s,A[i]);
	}
	
	ans=solve();
	
	printf("%d\n",ans);
	
	return 0;
}
