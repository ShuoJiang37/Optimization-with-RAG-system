#include<stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char value[5];
  char temp[5];
}Record;


int main(){
  
  int N,i,j,minj,flag,x=0,y=0,a,b;
  scanf("%d",&N);
  Record C[N],A[N],B[N];
  
  for(i=0;i<N;i++){
    scanf("%s",A[i].value);
  }

  for(i=0;i<N;i++){
    strcpy(B[i].value,A[i].value);
    strcpy(C[i].value,A[i].value);
  }



  





  //Bubble sort
  for(i=0;i<=N-1;i++){
    for(j=N-1;j>=i+1;j--){
      if(atoi(A[j].value+1) < atoi(A[j-1].value+1)){
	strcpy(A[j].temp,A[j].value);
	strcpy(A[j].value,A[j-1].value);
	strcpy(A[j-1].value,A[j].temp);
      }
    }
  }

  for(i=0;i<N;i++){
    printf("%s",A[i].value);
    if(i < N -1){
      printf(" ");
    }
  }
  printf("\n");

  for(i=0;i<=N-1;i++){
    for(j=i+1;j<=N-1;j++){
      for(a=0;a<=N-1;a++){
	for(b=a+1;b<=N-1;b++){
	  if(strcmp(C[i].value+1,C[j].value+1)==0  && strcmp(C[i].value,A[b].value)==0 && strcmp(C[j].value,A[a].value)==0){
	    x=1;
	  }
	}
      }
    }
  }
  if(x == 1){
    printf("Not stable\n");
  }else{
    printf("Stable\n");
    }


  
  

  

  //SelectionSort
  for(i=0;i<=N-1;i++){
    minj = i;
    for(j=i;j<=N-1;j++){
      if(atoi(B[j].value+1) < atoi(B[minj].value+1)){
	minj = j;
      }
    }
    strcpy(B[i].temp,B[i].value);
    strcpy(B[i].value,B[minj].value);
    strcpy(B[minj].value,B[i].temp);
  }

  

  for(i=0;i<N;i++){
    printf("%s",B[i].value);
    if(i < N -1){
      printf(" ");
    }
  }

  printf("\n");
  
  for(i=0;i<=N-1;i++){
    for(j=i+1;j<=N-1;j++){
      for(a=0;a<=N-1;a++){
	for(b=a+1;b<=N-1;b++){
	  if(strcmp(C[i].value+1,C[j].value+1)==0 && strcmp(C[i].value,B[b].value)==0 && strcmp(C[j].value,B[a].value)==0){
	    y = 1;
	  }
	}
      }
    }
  }
  if(y == 1){
    printf("Not stable\n");
  }else{
    printf("Stable\n");
    }

  

    return 0;
}
	   

