#include<stdio.h>

int main(void){

	int n,i,max,min,tmp,j,v,k,z,x,cnt;
  cnt=0;
		z=0;
	x=1;
	scanf("%d",&n);
	int a[1000001],g[20];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	for(i=0; x<=n; i++) {
    g[i]=x;
    x=x*3+1;
    z++;
  }

for(k=z-1; k>=0; k--) {
	for(i=g[k];i<n;i++)
   {
		 v=a[i];
	   j=i-g[k];

	  	while(j>=0&&a[j]>v)
	  	{
	  	 a[j+g[k]]=a[j];
	  	 j=j-g[k];
	     cnt++;
	  	}
   	a[j+g[k]]=v;
   }
}
	 printf("%d\n",z);
	for(i=z-1; i>=0; i--) {
    printf("%d",g[i]);
    if(i){
			printf(" ");
		}
  }
	printf("\n%d\n",cnt);

  for(i=0; i<n; i++)
		{
			printf("%d\n",a[i]);
		}
	return 0;
}
