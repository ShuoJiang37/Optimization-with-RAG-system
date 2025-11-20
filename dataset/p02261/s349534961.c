#include <stdio.h>
#include <stdlib.h>
 
int main(){
  int i,j,N,minj,a,b;
  char tmp;
  char tmp2;
  int flag=0;
  scanf("%d",&N);
  
  char A[N][2];
  char B[N][2];
  char C[N][2];
  for(i=0;i<N;i++){
    scanf("%s",C[i]); 
    A[i][0]=C[i][0];
    A[i][1]=C[i][1];
    B[i][0]=C[i][0];
    B[i][1]=C[i][1];
 
  }
   
   for(i=0;i<N;i++){
    for(j=N-1;j>i;j--){
      if((int)A[j][1]<(int) A[j-1][1]){
    tmp=A[j][0];
    A[j][0]=A[j-1][0];
    A[j-1][0]=tmp;
    tmp2=A[j][1];
    A[j][1]=A[j-1][1];
    A[j-1][1]=tmp2;
      }
    }
    }
 
   for(i=0;i<N-1;i++)printf("%c%c ",A[i][0],A[i][1]);
   printf("%c%c\n",A[N-1][0],A[N-1][1]);
 
 
   for(i=0;i<N;i++){
     for(j=i+1;j<N;j++){
       for(a=0;a<N;a++){
     for(b=a+1;b<N;b++){
       if(C[i]==C[j] && C[i]==A[b] && C[j]==A[a]){
         flag=1;
       }
     }
       }
     }
   }
   if(flag==0)printf("Stable\n");
   else printf("Not stable\n");
 
   flag=0;
 
   for(i=0;i<N;i++){
     minj=i;
     for(j=i;j<N;j++){
       if((int)B[j][1]<(int)B[minj][1]){
     minj=j;
       }
     }
     tmp=B[i][0];
     B[i][0]=B[minj][0];
     B[minj][0]=tmp;
     tmp2=B[i][1];
     B[i][1]=B[minj][1];
     B[minj][1]=tmp2;
   }
 
 
   for(i=0;i<N-1;i++)printf("%c%c ",B[i][0],B[i][1]);
   printf("%c%c\n",B[N-1][0],B[N-1][1]);
 
   for(i=0;i<N;i++){
     for(j=i+1;j<N;j++){
       for(a=0;a<N;a++){
     for(b=a+1;b<N;b++){
       if(C[i][1]==C[j][1] && C[i][0]==B[b][0] && C[i][1]==B[b][1] && C[j][0]==B[a][0] && C[j][1]==B[a][1] ){
         flag=1;
       }
     }
       }
     }
   }
   if(flag==0)printf("Stable\n");
   else printf("Not stable\n");
 
 
 
   return 0;
}