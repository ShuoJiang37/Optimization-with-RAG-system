#include <stdio.h>
int main(){
  int n,j,i,count=0 ,res[100],minj,alg;
  scanf("%d",&n);
 
  for(i=0;i<n;i++){
    scanf("%d",&res[i]);
  }
  
  for(i=0;i<=n-1;i++){
    minj = i;
    for(j=i;j<=n-1;j++){
      if(res[j]<res[minj]){
      minj = j;
      }
    }
    if(i!=minj) {
      alg = res[i];
      res[i] = res[minj];
      res[minj] = alg;
      count++;
      }
    }
  




  
  for(i=0;i<n;i++){
    printf("%d",res[i]);
    if(i!=n-1)printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}