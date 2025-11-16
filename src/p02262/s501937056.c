#include<stdio.h>


void insertion(int x[], int n, int g);
void shell(int x[], int n);
#define a 10000000
int cnt;
int main(void){

	int n, i;
	int x[a];

	scanf("%d", &n);
	for(i = 0;i<n;i++){
		scanf("%d", &x[i]);
	}
	shell(x, n);
	printf("%d\n", cnt);
	for(i = 0;i<n;i++){
		printf("%d\n", x[i]);
	}
			//printf("%d", x[n-1]);

	return 0;

}

void insertion(int x[], int n, int g){
	int i, j,v;
	for(i = g;i<n;i++){
		v = x[i];
		j = i-g;
		while(j>=0 && x[j] >v){
			x[j+g] = x[j];
			j = j-g;
			cnt++;
		}
		x[j+g] = v;
	}
}

void shell(int x[], int n){
	int i;
	
	int m = 0;
	int g[1000000];
	g[0] =1;
	for(m=1;3*g[m-1]+1 <=n;m++){
		g[m] = 3*g[m-1]+1;
	}
	printf("%d\n", m);
	cnt =0;
	for(i=m-1;i>0;i--){
		printf("%d ", g[i]);
		insertion(x, n, g[i]);
	}

	printf("%d\n", g[0]);
	insertion(x, n, g[0]);
	
	//printf("\n");

}
