#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void insertionsort(int *, int , int );
void shellsort(int *, int );
int cnt;
int main(){
	int n,i,tmp;
	int *data;
	scanf("%d",&n);
	data = malloc(sizeof(int)*n);
	for(i=0; i<n; i++){
		scanf("%d",(data+i));
	//	printf("%d\n",*(data+i));
	}
	//insertionsort(data,n,1);
	shellsort(data,n);
	for(i=0; i<n; i++){
		printf("%d\n",*(data+i));
	}	
	return 0;
}
void shellsort(int *A, int n){
	int m=0,G[n],i;
	G[0] = 1;
	//printf("n=%d",n);
	for(i = 1; G[i-1] <= n; i++){
		G[i] = (pow(3,i+1)-1)/2;
//		printf("%d\n",G[i-1]);
		m++;
	}
	printf("%d\n",m);
	for(i=0; i <= m-1; i++){
		insertionsort(A,n,G[m-i-1]);
	//	cnt++;
//		printf("G[%d]=",i);
		i < m-1 ? printf("%d ",G[m-i-1]) : printf("%d\n",G[m-i-1]);
	}
	printf("%d\n",cnt);
}
void insertionsort(int *A, int n, int g){
	int i,j,v;
	for(i = g; i <= n-1; i++){
		v = *(A+i);
		j = i - g;
		while(j >= 0 && *(A + j) > v){
			*(A + j + g)=*(A + j);
			j = j - g;
			cnt++;
		}
		*(A+j+g) = v;
	}
}