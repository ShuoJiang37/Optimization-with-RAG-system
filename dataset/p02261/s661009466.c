#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

  int N,i,j,k,minj,count=0;
  char *v;

  scanf("%d", &N);
  char *A[N],*B[N],str[100];

  for(i=0;i<N;i++){
    scanf("%s",str);
    A[i]=(char *)malloc(sizeof(char) * (strlen(str)+1));
    B[i]=(char *)malloc(sizeof(char) * (strlen(str)+1));
    strcpy(A[i],str);
    strcpy(B[i],str);
  }
  
  /*BubbleSort*/
  for( i = 0 ; i < N-1 ; i++){
    for( j = N-1 ; j > i ; j--){      
      if(atoi(&A[j][1]) < atoi(&A[j-1][1])){
     	v = A[j];
       	A[j] = A[j-1];
       	A[j-1] = v;	
      }
    }
  }
  printf("%s",A[0]);
  for(k=1;k<N;k++)printf(" %s",A[k]);
  printf("\nStable\n");
  
  /*SelctionSort*/
  for(i = 0 ; i <= N-1 ; i++){
    minj = i;
    for( j = i ; j <= N-1 ; j++){
      if(atoi(&B[j][1]) < atoi(&B[minj][1]))minj = j;
    }
    if(i != minj){
      v = B[i];
      B[i] = B[minj];
      B[minj] = v;
    }
  }
  printf("%s",B[0]);
  for(k=1;k<N;k++)printf(" %s",B[k]);
  printf("\n");

  for(i = 0 ; i <= N-1 ; i++){
    if(A[i][0] != B[i][0] || A[i][1] != B[i][1]){
      printf("Not stable\n");
      count++;
      break;
    }
  }
  if(count==0)printf("Stable\n");
  
 return 0;
}

