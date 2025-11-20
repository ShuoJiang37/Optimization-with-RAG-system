#include<stdio.h>

long cnt = 0;
void insertionSort(int a[], int n, int g){
	int i,j,k,v;

	for(i=g; i<n; i++){
		v = a[i];
		j = i-g;
		while(j>=0 && a[j]>v){
			a[j+g] = a[j];
			j = j-g;
			cnt++;
		}
		a[j+g] = v;
	}
}

void shellSort(int a[], int n){
	int i,j,m,x;
	int G[10000];
	m=0;
	x = 1;
	for(j=0; x<=n;j++){
		G[j] = x;
		x = 3*x+1;
		m++;
	}
	printf("%d\n",m);

	/*ここがおかしい(1 行目に整数 m、2 行目に m 個の整数 Gi(i=0,1,...,m−1) を空白区切りで出力してください。
3 行目に、G を用いた場合のプログラムが終了した直後の cnt　の値を出力してください)*/

	for(i=m-1; i>=0; i--){
		if(i==0){
			printf("%d\n",G[i]);
			break;
		}
		printf("%d ",G[i]);
	}

	for(i=m-1; i>=0; i--){
		insertionSort(a,n,G[i]);
	}
	printf("%d\n",cnt);

	for(i=0; i<n; i++){
		printf("%d\n",a[i]);
	}
}

int main(void){
	int i,n;

  scanf("%d",&n);

  int z[n];

  for(i = 0; i<n; i++){
    scanf("%d",&z[i]);
  }

  shellSort(z,n);

  return 0;
}

