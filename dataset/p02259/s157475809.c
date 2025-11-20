#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main(){

  int n;
  int i,j;
  int *A;
  int count=0,check;
  int key;


  scanf("%d",&n);
  A=malloc(n*sizeof(int));
  for(i=0;i<n;i++) scanf("%d",&A[i]);


  for(i=0;i<n-1;i++){
    check=count;
    for(j=n-2;j>=i;j--){
      if(A[j+1] < A[j]){
        key=A[j+1];
        A[j+1]=A[j];
        A[j]=key;
        count+=1;
      }
    }
    if(check==count) break;
  }
  
  printf("%d",A[0]);
  for(i=1;i<n;i++) printf(" %d",A[i]);
  printf("\n%d\n",count);
  return 0;
}


//バブルソート
//一つの過程で全く交換が行われなかったら、その後は続けなくて良い。
  
    

  
