#include<stdio.h>

#define N 3000000

int main(){
  int loop;
  int Before[N],After[N],Counter[N];
  int i;

  scanf("%d",&loop);
  for(i=0;i<N+1;i++){
    Counter[i]=0;
  }

  for(i=1;i<loop+1;i++){
    scanf(" %d",&Before[i]);
    Counter[Before[i]]++;
  }
  
  for(i=1;i<N+1;i++){
    Counter[i]=Counter[i]+Counter[i-1];
  }

  for(i=loop;i>=1;i--){
    After[Counter[Before[i]]]=Before[i];
    Counter[Before[i]]--;
  }

  for(i=1;i<loop;i++){
    printf("%d ",After[i]);
  }

  printf("%d\n",After[loop]);
  
  return 0;
}


