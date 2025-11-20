#include<stdio.h>
#include<math.h>

#define L 1000000
int cnt = 0;

	int debug;


void insertionSort(int A[L], int n, int g){
	for(int i = g; i < n; i++){
		int v = A[i];
		int j = i - g;
		while(j >= 0 && A[j] > v){
			A[j + g] = A[j];
			j = j - g;
			cnt++;
		}
		A[j + g] = v;
	}
}

void shellSort(int A[L],int n){
	int m = 0;
	int G[n];

	int o = 0;
	for(o = 0; o < 100; o++){
		m = m * 3 + 1;
		if(m > n){
			break;
		}
	}
	G[0] = (m - 1) / 3;
	m = 1;
	for(int i = o - 1; i > 0; i--){
		G[o - i] = (G[o - 1 - i] - 1) / 3;
		m++;
	}
	
	for(int i = 0; i < m; i++){
//		printf("i = %d",i);
		insertionSort(A, n, G[i]);
	}
	printf("%d\n",m);
	printf("%d",G[0]);
	for(int i = 1; i < m;i++){
		printf(" %d",G[i]);
	}
	printf("\n");
}

int main(){
	int n;
	int val[L];
	
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&val[i]);
//		printf("val[%d] = %d",i,val[i]);
	}
//	printf("n = %d",n);
	shellSort(val,n);
	
	printf("%d\n",cnt);
	for(int i = 0; i < n; i++){
		printf("%d\n",val[i]);
	}
	
	return 0;

}
