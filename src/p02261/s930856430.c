#include <stdio.h>
#include <string.h>

int main(){
  int i,j,a,b,minj,flag=1,N;
  char temp[3];

  scanf("%d",&N);

  char C[N][3],B[N][3],S[N][3];

  for(i=0;i<N;i++){
    scanf("%s",C[i]);
    
    strcpy(B[i],C[i]);
    strcpy(S[i],C[i]);
  }

  for(i=0;i<N;i++){
    for(j=N-1;j>i;j--){
      if(B[j][1]<B[j-1][1]){	
	strcpy(temp,B[j]);
	strcpy(B[j],B[j-1]);
	strcpy(B[j-1],temp);
      }
    }
  }

  for(i=0;i<N-1;i++)
    printf("%s ",B[i]);
  printf("%s\n",B[N-1]);

  for(i=0;i<N;i++){
    for(j=i+1;j<N;j++){
      for(a=0;a<N;a++){
	for(b=a+1;b<N;b++){
	  if(C[i][1]==C[j][1]&&strcmp(C[i],B[b])==0&&strcmp(C[j],B[a])==0)
	    flag=0;
	}
      }
    }
  }
  if(flag==0) printf("Not stable\n");
  else printf("Stable\n");
  flag=1;

  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(S[j][1]<S[minj][1]){
	minj=j;
      }
    }
    strcpy(temp,S[i]);
    strcpy(S[i],S[minj]);
    strcpy(S[minj],temp);
  }
  
 for(i=0;i<N-1;i++)
    printf("%s ",S[i]);
  printf("%s\n",S[N-1]);

  for(i=0;i<N;i++){
    for(j=i+1;j<N;j++){
      for(a=0;a<N;a++){
	for(b=a+1;b<N;b++){
	  if(C[i][1]==C[j][1]&&strcmp(C[i],S[b])==0&&strcmp(C[j],S[a])==0)
	    flag=0;
	}
      }
    }
  }
  if(flag==0) printf("Not stable\n");
  else printf("Stable\n");

  return 0;
}