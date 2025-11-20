
#include<stdio.h>
#define N 100


int main(){
  int n,A[N+1],k;
  int i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(k=0;k<n;k++){
    if(k>0)printf(" ");
    printf("%d",A[k]);
  }
  printf("\n");

int j,v;
for(i=1;i<n;i++){
  v=A[i];
  j=i-1;
  while(j>=0 && A[j]>v){
    A[j+1]=A[j];
    j--;
    A[j+1]=v;
  }
  for(k=0;k<n;k++){
    if(k>0)printf(" ");
    printf("%d",A[k]);
  }
  printf("\n");
 }
return 0;
}

