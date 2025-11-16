#include <stdio.h>

void InsertionSort(int A[], int N, int g);
void shellSort(int A[],int n);

int cnt;
int A[1000000];

int main(void){
	
	int n;
	scanf("%d",&n);
	
	int i;
	
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	
	shellSort(A,n);
	
	printf("%d\n",cnt);
	
	for(i=0;i<n;i++){
		if(i>0) printf("\n");
		printf("%d",A[i]);
	}
	
	return 0;
}

void InsertionSort(int A[], int N, int g)
{

	int i,j,v;
	
	for(i=g;i<N;i++){
	
		v = A[i];
		j = i-g;
		
		while (j >= 0 && A[j] > v){
			
			A[j+g] = A[j];
			j=j-g;
			cnt++;

		}
		
		A[j+g] = v;
	
	}

}

void shellSort(int A[], int n)
{
	int G[100];
	int m;
	G[0]=1;
	
	for(m=1; 3*G[m-1]+1 <= n; m++){
		
		G[m] = 3*G[m-1]+1;
	}
	printf("%d\n",m);
	
	cnt=0;
	
	for(int i=m-1; i >=0 ; i--){
		if(i<m-1) printf(" ");
		printf("%d",G[i]);
		InsertionSort(A, n, G[i]);
	}	
	printf("\n");
}
