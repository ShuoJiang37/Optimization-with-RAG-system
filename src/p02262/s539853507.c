#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int cnt;

void insertionSort(int* a,int n,int g){
    int v,j;
    for(int i=g;i<n;i++){
        v=a[i];
        j=i-g;
        while(j>=0&&a[j]>v){
            a[j+g]=a[j];
            j=j-g;
            cnt++;
        }
        a[j+g]=v;
    }
}

void shellSort(int* a,int n){
    cnt=0;
    int m=0;
    int* g=(int*)malloc(sizeof(int)*n);
    
    for(int j=1;;){
    	if(j>n)break;
    	g[m]=j;
    	m++;
    	j=3*j+1;
    }
	
	printf("%d\n",m);
	for(int i=m-1;i>=0;i--){
		printf("%d",g[i]);
		if(i!=0)printf(" ");
	}
    printf("\n");
    
    for(int i=m-1;i>=0;i--){
        insertionSort(a,n,g[i]);
    }
    free(g);
}

int main(void){
    int n;
    cnt=0;
    
    scanf("%d",&n);
    
    int* a=(int*)malloc(sizeof(int)*n);
    
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    
    shellSort(a,n);
    printf("%d\n",cnt);
    for(int i=0;i<n;i++)printf("%d\n",a[i]);
    
    free(a);
}


