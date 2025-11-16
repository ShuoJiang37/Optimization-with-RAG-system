#include<stdio.h>
#include<stdlib.h>

void bubble(int *a,char *b,int n){
	int x,flag=1;
	char y;
	while(flag!=0){
		flag=0;
		for(int i=n-1;i>0;i--){
			if(a[i]<a[i-1]){
				x=a[i];
				y=b[i];
				a[i]=a[i-1];
				b[i]=b[i-1];
				a[i-1]=x;
				b[i-1]=y;
				flag=1;
			}
		}
	}
	//出力
	for(int i=0;i<n;i++){
			printf("%c%d",b[i],a[i]);
			if(i!=n-1){
				printf(" ");
		}else{
			printf("\n");
		}
	}
}

void ssort(int* a,char* b,int n){
	
	int minj,x,flag=0;
	char y;
	
	for(int i=0;i<n;i++){
		minj=i;
		for(int j=i;j<n;j++){
			if(a[j]<a[minj]){
				minj=j;
				flag=1;
			}
		}
		x=a[i];
		y=b[i];
		a[i]=a[minj];
		b[i]=b[minj];
		a[minj]=x;
		b[minj]=y;
		flag=0;
	}
	for(int i=0;i<n;i++){
		printf("%c%d",b[i],a[i]);
		if(i!=n-1) printf(" ");
	}
	printf("\n");
}

void isStable(int n,char* b,char* d){
	
	int c=0;
	
	for(int i=0;i<n;i++){
		if(b[i]!=d[i]){
			c++;
		}
	}
	if(c!=0){
		printf("Not stable\n");
	}else{
		printf("Stable\n");
	}
}

int main(void){
	
	int n;
	
	scanf("%d",&n);
	
	int* a=(int*)malloc(sizeof(int)*n);
	char* b=(char*)malloc(sizeof(char)*n);
	int* c=(int*)malloc(sizeof(int)*n);
	char* d=(char*)malloc(sizeof(char)*n);
	
	for(int i=0;i<n;i++){
		scanf(" %c",&b[i]);
		scanf("%d",&a[i]);
		c[i]=a[i];
		d[i]=b[i];
	}
	
	bubble(a,b,n);
	printf("Stable\n");
	ssort(c,d,n);
	isStable(n,b,d);
}

