#include <stdio.h>
#include <stdlib.h>

int cnt=0;

void merge(int A[], int left, int mid, int right){
	int n1, n2, i, j, k;
	int *L, *R;
	n1 = mid - left;
	n2 = right - mid;
	L = (int *)malloc( sizeof( int ) * n1+100 );
	R = (int *)malloc( sizeof( int ) * n2+100 );
//	int L[n1+1], R[n2+1];

	for(i=0; i<n1; i++){
		L[i] = A[left+i];
	}
	for(i=0; i<n2; i++){
		R[i] = A[mid+i];
	}
	L[n1] = 10000000000000000;
	R[n2] = 10000000000000000;
	i = 0;
	j = 0;
	for(k=left; k<right; k++){		
		if(L[i]<=R[j]){
			A[k] = L[i];
			i++;
		}else{
			A[k] = R[j];
			j++;
		}
		cnt++;
	}

	free( L );
	free( R );
}


void mergesort(int A[], int left, int right){
	int mid;
	if(left+1<right){
		mid = (left + right)/2;
		mergesort(A, left, mid);
		mergesort(A, mid, right);
		merge(A, left, mid, right);
	}
}



int main(){

	int A[500000];
	int left, mid, right, n, i;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &A[i]);
	}

	left = 0;
	right = n;
	mergesort(A, left, right);

	for(i=0; i<n; i++){
		if(i!=0){
			printf(" ");
		}
		printf("%d", A[i]);
	}

	printf("\n%d\n", cnt);

	return 0;
}