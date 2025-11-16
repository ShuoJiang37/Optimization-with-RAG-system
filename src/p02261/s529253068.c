#include <stdio.h>
typedef struct{
  char A;
  int value;
}T;

void swap(T *, T *);

int main(){
  int i,j,minj,N;
  int count = 0;
  T C[36],B[36];

  scanf("%d",&N);

  for(i = 0; i < N; i++){
    scanf(" %c%d",&C[i].A,&C[i].value);
    B[i] = C[i];
  }

  for(i = 0; i < N-1; i++){
    for(j = N-1; j > i; j--){
      if(C[j].value < C[j-1].value) swap(&C[j],&C[j-1]);
    }
  }

  for(i = 0; i < N; i++){
    printf("%c%d",C[i].A,C[i].value);
    if(i == N-1) break;
    printf(" ");
  }

  printf("\nStable\n");

  for(i = 0; i < N-1; i++){
    minj = i;
    for(j = i+1; j < N; j++){
      if(B[j].value < B[minj].value) minj = j;
    }
    if(minj != i) swap(&B[i],&B[minj]);
  }

  for(i = 0; i < N; i++){
    printf("%c%d",B[i].A,B[i].value);
    if(B[i].A != C[i].A) count++;
    if(i == N-1) break;
    printf(" ");
  }

  if(count > 0) printf("\nNot stable\n");
  else printf("\nStable\n");

  return 0;

}

void swap(T *X, T *Y){
  T cal;

  cal = *X;
  *X = *Y;
  *Y = cal;
}

