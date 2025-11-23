#include <stdio.h>
#define N 100
int bubblesort(int *,int);

int main(){
  int i,j,tmp,n,count,sep;
  int in[N];

  /* input */
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&in[i]);
  }

  /* sort */
  count = bubblesort(in,n);
  
  /* output */
  for(i=0;i<n-1;i++){
    printf("%d ",in[i]);
  }
  printf("%d\n",in[i]);
  printf("%d\n",count);

  return 0;
}

int bubblesort(int *in,int n){
  int i,j,flag,tmp,count;
  flag = 1;
  count = 0;
  while(flag){
    flag = 0;
    for(j=n-1;j>0;j--){
      if(in[j-1] > in[j]){
	tmp = in[j-1];
	in[j-1] = in[j];
	in[j] = tmp;
	flag = 1;
	count++;
      }
    }
  }

  return count;
}