#include <stdio.h>

int bubbleSort(int *,int);
void swap(int *,int *);
int main(void){
	int i,n;
	int count;
	int a[100];
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	
	count=bubbleSort(a,n);
	
	for(i=0;i<n;i++){
		printf("%d",a[i]);
		if(i<n-1)
			printf(" ");
	}
	printf("\n");
	printf("%d\n",count);
	
	
	return 0;
}

int bubbleSort(int *a,int n){
	int i;
	int count=0,flag=1;
	while(flag){
		flag=0;
		for(i=n-1;i>0;i--){
			if(a[i]<a[i-1]){
				swap(&a[i],&a[i-1]);
				flag=1;
				count++;
			}
		}
	}
	
	return count;
}


void swap(int *px,int *py){
	int tmp=*px;
	*px=*py;
	*py=tmp;
}