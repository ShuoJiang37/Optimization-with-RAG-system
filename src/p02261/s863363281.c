#include <stdio.h>

int main(){

  int N,i,j,flag,minj,c2,x;
  int  C2[36],c3,C3[36];
  char c1,C1[36],c4,C4[36];
  
  flag=0;
  
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf(" %c%d",&C1[i],&C2[i]);
    C3[i]=C1[i];
    C4[i]=C2[i];
     }

  for(i=0;i<=N-1;i++){
    for(j=N-1;j>=i+1;j--){
      if(C2[j]<C2[j-1]){
	c1=C1[j];
	C1[j]=C1[j-1];
	C1[j-1]=c1;

	c2=C2[j];
	C2[j]=C2[j-1];
	C2[j-1]=c2;	
      }
    }
  }
  for(i=0;i<N-1;i++){
    printf("%c%d ",C1[i],C2[i]);
  }  
  printf("%c%d\n",C1[N-1],C2[N-1]);
  printf("Stable\n");
  
  for(i=0;i<=N-1;i++){
    minj=i;
    for(j=i;j<=N-1;j++){
      if(C4[j]<C4[minj]){
	minj=j;
      }
    }
    c3=C3[i];
    C3[i]=C3[minj];
    C3[minj]=c3;

    c4=C4[i];
    C4[i]=C4[minj];
    C4[minj]=c4;
       
  }
  for(i=0;i<N-1;i++){
    printf("%c%d ",C3[i],C4[i]);
  }  
  printf("%c%d\n",C3[N-1],C4[N-1]);

  for(i=0;i<=N-1;i++){
    if(C1[i]!= C3[i] || C2[i]!=C4[i])
      flag=1;
  }
  if(flag==1)printf("Not stable\n");
  else printf("Stable\n");
  return 0;


}