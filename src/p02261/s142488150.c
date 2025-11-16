#include<stdio.h>
#include<stdlib.h>

int main(){

  int num[36],A[36];
  char mar[36],Am[36];
  int N,i,j,boxi,flag = 0,minj,box;
  char boxc;

  scanf("%d",&N);

  for(i=0;i<N;i++){
    scanf(" %c%d",&mar[i],&num[i]);
  }

  for(i=0;i<N;i++){
    Am[i] = mar[i];
    A[i] = num[i];
  }
  
  for(i=0;i<N;i++){
    for(j=N-1;j>i;j--){
            
      if(num[j]<num[j-1]){
	boxi = num[j];
	boxc = mar[j];
	num[j] = num[j-1];
	mar[j] = mar[j-1];
	num[j-1] = boxi;
	mar[j-1] = boxc;
      }
    }
  }
  for(i=0;i<N-1;i++){
    printf("%c%d ",mar[i],num[i]);
  }
  printf("%c%d\n",mar[i],num[i]);
  printf("Stable\n");


  for(i=0;i<N;i++){
    minj = i;
    for(j=i;j<N;j++){
      if(A[j]<A[minj])
	minj = j;
    }
    if(i != minj){
      box = A[i];
      boxc = Am[i];      
      A[i] = A[minj];
      Am[i] = Am[minj];
      A[minj] = box;
      Am[minj] = boxc;
    }
  }

  for(i=0;i<N-1;i++){
    printf("%c%d ",Am[i],A[i]);
  }
  printf("%c%d\n",Am[i],A[i]);

  flag = 0;
  for(i=0;i<N;i++)
    if(Am[i]!=mar[i])flag=1;

  if(flag==1)printf("Not stable\n");
  else printf("Stable\n");
  
  return 0;
}