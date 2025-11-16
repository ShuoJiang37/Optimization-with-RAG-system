#include<stdio.h>
#define MAX 36
   
typedef struct {
  char op;
  int value;
}c;
   
int N;
int isStable(c *,c *);
void bubble(c *);
void selection(c *);
   
c A[MAX],C[MAX],D[MAX];
   
int main(){
  int i,j;
  char dummy;
  c D[MAX];
  scanf("%d%c",&N,&dummy);
  for(i=0;i<N;i++){
    scanf("%c%d%c",&C[i].op,&C[i].value,&dummy);
    A[i]=C[i];
    D[i]=C[i];
  }
   
  bubble(C);
  selection(D);
  return 0;
}
     
void bubble(c *C){
  int i,j,nstac;
  char opstac;
  for(i=0;i<=N-1;i++){
    for(j=N-1;j>=i+1;j--){
      if(C[j].value<C[j-1].value){
	nstac=C[j].value;
	opstac=C[j].op;
	C[j].value=C[j-1].value;
	C[j].op=C[j-1].op;
	C[j-1].value=nstac;
	C[j-1].op=opstac;
      }
    }
  }
  for(i=0;i<N;i++){
    if(i>0) printf(" ");
    printf("%c%d",C[i].op,C[i].value);
  }
  printf("\n");
  printf("Stable\n");
}
    
void selection(c *D){
  c x[MAX];
  int i,j,minj;
  for(i=0;i<=N-1;i++){
    minj=i;
    for(j=i;j<=N-1;j++){
      if(D[j].value<D[minj].value)
	minj=j;
    }
    x[i]=D[minj];
    D[minj]=D[i];
    D[i]=x[i];
  }
       
  for(i=0;i<N;i++){
    if(i>0) printf(" ");
    printf("%c%d",D[i].op,D[i].value);
  }
  printf("\n");
  if(isStable(D,A)==0)
    printf("Not stable\n");
  if(isStable(D,A)==1)
    printf("Stable\n");
}
              
int isStable(c *in,c *out){
  int i,j,a,b;
  for(i=0;i<=N-1;i++){
    for(j=i+1;j<=N-1;j++){
      for(a=0;a<=N-1;a++){
	for(b=a+1;b<=N-1;b++){
	  if(in[i].value==in[j].value && in[i].op==out[b].op && in[j].op==out[a].op) return 0;
	}}}}
  return 1;
}