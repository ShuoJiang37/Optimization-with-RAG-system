#include<stdio.h>
int selectionSort(int A[],int n){
  int i,j,minj,c=0,tmp;
  for(i=0;i<n-1;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(A[j]<A[minj]){
	minj=j;
      }
    }
	tmp=A[i];
	A[i]=A[minj];
	A[minj]=tmp;
    if(i!=minj) c++;
    }
  return c;
}

int main(){
  int i,j,A[100],c,n;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  c=selectionSort(A,n);
  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",c);
  return 0;
  
}
  

