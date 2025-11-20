#include<stdio.h>

int main(){

  int n, tmp, i, j ,k;
  //Input
  scanf("%d",&n);

  int a[100];

  for( i = 1; i <= n; i++)scanf("%d",&a[i]);
  //Algo
  for( i = 1; i <= n; i++){    

    tmp = a[i];
    j = i-1;
    while( j > 0 && a[j] > tmp){
      a[j+1] = a[j];
      j--;
    }      
    a[j+1] = tmp;
    //Print
    for( k = 1; k <= n; k++){
      printf("%d",a[k]);
      if(k==n)break;
      printf(" ");
    }
    printf("\n");
  }
  return 0;
}