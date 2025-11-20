#include <stdio.h>

#define NMAX 2000000
#define AIMAX 10000

int main(void)
{
	int i, n;
	int C[AIMAX+1]={0};
	short A[NMAX+1], B[NMAX+1];
	
	scanf("%d",&n);
	for(i=1; i<=n; i++) {
		scanf("%d",&A[i]);
		C[A[i]]++;
	}
	
	for (i=1; i<=AIMAX; i++) {
		C[i] += C[i-1];
	}
	
	for (i=n; i>0; i--) {
		B[C[A[i]]] = A[i];
		C[A[i]]--;
	}
	
	for (i=1; i<=n; i++) {
		if(i>1) printf(" ");
		printf("%d",B[i]);
	}
	printf("\n");
	
	return 0;
}