#include<stdio.h>

int main(){
  int N,A[100],i,j,key,B[100],minj;
  char Ac[100],keyc,Bc[100];

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf(" %c%d",&Ac[i],&A[i]);
    B[i]=A[i];
    Bc[i]=Ac[i];
  }

  for(i=0;i<N;i++){
    for(j=N-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
        key=A[j];
        keyc=Ac[j];
        A[j]=A[j-1];
        Ac[j]=Ac[j-1];
        A[j-1]=key;
        Ac[j-1]=keyc;
      }
    }
  }
  for(i=0;i<N-1;i++){
    printf("%c%d ",Ac[i],A[i]);
  }
  printf("%c%d\nStable\n",Ac[N-1],A[N-1]);

  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(B[j]<B[minj]){
        minj=j;
      }
    }

    key=B[i];
    keyc=Bc[i];
    B[i]=B[minj];
    Bc[i]=Bc[minj];
    B[minj]=key;
    Bc[minj]=keyc;
  }
    for(i=0;i<N-1;i++){
    printf("%c%d ",Bc[i],B[i]);
  }
  printf("%c%d\n",Bc[N-1],B[N-1]);

  for(i=0;i<N;i++){
    if(Ac[i]!=Bc[i]){
      printf("Not stable\n");
      break;
    }
    else if(i==N-1 && Ac[i]==Bc[i]){
      printf("Stable\n");
      break;
    }
  }

  return 0;

}

