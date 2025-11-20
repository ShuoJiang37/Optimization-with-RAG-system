#include<stdio.h>

void BubleSort(int w[],int n,char W[]){
	
	int i,j,t,count,cp;
	char c;
	
	count=0;
	t=0;
	
	for(j=0; j<n; j++){
		for(i=n-1; i>=1; i--){
			if(w[i] < w[i-1]){
				cp = w[i-1];
				c  = W[i-1];
				
				w[i-1] = w[i];
				W[i-1] = W[i];
				
				w[i] = cp;
				W[i] = c;
				
				count++;
		    }
		}
	}
	
	for(i=0; i<n; i++){
		printf("%c%d",W[i],w[i]);
		if(i != n-1){
			printf(" ");
		}
	}
	printf("\n");
	
	
}

void SelectionSort(int w[],int n,char W[]){
	
	int i,j,s,count,min;
	char c;
	
	count=0;
	min=100;
	
	
	for(j=0; j<n-1; j++){
		for(i=j; i<n; i++){
			if(w[i] < min){
				min = w[i];
				c   = W[i];
				
				s=i;
			}
		}
		
		if(s != j){
			w[s]=w[j];
			W[s]=W[j];
			
			w[j]=min;
			W[j]=c;
			
			count++;
		}
		min = 100;
	}
	
	for(i=0; i<n; i++){
		printf("%c%d",W[i],w[i]);
		if(i != n-1){
			printf(" ");
		}
	}
	printf("\n");
	
}

int main(void){
	
	int i, n, N[36];
	char M[36];
	
	int N2[36];
	char M2[36];
	
	scanf("%d",&n);
	
	for(i=0; i<n; i++){
	scanf(" %c%d",&M[i],&N[i]);
		M2[i]=M[i];
		N2[i]=N[i];
		
	}
	
	BubleSort(N,n,M);
	printf("Stable\n");
	
	SelectionSort(N2,n,M2);
	
	for(i=0; i<n; i++){
		if(M[i] != M2[i]){
			printf("Not stable\n");
			break;
		}
	if(i == n-1) printf("Stable\n");
	}
	
		
	return 0;
}



