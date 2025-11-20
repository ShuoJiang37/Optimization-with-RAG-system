#include<stdio.h>
#include<stdlib.h>
void insertionSort(int*,int,int*);
void ShellSort(int,int *);
int count = 0;
int temp = 0; 
int temp_temp;
int h[14];
int main(void){
	int num,*arr,i,j;
	scanf("%d",&num);
	arr = (int *)malloc(sizeof(int) * num);
	for(i=0;i<num;i++) scanf("%d",&arr[i]);
	ShellSort(num,arr);
	printf("%d\n",temp_temp+1);
	for(i=temp;i!=-1;i--)  i==0 ? printf("%d\n",h[i]):printf("%d ",h[i]);
	printf("%d\n",count);
	for(i=0;i<num;i++){
		printf("%d\n",arr[i]);
	}
	return 0;
	
}
void ShellSort(int num,int *arr){
	int i,j,n,m;//temp = 0;
	h[0]=1;
	for(i=0;i<14;i++){
		h[i+1] = 3 * h[i] +1;
	//	if(11==i) printf("%d\t%d\n",h[i],i);
     //		printf("%d\n",h[i+1]);
		}
	for(i=0;i<14;i++){
		if(num < h[i]){temp = i-1;break;}
		}
//	printf("%d\n",h[temp]);
/*	for(i=0;i<h[temp];i++){	
		printf("%d!!\n",i);
		insertionSort(arr,num,&h[i]);
	}
*/
	for(i=temp;i!=-1;i--){
		if(i==temp){/*printf("%d\n",temp+1);*/temp_temp = temp;}
		//i==0 ? printf("%d\n",h[i]):printf("%d ",h[i]);
		insertionSort(arr,num,&h[i]);
	}
}
void insertionSort(int *arr,int num,int *h){
	int i,j,v;
//	printf("!%d\n",*h);
//	printf("!!\n");
	for(i=(*h);i<num;i++){
	//	printf("%d\n",i);
	//	printf("%d\n",arr[i]);
		v = arr[i];
		j = i - (*h);
	//	printf("!!\n");
		while(j >= 0 && arr[j] > v){
			arr[j+(*h)] = arr[j];
			j = j - (*h);
			count++;
	//		printf("!!\n");
		}
		arr[j+(*h)] = v;	
	//		printf("abc\n");
	}
}