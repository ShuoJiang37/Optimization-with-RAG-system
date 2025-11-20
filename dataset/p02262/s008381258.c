#include<stdio.h>
#include<string.h>
int cnt;

void insertionSort(int *A, int n, int g){

	int i, v, j;

	for(i=g; i<=n-1; i++){
		v=A[i];
		j=i-g;

		while(0<=j && v<A[j]){
			A[j+g]=A[j];
			j=j-g;
			cnt++;
		}
		A[j+g]=v;
	}
}

void shellSort(int *A, int n){

	int g[500], i;

	g[0]=1;
  int m=0;
  cnt=0;
	for(m=1; 3*g[m-1]+1<n+1; m++)
  {
    g[m]=g[m-1]*3+1;
  }
	printf("%d\n", m);

	for(i=m-1; i>=0; i--) {
		if(i!=0){printf("%d ", g[i]);}
    	else{printf("%d\n", g[i]);}
		insertionSort(A, n, g[i]);
 	}
}

int main(){
	int n;
	scanf("%d", &n);
	int A[n];
	for(int k=0; k<n; k++){
		scanf("%d", &A[k]);
	}
	shellSort(A, n);
	printf("%d\n", cnt);
	for(int l=0; l<n; l++)
  {
    printf("%d\n", A[l]);
  }

}

