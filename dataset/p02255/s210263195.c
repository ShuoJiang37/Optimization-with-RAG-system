#include <stdio.h>

#define MAX 100

void print(int,int*);

int main(){
  int N,a[MAX],i,j,key;

  scanf("%d" ,&N);
  for(i = 0 ; i < N ; i++){
    scanf("%d" ,a + i);
  }

  print(N,a);
  for(j = 1 ; j < N ; j++){
    key = a[j];
    i = j - 1;

    while(i >= 0 && a[i] > key){
      a[i+1] = a[i];
      i--;
    }
    a[i+1] = key;
    print(N,a);
  }
    
  return 0;
}


void print(int N,int *a){
  int i;

  for(i = 0 ; i < N ; i++){
    if(i != N-1){
      printf("%d " ,a[i]);
    }else{
      printf("%d\n" ,a[i]);
    }
  }
}