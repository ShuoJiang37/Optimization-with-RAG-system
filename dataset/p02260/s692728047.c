#include<stdio.h>
void showData(int*,int);

int main()
{
	int a[100],i,j,tmp,count=0;
	int length,min_index=0;
	scanf("%d",&length);
	
	for(i=0; i<length; i++){
		scanf("%d",&a[i]);
	}
	
	for(i=0; i<length-1; i++){
		min_index=i;
		for(j=i+1; j<length; j++){
			if(a[min_index] > a[j]){
				min_index=j;
			}
		}
		
		if(min_index!=i){
			tmp=a[i];
			a[i]=a[min_index];
			a[min_index]=tmp;
			
			count++;
		}
	}
	showData(a,length);
	printf("%d\n",count);
        return 0;
}
void showData(int*array,int length){
	int i;
	for(i=0; i<length; i++){
		if(i<length-1) printf("%d ",array[i]);
		else printf("%d\n",array[i]);
	}
}
		