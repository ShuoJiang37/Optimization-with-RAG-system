#include<stdio.h>
#include<stdlib.h>
#define MAX 2000000
#define VMAX 10000

void CountingSort(unsigned short X[],unsigned short Y[]);

int C[VMAX + 1];
int n;

int main(){
  unsigned short *X,*Y;
  int i;

  scanf("%d",&n);

  X = malloc(sizeof(short) * n + 1);
  Y = malloc(sizeof(short) * n + 1);

  for(i = 0;i < n;i++){
    scanf("%hu",&X[i + 1]);
  }

  CountingSort(X,Y);

  for(i = 1;i <= n;i++){
    if(i > 1){
      printf(" ");
    }
    printf("%u",Y[i]);
  }
  printf("\n");

  free(X);
  free(Y);

  return 0;
}

void CountingSort(unsigned short X[],unsigned short Y[]){
  int i,j;
  
  for(i = 0;i <= VMAX;i++){     
    C[i] = 0;
  }
  for(j = 1;j <= n;j++){                     /*C[i]にiの出現数を記録する*/
    C[X[j]]++;
  }
  for(i = 1;i <= VMAX;i++){      /*i以下の数の出現数を記録する*/
    C[i] = C[i] + C[i-1];
  }
  for(j = 1;j <= n;j++){
    Y[C[X[j]]] = X[j];
    C[X[j]]--;
  }

}

