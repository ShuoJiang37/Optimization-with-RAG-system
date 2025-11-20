#include<stdio.h>
void trace(int a[],int n){
    int i;
    for(i=0;i<n;i++){
	if(i>0) printf(" ");
	printf("%d",a[i]);
    }
    printf("\n");
}

int bubbleSort(int a[],int n){
    int i,j,flag,tmp,count=0;
    flag=1;
    i=0;
    while(flag){
	flag=0;
	for(j=n-1;j>=i+1;j--){
	    if(a[j-1]>a[j]){
		tmp=a[j-1];
		a[j-1]=a[j];
		a[j]=tmp;
		flag=1;
		count++;
	    }
	}
    }
    trace(a,n);
    return count;
}
	
int main(void){
    int n,a[100],i,ans;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    ans=bubbleSort(a,n);
    printf("%d\n",ans);
    return 0;
}