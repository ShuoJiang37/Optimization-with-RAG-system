#include <stdio.h>
#include <string.h>
#include <math.h>
#define rep(i,l,n) for(i=l;i<n;i++)

int main(void){
	int flag,a[105],i,j,k,n,c;
	
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",&a[i]);
	
	k=0;
	flag=1;
	while(flag){
		flag=0;
		for(j=n-1;j>0;j--){
			if(a[j]<a[j-1]){
				c=a[j-1];
				a[j-1]=a[j];
				a[j]=c;
				flag=1;
				k++;
			}
		}
	}
	rep(i,0,n-1) printf("%d ",a[i]);
	printf("%d\n",a[n-1]);
	printf("%d\n",k);
	return 0;
}