#include<stdio.h>

void intsertSort(int *array,int num){
	int i,j,k,tmp;
	for(i=1;i<num;i++){
		
		//********
		for(k=0;k<num;k++){
			printf("%d",array[k]);
			if(k!=num-1){
				printf(" ");
			}
		}printf("\n");
		//********
		
		tmp = array[i];
		j=i-1;
		while(j>=0 && array[j]>tmp){
			array[j+1] = array[j];
			j--;
		}
		array[j+1]=tmp;
		
	}
	
	//********
	for(k=0;k<num;k++){
		printf("%d",array[k]);
		if(k!=num-1){
			printf(" ");
		}
	}printf("\n");
	//********
}

int main(){
	int num,i,array[100];
	
	scanf("%d",&num);
	
	for(i=0;i<num;i++){
		scanf("%d",&array[i]);
	}
	
	intsertSort(array,num);
	
	return 0;
}