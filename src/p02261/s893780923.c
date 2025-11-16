#include <stdio.h>

int main()
{
  int i, j, n, flag=0, swap, minj, A[36], B[36];
  char C1[36], C2[36], tmp;

  scanf("%d",&n);
  for( i=0 ; i<n ; i++ ){
    scanf(" %c%d",&C1[i],&A[i]);
    C2[i] = C1[i];
    B[i] = A[i];
  }

  for( i=0 ; i<n ; i++ ){
    for( j=n-1 ; j>=i+1 ; j-- ){
      if(A[j]<A[j-1]){
	swap = A[j];
	A[j] = A[j-1];
	A[j-1] = swap;
	tmp = C1[j];
	C1[j] = C1[j-1];
	C1[j-1] = tmp;
      }
    }
  }
  for( i=0 ; i<n-1 ; i++ )
    printf("%c%d ",C1[i],A[i]);
  printf("%c%d\n",C1[i],A[i]);
  printf("Stable\n");
  

  for( i=0 ; i<n ; i++ ){
    minj = i;
    for( j=i ; j<n ; j++ ){
      if(B[j]<B[minj]){
	minj = j;
      }
    }
    swap = B[i];
    B[i] = B[minj];
    B[minj] = swap;
    tmp = C2[i];
    C2[i] = C2[minj];
    C2[minj] = tmp;    
  }
  for( i=0 ; i<n-1 ; i++ )
    printf("%c%d ",C2[i],B[i]);
  printf("%c%d\n",C2[i],B[i]);

  for( i=0 ; i<n ; i++ ){
    if(C1[i]!=C2[i] || A[i]!=B[i])
      flag = 1;
  }
  if(flag==1) printf("Not stable\n");
  else printf("Stable\n");

  return 0;
}