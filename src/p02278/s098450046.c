#include<stdio.h>
#define N 1000
 
int n,A[N],B[N],C[N],con,res,min;
 
void swap(int* A,int* B)
{
  int ch;
  ch=*A;
  *A=*B;
  *B=ch;
}
int small(int a,int b)
{
  if(a<b)return a;
  
  else return b;
}
 
int search(int a)
{
  int m;
  for(m=0; m<n; m++){
    if(A[m]==a)return m;
  }
  
}
 
int main()
{
  int i,j,sum=0,k;
 
  scanf("%d",&n);
 
  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
    B[i]=A[i];
  }
 
  for(i=n-1; i>0; i--){
    for(j=0; j<i; j++){
      if(B[j]>B[j+1]) swap(&B[j],&B[j+1]);
    }
  }
 
  for(i=0; i<n; i++)C[i]=0;
 
  for(i=0; i<n; i++){
    k=i;
    con=res=0;
    min=(1<<24);
 
    while(C[k]==0){
      C[k]=1;
      con++;
      res+=A[k];
      min=small(min,A[k]);
      k=search(B[k]);
    }
 
    if(con<2)continue;
    sum+=small(res+B[0]*(con+1)+min,res+min*(con-2));
  }
 
  printf("%d\n",sum);
   
  return 0;
  
}


