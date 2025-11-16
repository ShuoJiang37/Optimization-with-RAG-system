#include<stdio.h>
#include<string.h>
#define N 36

//bool isStable(char*,char*,int);
int main(){
  int i,j,a,k,minj;
  char A[N][N],tmp[N],A2[N][N];

  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%s",&A[i]);
  }
 
  memcpy(A2,A,sizeof(A));
  for(i=0;i<a-1;i++){   
    for(j=a-1;i+1<=j;j--){
      //printf("%s %s\n",A[j],A[j-1]);
      if (A[j][1]<A[j-1][1]){
	strcpy(tmp,A[j]);
	strcpy(A[j],A[j-1]);
	strcpy(A[j-1],tmp); 
        //printf("change %s %s\n",A[j],A[j-1]);
      }
    }
  }
 
  for(k=0;k<a-1;k++)
  printf("%s ",A[k]);
  printf("%s\n",A[k]);
  printf("Stable\n");
    
  for(i=0;i<a-1;i++){
    minj=i;
    for(j=i;j<a;j++){
      if(A2[j][1]<A2[minj][1])
	minj = j;
    }
    if (i!=minj){
      strcpy(tmp,A2[i]);
      strcpy(A2[i],A2[minj]);
      strcpy(A2[minj],tmp); 
	
    }
  }

  for(k=0;k<a-1;k++)
    printf("%s ",A2[k]);
  printf("%s\n",A2[k]);
    

  for(k=0;k<a;k++){
    if(A[k][1]!=A2[k][1] || A[k][0]!=A2[k][0])
      break;
  }
  if(k==a) printf("Stable\n");
  else printf("Not stable\n");
    
   
  return 0;

}  



