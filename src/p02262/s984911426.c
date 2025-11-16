#include<stdio.h>

int cnt;

void insertion(int a[], int n, int g){
	int i, j, tmp;
	for(i=g; i<n; i++){
		tmp=a[i];
		j=i-g;
		while(j>=0&&a[j]>tmp){
			a[j+g]=a[j];
			j=j-g;
			cnt++;
		}
		a[j+g]=tmp;
	}
}

void shell(int a[], int n){
	int i;
	cnt=0;
	int m=1;
	int g[n];
	g[0]=1;
	while(1){
		g[m]=g[m-1]*3+1;
		if(g[m]>n)break;
		m++;
	}

	for(i=m-1; i>=0; i--){
		insertion(a, n, g[i]);
	}
	//出力
	printf("%d\n", m);
	for(i=m-1; i>=0; i--){
		if(i==0){
			printf("%d\n", g[i]);
		}else if(i>0){
			printf("%d ", g[i]);
		}
	}
	printf("%d\n", cnt);
	for(i=0; i<n; i++){
		printf("%d\n", a[i]);
	}	
}


int main(){
	int n, i;
	scanf("%d", &n);
	int nx[n];

	for(i=0; i<n; i++){
		scanf("%d", &nx[i]);
	}

	shell(nx, n);

	return 0;
}
