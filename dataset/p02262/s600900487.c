#include <stdio.h>
#define N 1000000

int main(){
  int A[N] , G[100];
  int num, i, j, k, cnt, m, v;
  scanf("%d", &num);
  for(i = 0; i < num; i++){
    scanf("%d", &A[i]);
  }
  
  cnt = 1;
  j = 1;
  while(1){ 
    if(cnt > num/5.0){
      break;
    }
    cnt = cnt*3 + 1;
    j++;
  }
  m = j;
  j = 0;
  for(i = cnt; i > 0; i=i/3){
    G[j] = i;
    j++;
  }
    cnt = 0;
    
  for(k = 0; k < m; k++){
    for(i = G[k]; i < num; i++){
      v = A[i];
      j = i - G[k];
      while(j >= 0 && A[j] > v){
	A[j+G[k]] = A[j];
	j = j - G[k];
	cnt++;
      }
      A[j+G[k]] = v;
    }
    
  }
  printf("%d\n", m);
  for(i = 0; i < m; i++){
    printf("%d ", G[i]);
  }
  printf("\n%d\n", cnt);
  for(i = 0; i < num; i++){
    printf("%d\n", A[i]);
  }
  return 0;
}

