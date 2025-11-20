#include<stdio.h>

void qsort(int a[],int left,int right){
	
	int p=(left+right)/2;
	int pivot=a[p];
	int i,temp;
	if(left<right){
		p=left;
		pivot=a[p];
		for(i=left+1;i<=right;i++){
			if(a[i]<pivot){
				p++;
				temp=a[i];a[i]=a[p];a[p]=temp;//swap
			}
		}
		temp=a[left];a[left]=a[p];a[p]=temp;//swap
		qsort(a,left,p-1);
		qsort(a,p+1,right);
	}

}

int search(int key,int a[],int n){
	int i;
	for(i=0;i<n;i++){
		if(key==a[i])return i;
	}
	
	return i;
}

int isVisited(int v[],int n){
	int i;
	for(i=0;i<n;i++){
		if(v[i]!=1)return -1;
	}
	return 1;
}
	
int min(int a,int b){
	if(a<b)return a;
	return b;
}


int main(void){
	int n,i,j,minW,cost=0,w;
	int a[1000],b[1000],v[1000];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
		v[i]=0;
	}
	qsort(b,0,n-1);
	
	for(i=0;i<n;i++){	
		int x=i;
		int sum=0;
		int count=0;
		minW=10000;
		while(v[x]==0){
			v[x]=1;
			sum+=a[x];
			count++;
			if(minW>a[x])minW=a[x];
			x=search(a[x],b,n);
		}
		if(count<2)continue;
		
		cost+=min(b[0]*(count+1)+sum+minW,sum+(count-2)*minW);
		if(isVisited(v,n)==1)break;
	}
	
	printf("%d\n",cost);
	return 0;
}