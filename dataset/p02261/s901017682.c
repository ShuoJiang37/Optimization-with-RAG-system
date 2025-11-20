#include<stdio.h>
#include<string.h>
 
int isStable(char in[36][3] ,char out[36][3]);
int N;
 
int main(){
 
  int i,j,min;
  char C[36][3],num[36][3],A[36][3],tmp[36];
 
  scanf("%d",&N);
  
  for(i=0;i<N;i++){
    scanf("%s",C[i]);
    strcpy(num[i],C[i]);
    strcpy(A[i],C[i]);
  }
 
  for(i=0;i<N;i++){
    for(j=N-1;j > i;j-- ){
      if(C[j][1]<C[j-1][1]){
    strcpy(tmp,C[j]);
    strcpy(C[j],C[j-1]);
    strcpy(C[j-1],tmp);
      }
    }
  }
  for(i=0;i<N-1;i++)
    printf("%s ",C[i]);
 
    printf("%s\n",C[i]);
 
     
    if((isStable(num,C))==1)printf("Stable\n");
    else printf("Not stable\n");
 
 
   
for(i=0;i<N;i++){
    min=i;
    for(j=i;j<N;j++){
      if(A[j][1]<A[min][1])min=j;
    }
    strcpy(tmp,A[i]);
    strcpy( A[i],A[min]);
    strcpy( A[min],tmp);
 }
 
  for(i=0;i<N-1;i++)
    printf("%s ",A[i]);
 
  printf("%s\n",A[i]);
   
 
  if((isStable(num,A))==1)printf("Stable\n");
    else printf("Not stable\n");
 
  return 0;
}
 
int isStable(char in[36][3] , char out[36][3]){
 
  int i,j,a,b;
 
  for(i=0;i<N;i++){
    for(j=i+1;j<N;j++){
      for(a=0;a<N;a++){
    for(b=a+1;b<N;b++){
      if((in[i][1]==in[j][1])&&(strcmp(in[i],out[b])==0)&&(strcmp(in[j],out[a])==0))return 0;
    }
      }
    }
  }
  return 1;
  
}