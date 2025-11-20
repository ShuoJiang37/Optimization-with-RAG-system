#include<stdio.h>
#include<stdlib.h>

#define T 36
 
int main(){
 
  int A[T],B[T],n,a1,b2,flag=0;
  char c3,C[T],D[T];
 
  scanf("%d",&n);
  
  int i,j;
 
  for(i=1;i<=n;i++){
    
    scanf(" %c%d",&C[i],&A[i]);
    
    B[i]=A[i];
    D[i]=C[i];
  }
 
 
 
  
  for(i=0;i<n;i++){
    
    for(j=n;j > i+1;j--){
      
      if(A[j]<A[j-1]){
	
        c3=C[j];
        C[j]=C[j-1];
        C[j-1]=c3;
        a1=A[j];
        A[j]=A[j-1];
        A[j-1]=a1;
    }
    }
  }

  
  for(i=1;i<=n;i++){
    
    printf("%c%d",C[i],A[i]);
    
    if(i!=n)printf(" ");
  }
    printf("\nStable\n");


  for(i=1;i<=n;i++){
    
    b2=i;
    
    for(j=i;j<=n;j++){
      
      if(B[j]<B[b2]){
	
        b2=j;
      }
    }
     c3=D[i];
      D[i]=D[b2];
      D[b2]=c3;
      a1=B[i];
      B[i]=B[b2];
      B[b2]=a1;
  }
  for(i=1;i<=n;i++){
    
    printf("%c%d",D[i],B[i]);
    
    if(i!=n)printf(" ");
    
  }
  
  printf("\n");
  
flag=0;
 
  for(i=1;i<=n;i++){
    
    if(B[i]!=A[i]||D[i]!=C[i]){
      
      flag=1;
      
      printf("Not stable\n");
      
      break;
    }
  }
     if(flag==0) printf("Stable\n");
   return 0;
}


