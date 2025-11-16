#include <stdio.h>

#define MAX 1000
#define VMAX 10000

int n, A[MAX], s;
int B[MAX], T[VMAX+1];

void sort(int A[]){
	int f = 1;
	int tmp;
	while(f){
		f = 0;
		for(int j = n-1; j >= 1; j--){
			if(A[j] < A[j-1]){
				tmp = A[j-1];
				A[j-1] = A[j];
				A[j] = tmp;
				f = 1;
			}
		}
	}
}


int min(int a, int b){
	if(a <= b) return a;
	else return b;
}

int solve(){
	int ans=0;
	int i;
	
	int V[MAX];
	for(i = 0; i < n; i++){
		B[i] = A[i];
		V[i] = 0;
	}
	sort(B);
	for(i = 0; i < n; i++)T[B[i]] = i;
	for(i = 0; i < n; i++){
		if(V[i]) continue;
		int cur = i;
		int S = 0;
		int m = VMAX;
		int an = 0;
		while(1){
			V[cur] = 1;
			an++;
			int v = A[cur];
			m = min(m, v);
			S += v;
			cur = T[v];
			if(V[cur])break;
		}
		ans += min(S+(an-2)*m, m+S+(an+1)*s);
	}
	return ans;
}

int main(void){
	scanf("%d", &n);
	s = VMAX;
	for(int i = 0; i < n; i++){
		scanf("%d", &A[i]);
		s = min(s, A[i]);
	}
	int ans = solve();
	
	printf("%d\n", ans);
	
	return 0;
}
