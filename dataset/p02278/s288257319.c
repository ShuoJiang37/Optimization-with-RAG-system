#include <stdio.h>
#include <stdlib.h>
#define N 10000
#define MIN(a, b) (a < b ? a : b)

int partition(int *A, int  p, int r){
	int i, j, x, temp;
	x = A[r];
	//printf("x:%d\n", x);
	i = p-1;
	for(j=p; j<r; j++){
		if(A[j]<=x){
			i=i+1;
			//A[i] と A[j] を交換
			temp=A[i];
			A[i]=A[j];
			A[j]=temp;
		}
	}
	//A[i+1] と A[r] を交換
	temp=A[i+1];
	A[i+1]=A[r];
	A[r]=temp;
	
	return i+1;
}

void quicksort(int *A, int  p, int r){
	int q;
	if(p<r){
		q = partition(A, p, r);
		quicksort(A, p, q-1);
		quicksort(A, q+1, r);
	}
}

int solve(int *A, int *B, int min, int n){
	int i, sum, c, m, ans=0;
	int X[N+1], C[N];
	for(i=0; i<n; i++) C[i]=0;
	quicksort(B, 0, n-1);
	
	for(i=0; i<n; i++) X[B[i]]=i;
	for(i=0; i<n; i++){
		if(C[i]) continue;
		int x=i;
		sum=0;
		m=N;
		c=0;
		while(1){
			C[x]=1;
			c++;
			int a=A[x];
			m=MIN(m, a);
			sum+=a;
			x=X[a];
			if(C[x]) break;
		}
		ans+=MIN(sum+(c-2)*m, m+sum+(c+1)*min);
	}
	return ans;
}

int main(void){
	int n, i, j, A[N], B[N], min=N;	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &A[i]);
		if(min>A[i]) min=A[i];
		B[i]=A[i];
	}
	printf("%d\n", solve(A, B, min, n));
	return 0;
}
