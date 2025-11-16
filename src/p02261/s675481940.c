#include<stdio.h>

int main(){
  int i,j,N,A[2][36],minj,atmp;
  char C[2][36],ctmp;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf(" %c%d",&C[0][i],&A[0][i]);
    A[1][i]=A[0][i];
    C[1][i]=C[0][i];
  }

  for(i=0;i<=N-1;i++){
    for(j=N-1;j>=i+1;j--){
      if(A[1][j]<A[1][j-1]){
	atmp=A[1][j];
	A[1][j]=A[1][j-1];
	A[1][j-1]=atmp;

	ctmp=C[1][j];
	C[1][j]=C[1][j-1];
	C[1][j-1]=ctmp;
      }
    } 
  }

  for(i=0;i<N;i++){
    printf("%c%d",C[1][i],A[1][i]);
    if(i!=N-1)printf(" ");
  }
  printf("\nStable\n");

  for(i=0;i<N;i++){
    A[1][i]=A[0][i];
    C[1][i]=C[0][i];
  }

  for(i=0;i<=N-1;i++){
    minj=i;
    for(j=i;j<=N-1;j++){
      if(A[1][j]<A[1][minj])minj=j;
    }
    atmp=A[1][i];
    A[1][i]=A[1][minj];
    A[1][minj]=atmp;

    ctmp=C[1][i];
    C[1][i]=C[1][minj];
    C[1][minj]=ctmp;
  }

  for(i=0;i<N;i++){
    printf("%c%d",C[1][i],A[1][i]);
    if(i!=N-1)printf(" ");
  }
  minj=0;
  for(i=0;i<=N-1;i++){
    for(j=i+1;j<=N-1;j++){
      for(atmp=0;atmp<=N-1;atmp++){
	for(ctmp=atmp+1;ctmp<=N-1;ctmp++){
	  if(A[1][i]==A[1][j] && C[1][i]==C[0][ctmp] && C[1][j]==C[0][atmp]){
	    minj=1;
	    break;
	  }
	}
      }
    }
  }
  if(minj==0)printf("\nStable\n");
  else printf("\nNot stable\n");
  return 0;
}