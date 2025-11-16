#include <stdio.h>
void s(int *a,int *b){int i=*a;*a=*b;*b=i;}
void c(char *a,char *b){char i=*a;*a=*b;*b=i;}
void sB(int *A,char *C,int a){
  int i,j;
  for(i=0;i<a-1;i++)
    for(j=a-1;j>i;j--)
      if(A[j]<A[j-1]){
	s(&A[j],&A[j-1]);
	c(&C[j],&C[j-1]);
      }
}  
void sS(int *A,char *C,int a){
  int i,j;
  for(i=0;i<a;i++){
    int m=i;
    for(j=i;j<a;j++)
      if(A[j]<A[m])
	m=j;
    if(A[i]!=A[m]){
      s(&A[i],&A[m]);
      c(&C[i],&C[m]);
    }
  }
}

int cS(int *Ac,char *Cc,int *A,char *C,int N){
  int n=0;
  for(n=0;n<N-2;n++){
    if(Ac[n]==Ac[n+1]){
      int m=0;
      while((Ac[n]==Ac[n+1])&&(n<N-2)){
	while(Ac[n]!=A[m])
	  m++;
	if(Cc[n]!=C[m])
	  return 1;
	n++; m++;
      }
    }
  }
  return 0;
}

int main(void){
  int n,N,No[36],Nb[36],Ns[36];char C[36],Cb[36],Cs[36];
  scanf("%d\n",&N);
  for(n=0;n<N;n++){
    scanf("%c%d ",&C[n],&No[n]);
    Cb[n]=C[n];Cs[n]=C[n];Nb[n]=No[n];Ns[n]=No[n];
  }
  sB(Nb,Cb,N);
  for(n=0;n<N-1;n++)
    printf("%c%d ",Cb[n],Nb[n]);
  printf("%c%d\n",Cb[N-1],Nb[N-1]);
  if(cS(Nb,Cb,No,C,N))
    printf("Not Stable\n");
  else
    printf("Stable\n");
  sS(Ns,Cs,N);
  for(n=0;n<N-1;n++)
    printf("%c%d ",Cs[n],Ns[n]);
  printf("%c%d\n",Cs[N-1],Ns[N-1]);
  if(cS(Ns,Cs,No,C,N))
    printf("Not stable\n");
  else
    printf("Stable\n");
  return 0;
}