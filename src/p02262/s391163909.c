#include <stdio.h>

	int cnt = 0;
void insertionSort(int A[],int n, int g){
	
	int v, j;
	for(int i = g ; i < n ;i++){
		v = A[i];
		j = i-g;
		while( j >= 0 && A[j] > v)
		{
		A[j + g] = A[j];
			j = j-g;
			cnt++;
		}
		
		A[j+g] = v;
		
	}

}
void shellSort(int A[],int n){
	

	//int m = (n-1)/3 + 1;
	int G[100];
	int a = 1;
	G[0] = 1;
	int i = 0;
	
	for( ;G[i] <= n;i++){
		
		G[i+1] = 3*G[i]+1; 
		
	}
	int m = i;
	
	
	for(i = m-1;i >= 0 ; i--){
		insertionSort(A,n,G[i]);
	}
	
	
	printf("%d\n",m);
	for(i = m-1;i >= 0;i--){
	printf("%d ",G[i]);
	}
	
	printf("\n");
	printf("%d\n", cnt);
	
	
	for(i = 0;i < n; i++){
	printf("%d",A[i]);
		if(i != n-1)printf("\n");
	}
	
}


int main(void){
	
	int n;
	scanf("%d",&n);
	int number[n];


	for(int i = 0;i < n;i++)
	{
		scanf("%d",&number[i]);
	}
	
	shellSort(number,n);
	
	return 0;

}
