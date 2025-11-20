#include <stdio.h>
int main(){
  int N;
  int v;
  int i;
  int j;
  int count;
  int x;
  int A[10000];

  scanf("%d",&N);
  
  for(i=0;i<N;i++){
    scanf(" %d",&A[i]);
  }

  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i == N - 1) break;
    printf(" ");
  }
  printf("\n");
  
  for(i = 1;i<N;i++){
    v = A[i];
    j = i - 1;
    while(j>=0 && A[j] > v){
      A[j + 1] = A[j];
      j--;
    }
    A[j+1] = v;
    
    for(x = 0;x<N;x++){
	printf("%d",A[x]);
	if(x == N-1) break;
	printf(" ");
    }
      printf("\n");
  }
}

