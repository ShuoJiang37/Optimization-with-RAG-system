#include<stdio.h>

int cnt;

void insertionSort(int *, int, int);
void shellSort(int *, int);

int main()
{
	int i, n;
	scanf("%d", &n);
	int A[n];
	for(i=0; i<n; i++) scanf("%d", &A[i]);
	shellSort(A, n);
	printf("%d\n", cnt);
	for(i=0; i<n; i++) printf("%d\n", A[i]);
	return 0;
}

void insertionSort(int A[], int n, int g)
{
	int i, j, v;
	for(i=g; i<n; i++){
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

void shellSort(int A[], int n) //一定の間隔 g だけ離れた要素のみを対象とした挿入ソートである insertionSort(A, n, g) を、最初は大きい値から g を狭めながら繰り返します。
{
	int i, m;
	int G[100];
	G[0]=1;
	cnt=0;
	for(m=1; G[m-1]*3+1<=n; m++){ //G[m]がnより小さい間
		G[m]=G[m-1]*3+1;
	}
	printf("%d\n", m);
	for(i=m-1; i>=0; i--) {
		if(i==0) printf("%d\n", G[i]);
		else printf("%d ", G[i]);
		insertionSort(A, n, G[i]);
  }
}
