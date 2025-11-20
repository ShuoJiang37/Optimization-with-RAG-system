#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 36

int main(){
  int n,i,j,minj;
  char tmp[3],A[N][3],B[N][3],S[N][3];
  
  scanf("%d",&n);
   
  for(i=0;i<n;i++){
    scanf("%s",A[i]);
  }
  
  for(i=0;i<n;i++){
    strcpy(B[i],A[i]);
    strcpy(S[i],A[i]);
  }
  
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(B[j][1]<B[j-1][1]){
	strcpy(tmp,B[j]);
	strcpy(B[j],B[j-1]);
	strcpy(B[j-1],tmp);
      }
    }
  }

  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(S[j][1]<S[minj][1]){
	minj = j;
      }
      
    }
    strcpy(tmp,S[i]);
    strcpy(S[i],S[minj]);
    strcpy(S[minj],tmp);
  }

  for(i=0;i<n;i++){
    printf("%s",B[i]);
    if(i<n-1){
      printf(" ");
    }else{
      printf("\nStable\n");
    }
  }

  for(i=0;i<n;i++){
    printf("%s",S[i]);
    if(i<n-1){
      printf(" ");
    }else{
      printf("\n");
    }
  }
  j=0;
  for(i=0;i<n;i++){
    if(strcmp(B[i],S[i])!=0){
      j=1;
    }
  }
  
  if(j==0){
    printf("Stable\n");
  }else{
    printf("Not stable\n");
  }
  return 0;
}

