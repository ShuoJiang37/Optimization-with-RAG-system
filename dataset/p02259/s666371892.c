#include<stdlib.h>
#include<stdio.h>
#include<string.h>


int main(){
  int j,i,n,*A,count,swap,oldcount;
  scanf("%d",&n);
  A=malloc(n*sizeof(int));
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  for(i=0;i<n-1;i++){
    oldcount=count;
    for(j=n-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
        swap=A[j];
        A[j]=A[j-1];
        A[j-1]=swap;
        count+=1;
      }
    }
    if(oldcount==count) break;
  }
  for(i=0;i<n-1;i++) printf("%d ",A[i]);
  printf("%d\n",A[n-1]);
  printf("%d\n",count);
  return 0;
}