#include <stdio.h>
#include <string.h>
 
int main(){
  int i,j,N,a,b,minj,result=0;
  char A[36][3],B[36][3],C[36][3];
   
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%s",A[i]);
  }
   
 
  for(i=0;i<N;i++){
    strcpy(C[i],A[i]);
  }
   
  for(i=0;i<N;i++){
    for(j=N-1;j>=i+1;j--){
      if(A[j][1]<A[j-1][1]){
    strcpy(B[j],A[j-1]);
    strcpy(A[j-1],A[j]);
    strcpy(A[j],B[j]);
      }
    }
  }
  for(i=0;i<N;i++){
    for(j=i+1;j<N;j++){
      for(a=0;a<N;a++){
    for(b=a+1;b<N;b++){
      if(C[i][1]==C[j][1] && strcmp(C[i],A[b])==0 && strcmp(C[j],A[a])==0)
        result=1;
    }
      }
    }
  }
 
  for(i=0;i<N-1;i++){
    printf("%s ",A[i]);
  }
  printf("%s\n",A[N-1]);
  if(result==1){
    printf("Not stable\n");
  }
  else printf("Stable\n");
 
 
   
  result=0;
   
   for(i=0;i<N;i++){
    strcpy(A[i],C[i]);
  }
   
  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j][1]<A[minj][1]){
    minj=j;
      }
    }
 
    strcpy(B[i],A[i]);
    strcpy(A[i],A[minj]);
    strcpy(A[minj],B[i]);
 
  }
    for(i=0;i<N;i++){
      for(j=i+1;j<N;j++){
    for(a=0;a<N;a++){
      for(b=a+1;b<N;b++){
        if(C[i][1]==C[j][1] && strcmp(C[i],A[b])==0 && strcmp(C[j],A[a])==0)
          result=1;
      }
    }
      }
    }
 
    for(i=0;i<N-1;i++){
      printf("%s ",A[i]);
    }
   printf("%s\n",A[N-1]);
    if(result==1){
    printf("Not stable\n");
    }
    else printf("Stable\n");
     
  return 0;
}