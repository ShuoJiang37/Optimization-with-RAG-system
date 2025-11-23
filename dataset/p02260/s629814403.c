#include<stdio.h>
void selectionSort(int*,int);
int main(){
	int a,b,i,j;
	int array[100];
	scanf("%d",&a);
	for(i=0;i<a;i++){
		scanf("%d",&array[i]);
	}
	selectionSort(array,a);
	return 0;
}

void selectionSort(int* x,int y){
	int i,j,count=0,flag;
	int minj;
	int change;
	for(i=0;i<=y-1;i++){
		minj=i;
		flag=0;
		for(j=i;j<=y-1;j++){
			if(x[j]<x[minj]){
				minj=j;
				flag=1;
			}
		}
		if(flag==1){
			count++;
		}
		change=x[i];
		x[i]=x[minj];
		x[minj]=change;
	}
	for(i=0;i<y;i++){
		if(i==y-1){
			printf("%d\n",x[i]);
		}
		else{
			printf("%d ",x[i]);
		}
	}
	printf("%d\n",count);
}
