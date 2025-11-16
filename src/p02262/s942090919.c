#include<stdio.h>

int insertionSort(int A[],int n, int g){
	
	int i,j,t;
	int v,count;
	
	count=0;
	
	for(i=g; i<n; i++){
		
		v=A[i];
		j=i-g;
		
		while (j >= 0 && A[j] > v){
			A[j+g] = A[j];
			j = j - g;
			count++;
			
		}
		A[j+g] = v;
	}
	
	return count;
}

	

void ShellSort(int A[], int n){
	
	int i,j,t,k,count;
	int G[100];
	G[0]=1;
	count=0;
	
	for(i=0; G[i]<=n; i++){
		G[i+1] = 3*G[i] + 1;
	}
	
	for(j=i-1; j>=0; j--){
		count = count + insertionSort(A,n,G[j]);
	}
	printf("%d\n",i);
	
	for(t=i-1; t>=0; t--){
		printf("%d",G[t]);
		if(t>0){
			printf(" ");
		}
		
	}
		
	printf("\n");
	printf("%d\n",count);
	for(k=0; k<n; k++){
		printf("%d",A[k]);
		
		if(k<n-1){
			printf("\n");
		}
	}
}



int main(void){
	
	int i,n;
	
	scanf("%d",&n);
	
	int A[n];
	
	for(i=0; i<n; i++){
		scanf("%d",&A[i]);
	}
	
	ShellSort(A, n);
	
	
	return 0;
}



