#include<stdio.h>
#define N 10001
typedef struct {
  int sum;
  int flag;
} CC;
CC C[N];
int A[1000],B[1000];
int main()
{
  int i,n,min=0,m,k,now,sum=0,minx,sum1,sum2;
  scanf("%d",&n);
  for(i=1;i<n+1;i++){
    scanf("%d",&A[i]);
  }
  minx=A[1];
  for(i=1;i<n+1;i++){
    if(minx>A[i])minx=A[i];
  }
  for(i=0;i<N;i++){
    C[i].sum=0;
    C[i].flag=0;
  }
  for(i=1;i<n+1;i++){
    C[A[i]].sum+=1;
    C[A[i]].flag+=1;
  }
  for(i=0;i<N;i++){
    C[i].sum+=C[i-1].sum;
  }

  for(i=n+1;i>0;i--){
    if(C[A[i]].flag==1){
      k=i;
      now=k;
      m=0;
      B[C[A[k]].sum]=A[k];
      C[A[i]].flag=0;
      min=A[k];
      k=C[A[k]].sum;
      while(A[now]!=A[k]){
        if(m==0){
          sum+=A[now];
	  //printf("%d ",A[now]);
        }
        //printf("%d ",A[k]);
        B[C[A[k]].sum]=A[k];
        C[A[k]].flag=0;
        sum+=A[k];
        if(min>A[k])min=A[k];
        k=C[A[k]].sum;
        m+=1;
      }
      sum2=min*(m-1);
      sum1=min+(m+2)*minx;
      if(m>1){      
	if(sum1<sum2){
	  sum+=sum1;
	}
	else sum+=sum2;     
	m=0;
	min=0;
      }
    }
    
  }
  /* printf("\n");
  for(i=1;i<n;i++){
    printf("%d ",B[i]);
  }
  printf("%d",B[i]);*/
  printf("%d\n",sum);
  return 0;
}