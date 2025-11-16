#include  <stdio.h>

int main(void)
{		
  int n,i,j,temp,x[100],count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&x[i]);
  }
  for (i = 0; i < n - 1; i++) {
    for (j = n - 1; j > i; j--) {
      if (x[j - 1] > x[j]) {  /* 前の要素の方が大きかったら */
	temp = x[j];        /* 交換する */
	x[j] = x[j - 1];
	x[j - 1]= temp;
	count++;
      }
    }	
  }
  for(i=0;i<n;i++){
    if(i==n-1)
      printf("%d\n",x[i]);
    else
      printf("%d ",x[i]);
  }
  printf("%d\n",count);
  return 0;
}