#include <stdio.h>
#include <string.h>
#include <math.h>
#define rep(i,l,n) for(i=l;i<n;i++)

int main(void){
	int n,a[1010],i,j,k,v;
	
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",&a[i]);
	
	rep(i,0,n){
		v=a[i];
		j=i-1;
		while(j>=0 && a[j]>v){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
		rep(k,0,n-1) printf("%d ",a[k]);
		printf("%d\n",a[n-1]);
	}
	
	
	return 0;
}