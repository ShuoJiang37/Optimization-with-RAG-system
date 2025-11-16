#include<stdio.h>

typedef struct card{
	char mark;
	int num;
}card;

void swap(card a[],int x,int y){
	card temp=a[x];
	a[x]=a[y];
	a[y]=temp;
	return;
}

void bubbleSort(card a[],int n){
	int i,j;
	
	for(i=n-1;i>=0;i--){
		for(j=0;j<i;j++){
			if(a[j].num > a[j+1].num){
				swap(a,j,j+1);
			}
		}
	}
	
	return;
}

void selectionSort(card a[],int n){
	int i,j;
	int min;
	int idx;
	
	for(i=0;i<n;i++){
		min=1000;
		for(j=i+1;j<n;j++){
			if(min > a[j].num){
				idx=j;
				min=a[j].num;
			}
		}
		if(a[i].num > min){
			swap(a,i,idx);
		}
	}
	
	return;
}

int is_stable(card a[],card b[],int n){
	for(int i=0;i<n;i++){
		if(a[i].mark!=b[i].mark)return 0;
	}
	return 1;
}

int main(){
	int n,i;
	char temp[5];
	card C[36];
	card D[36];
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%s",temp);
		C[i].mark=temp[0];
		C[i].num=temp[1]-'0';
		D[i]=C[i];
	}
	
	bubbleSort(C,n);
	
	for(i=0;i<n-1;i++)
		printf("%c%d ",C[i].mark,C[i].num);
	printf("%c%d\n",C[n-1].mark,C[n-1].num);
	
	printf("Stable\n");
	
	
	selectionSort(D,n);
	
	for(i=0;i<n-1;i++)
		printf("%c%d ",D[i].mark,D[i].num);
	printf("%c%d\n",D[n-1].mark,D[n-1].num);
	
	if(is_stable(C,D,n))
		printf("Stable\n");
	else 
		printf("Not stable\n");
		
	return 0;
	
}
