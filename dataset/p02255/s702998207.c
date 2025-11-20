#include<stdio.h>
#include<stdlib.h>

void output(int *,int);

int main(void){
  int N,key;
  int *data;
  int i,j;

  scanf("%d",&N);

  data=(int *)malloc(N*sizeof(int));

  for(i=0;i<N;i++) scanf("%d",&data[i]);

  output(data,N);

  for(i=1;i<N;i++){
    key=data[i];
    j=i-1;
    while(j>=0 && data[j]>key){
      data[j+1]=data[j];
      j--;
    }
    data[j+1]=key;
    
    output(data,N);
  }

  free(data);

  return 0;
}


void output(int *data,int N){
  int i;

  printf("%d",data[0]);
  for(i=1;i<N;i++){
    printf(" %d",data[i]);
  }
  printf("\n");
}