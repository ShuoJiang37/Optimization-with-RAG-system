#include<stdio.h>
#include<stdlib.h>

struct Tr{
  int id;
  char value[2];
};

int main(){

  int N,i,j,minj,M=1;
  struct Tr *C, *C2,K;

  scanf("%d",&N);

  C = (struct Tr *)malloc(sizeof(struct Tr) * N);
  C2 = (struct Tr *)malloc(sizeof(struct Tr) * N);

  for(i=0; i<=N-1; i++){
    scanf("%s",&C[i].value);
    C[i].id = i;
    C2[i] = C[i];
  }
  //BubbleSort(C2, N)
  for(i=0; i<=N-1; i++){
    for(j=N-1; j>=i+1; j--){
      if(C2[j].value[1] < C2[j-1].value[1]){
        K = C2[j];
        C2[j] = C2[j-1];
        C2[j-1] = K;
      }
    }
  }


  //SelectionSort(C, N)

  for(i=0; i<=N-1; i++){
    minj = i;
    for(j=i; j<=N-1; j++){
      if (C[j].value[1] < C[minj].value[1])
        minj = j;
    }
    K = C[i];
    C[i] = C[minj];
    C[minj] = K;
  }

  printf("%s",C2[0].value);
  for(i=1; i<=N-1; i++){
    printf(" %s",C2[i].value);
  }
  for(i=1; i<=N-1; i++){
    if(C2[i].value[1] == C2[i-1].value[1]){
      if(C2[i].id < C2[i-1].id){
        M = 0;
        break;
      }
      else M = 1;
    }
  }
  if(M == 1) printf("\nStable\n");
  else if(M == 0) printf("\nNot stable\n");

  printf("%s",C[0].value);
  for(i=1; i<=N-1; i++){
    printf(" %s",C[i].value);
  }
  for(i=1; i<=N-1; i++){
    if(C[i].value[1] == C[i-1].value[1]){
      if(C[i].id < C[i-1].id){
        M = 0;
        break;
      }
      else M = 1;
    }
  }  
  if(M == 1) printf("\nStable\n");
  else if(M == 0) printf("\nNot stable\n");
  return 0;
}
