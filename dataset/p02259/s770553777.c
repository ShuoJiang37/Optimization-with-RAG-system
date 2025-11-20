#include <stdio.h>

#define MAX 100

int main(){
  int N,a[MAX],i,j,tmp,count = 0;

  scanf("%d" ,&N);
  for(i = 0 ; i < N ; i++){
    scanf("%d" ,a + i);
  }

  for(i = 0 ; i < N ; i++){
    for(j = N-1 ; j > i ; j--){
      if(a[j] < a[j-1]){
	tmp = a[j];
	a[j] = a[j-1];
	a[j-1] = tmp;
	count++;
      }
    }
  }

  for(i = 0 ; i < N ; i++){
    if(i != N-1){
      printf("%d " ,a[i]);
    }else{
      printf("%d\n%d\n" ,a[i] ,count);
    }
  }

  return 0;
}