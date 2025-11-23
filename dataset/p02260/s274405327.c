#include <stdio.h>
#include <string.h>
#include <math.h>
#define rep(i,l,n) for(i=l;i<n;i++)

int main(void){
	int n,i,j,a[105],minj,k,c;
	
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",&a[i]);
	
	k=0;
	rep(i,0,n){
		minj=i;
		rep(j,i,n){
			if(a[j]<a[minj]) minj=j;
		}
		if(minj!=i){
			k++;
			c=a[i];
			a[i]=a[minj];
			a[minj]=c;
		}
	}
	rep(i,0,n-1) printf("%d ",a[i]);
	printf("%d\n",a[n-1]);
	printf("%d\n",k);
	return 0;
}