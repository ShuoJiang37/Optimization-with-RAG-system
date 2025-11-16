#include <stdio.h>
 
 
int n, cnt;
int A[1000000];
 
 int Insertionsort(int g) {
 	int v;
 	int i,j;
 	
 	for(i=g;i < n; i++) {
 		v = A[i];
 		j = i-g;
 		while(j >= 0&& A[j] > v) {
 			A[j+g] = A[j];
 			j -= g;
 			cnt++;
 		}
 		A[j+g] = v;
 	}
 }
 
 
 
 int Shellsort() {
 	int G[100];
 	int i,m = 0,g=0;
 	while(3 * g + 1 <= n) {
 		g = 3 * g + 1;
 		G[m++]=g;
 	}
 	printf("%d\n",m);
 	
 	for(i=m-1;i>=0;i--) {
 		if(i<m-1) printf(" ");
 		printf("%d",G[i]);
 		Insertionsort(G[i]);
 	}
	puts("");
	printf("%d\n",cnt);
	
	for(i = 0; i < n; i++) {
		printf("%d\n",A[i]);
	}
}
 
 
int main(void) {
   
  int i;
   
  scanf("%d", &n);
   
  for(i = 0; i < n; i++) {
    scanf("%d", A+i);
  }
 
  Shellsort();
 
  return 0;
 
}
 
