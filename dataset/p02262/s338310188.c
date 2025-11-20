#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<math.h>
#define scani(x) scanf("%d",&x)
#define scanc(x) scanf("%s",x)

#define printi(x) printf("%d",x)
#define printin(x) printf("%d\n",x)
#define printc(x) printf("%s",x)
#define repd(i,n,m) for(int i = n; i > m; i--)
#define repu(i,n,m) for(int i = 0; i < m; i++)
#define allprintu(i,n,m,a) for(int i = 0; i < m; i++){if(i != m-1){printf("%d ",a[i]);}else{printf("%d\n",a[i]);}}
#define allprintd(i,n,m,a) for(int i = n; i > m; i--){if(i != 0){printf("%d ",a[i]);}else{printf("%d\n",a[i]);}}
int cnt;

void insertionsort(int a[], int n, int g){
	int v;
	int j;
	repu(i,g,n){
		v = a[i];
		j = i - g;
		while(j>=0 && a[j]>v){
			a[j+g] = a[j];
			j = j - g;
			cnt++;
		}
		a[j+g] = v;
	}
}

void shellsort(int a[], int n){
	cnt = 0;
	int j;
	int g[100];
	int box = 1;
	for(j = 0;box <= n; j++){
		g[j] = box;
		box = box*3 + 1;
	}
	int m = j;
	repd(i,m-1,-1){
		insertionsort(a,n,g[i]);
	}
	printin(m);
	allprintd(i,m-1,-1,g);
	printin(cnt);
	repu(i,0,n){
		printin(a[i]);
	}
	
}

int main(void){
	int n;
	scani(n);
	int a[n];
	repu(i,0,n){
		scani(a[i]);
	}
	shellsort(a,n);
	return 0;
}
