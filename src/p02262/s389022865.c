#include <stdio.h>

void ShellSort(int A[],int N);
void insertionSort(int A[],int N,int g);

int cnt=0;
int g[1000];
int m;

int main(void){
	int i,N;
	scanf("%d",&N);
	int A[N];
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
		}
		
	ShellSort(A,N);
	
    printf("%d\n",m);
	for(i=m-1;i>=0;i--){
	if(i<m-1){
		printf(" ");
	}
	  printf("%d",g[i]);
	}
    printf("\n");
	printf("%d\n",cnt);
	for(i=0;i<N;i++){
		printf("%d\n",A[i]);
	}
	return 0;
}

void ShellSort(int A[],int N){
	int i;
	g[0]=1;
	for(i=0;;i++){
		if(g[i]>N){
			break;
		}
			g[i+1]=g[i]*3+1;
			m++;
	}
	
	for(i=m-1;i>=0;i--){
		insertionSort(A,N,g[i]);
	}
}

void insertionSort(int A[],int N,int g){
	int i,v,j;
	for(i=g;i<=N-1;i++){
		v=A[i];
		j=i-g;
		while(j>=0 && A[j]>v){
			A[j+g]=A[j];
			j=j-g;
			cnt++;
		}
		A[j+g]=v;
	}
}
