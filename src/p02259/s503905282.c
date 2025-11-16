#include<stdio.h>
int bubbleSort(int a[],int N);
int main(){
	int a[100],N;
	scanf("%d",&N);
	int i;
	for(i=0;i<N;i++){
		scanf("%d",&a[i]);
		
	}
	int t=bubbleSort(a,N);
	for(i=0;i<N-1;i++){
		printf("%d ",a[i]);
	}
	printf("%d\n",a[N-1]);
	printf("%d\n",t);
	return 0;
} 

int bubbleSort(int a[],int N){
	int i,j,temp,flag=0;
	for(i=0;i<N-1;i++){
		for(j=0;j<N-1-i;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				flag++;
			}
		}
	}
	return flag;
}
