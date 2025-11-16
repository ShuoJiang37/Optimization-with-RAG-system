#include<stdio.h>
#define N 100
int main(){
  int a,i,j=0,v,A[N],b;
  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&A[i]);
  }
  for(b=0;b<a-1;b++) printf("%d ",A[b]);
  printf("%d",A[a-1]);
  printf("\n"); 
  for(i=1;i<a;i++){
    v = A[i];
    j = i-1;
    while(j>=0 && A[j]>v)
      {
	A[j+1] = A[j];
	j--;
      }
    A[j+1] = v;
    for(b=0;b<a-1;b++)printf("%d ",A[b]);
    printf("%d",A[a-1]);
    printf("\n");
  }
  return 0; 
}

