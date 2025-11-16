#include <stdio.h>
#define Cn 100

struct card{char suit,value;};

void bubble(struct card C[],int N){
  int i,j;
  struct card k;
  for(i=0;i<=N-1;i++){
    for(j=N-1;j>=i+1;j--){
      if(C[j].value < C[j-1].value){
	k = C[j]; C[j] = C[j-1]; C[j-1] = k;
      }
    }
  }
}

void selection(struct card C[],int N){
  int i,j,minj;
  struct card k;
  for(i=0;i<=N-1;i++){
    minj = i;
    for(j=i;j<=N-1;j++){
      if(C[j].value < C[minj].value) minj = j;
    }
    k = C[i]; C[i] = C[minj]; C[minj] = k;
  }
}

int jgS(struct card C1[],struct card C2[],int N){
  int i;
  for(i=0;i<N;i++){
    if(C1[i].suit != C2[i].suit) return 1;
  }

  return 0;
}

int main(){
  int N,i;
  struct card C1[Cn],C2[Cn];
  scanf("%d",&N);
  
  for(i=0;i<N;i++){
    scanf(" %c%c",&C1[i].suit,&C1[i].value);
    C2[i] = C1[i];
  }

  bubble(C1,N);
  selection(C2,N);

  for(i=0;i<N;i++){
    printf("%c%c",C1[i].suit,C1[i].value);
    if(i != N-1) printf(" ");
  }
  printf("\n");
  printf("Stable\n");
  
  for(i=0;i<N;i++){
    printf("%c%c",C2[i].suit,C2[i].value);
    if(i != N-1) printf(" ");
  }
  printf("\n");
  if(jgS(C1,C2,N) == 1) printf("Not stable\n");
  else printf("Stable\n");

  return 0;
}
  

