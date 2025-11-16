#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){

  char **A,**B,**C,b[2];int k,i,j,n,x,y,minj,r,f=0;

  scanf("%d",&n);

  A=(char **)malloc(n*sizeof(char *));
  for(i=0;i<n;i++){
    
 A[i]=(char *)malloc(2*sizeof(char ));
  }
   B=(char **)malloc(n*sizeof(char *));
  for(i=0;i<n;i++){
    
 B[i]=(char *)malloc(2*sizeof(char ));
  }
   C=(char **)malloc(n*sizeof(char *));
  for(i=0;i<n;i++){
    
 C[i]=(char *)malloc(2*sizeof(char ));
  }
  for(i=0;i<n;i++){
  scanf("%s",A[i]);
  strcpy(C[i],A[i]);
  strcpy(B[i],A[i]);
  }

   for(i=0;i<n-1;i++){
   for(j=n-1;j>i;j--){
    x=atoi(&B[j][1]);
    y=atoi(&B[j-1][1]);
    if(x<y){
  	strcpy(b,B[j]);
     
  	strcpy(B[j],B[j-1]);
  	strcpy(B[j-1],b);
  	}
   
  }
  }

  
  for(i=0;i<n;i++){
    printf("%s",B[i]);
    if(i !=n-1)printf(" ");
  }printf("\n");
  
   printf("Stable\n");
  
   for(i=0;i<n;i++){
    minj=i;
    for(j=i+1;j<n;j++){
      x=atoi(&C[j][1]);y=atoi(&C[minj][1]);
      if(x<y){
	
	minj=j;
      }
      for(r=i+1;r<n;r++){
	if(atoi(&C[r][1])==atoi(&C[i][1])){
	if(r<minj)f++;


      }}
   
    }
   
    if(i !=minj){
      strcpy(b,C[i]);
      strcpy(C[i],C[minj]);
      strcpy(C[minj],b);}
   
      }
    for(i=0;i<n;i++){
    printf("%s",C[i]);
    if(i !=n-1)printf(" ");
  }printf("\n");
   
    if(f !=0)printf("Not stable\n");
  else printf("Stable\n");
  
  return 0;
}

