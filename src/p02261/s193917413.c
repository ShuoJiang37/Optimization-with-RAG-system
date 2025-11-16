#include <stdio.h>

typedef struct{char kigou,number;}Card;

void Bsort(Card *,int);
void Ssort(Card *,int);
void print(Card *,int);
int hantei(Card *,Card *,int);

int main(){
  Card C1[100],C2[100];
  int N,i;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf(" %c",&C1[i].kigou);
    scanf(" %c",&C1[i].number);
  }
  for(i=0;i<N;i++){
    C2[i]=C1[i];
  }

  Bsort(C1,N);
  Ssort(C2,N);
  print(C1,N);

  printf("Stable\n");

  print(C2,N);
  if(hantei(C1,C2,N)==1){
    printf("Stable\n");
  }
  else{
    printf("Not stable\n");
  }

  return 0;
}

void Bsort(Card *C ,int N){
  int i,j;
  Card a;
  for(i=0;i<N;i++){
    for(j=N-1;j>=i+1;j--){
      if(C[j].number<C[j-1].number){
        a=C[j];
        C[j]=C[j-1];
        C[j-1]=a;
      }
    }
  }
}

void Ssort(Card *C,int N){
  int i,j,minj;
  Card a;
  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(C[j].number<C[minj].number)minj=j;
    }
    a=C[i];
    C[i]=C[minj];
    C[minj]=a;
  }
}

void print(Card *C,int N){
  int i;
  for(i=0;i<N;i++){
    if(i>0)printf(" ");
    printf("%c%c",C[i].kigou,C[i].number);
  }
  printf("\n");
}

int hantei(Card *C1,Card *C2,int N){
  int i;
  for(i=0;i<N;i++){
    if(C1[i].kigou != C2[i].kigou)return 0;
  }
  return 1;
}

