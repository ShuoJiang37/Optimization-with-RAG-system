#include<stdio.h>

static const int N = 100;

int main(){
  int n,i,j,flag;
  int A[N];
  int swap,sort=0;

  scanf("%d",&n); /*Input an integer n, the number of elements in sequence*/

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);/* Input N elements of the sequence*/
  }

  flag=1;
  i=0;
  while(flag){
  flag=0;
    for(j=n-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
	swap=A[j];    
        A[j]=A[j-1];
        A[j-1]=swap;
        flag=1;
        sort++;
      }
     }
    i++;
   }
    for(i=0;i<n;i++){
      if(i<n-1) printf("%d ",A[i]);/*Output the sorted sequence*/
      else printf("%d\n",A[i]);
    }
    printf("%d\n",sort);  /*Output the number of swap operations.*/

    return 0;
   } 