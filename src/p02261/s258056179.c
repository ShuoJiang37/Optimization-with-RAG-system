#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char C1[10000][2];
  char C2[10000][2];
  int n,i,j;
  scanf("%d",&n);
  /*
  for(i=0;i<n;i++){
    scanf("%c%d",&C[i].mark,&C[i].num);  
  }
  */
  for(i=0;i<n;i++){
    scanf("%s",&C1[i]);  
  }
  
  for(i=0;i<n;i++){
    for(j=0;j<2;j++){
     C2[i][j]= C1[i][j]; 
    }
  }
    
  /*
  for(i=0;i<n;i++){
    for(j=0;j<2;j++){
      printf("%c",C[i][j]);  
    }
    printf(" ");
  }
  */
  BubbleSort(C2,n);
  printf("Stable\n");
  
  SelectionSort(C1,n);
  if(isStable(C1,C2,n) == 0) printf("Stable\n");
  else  printf("Not stable\n");
 
 


}

int BubbleSort(char A[10000][2],int n){
  int i,j;
  char c_tmp;
  int i_tmp;
  int judge=0;
  for(i=0;i<n;i++){
    for(j=n-1; j>i; j--){
      if(A[j][1] < A[j-1][1]){
	c_tmp = A[j-1][0];
	A[j-1][0] = A[j][0];
	A[j][0] = c_tmp;

	i_tmp = A[j-1][1];
	A[j-1][1] = A[j][1];
	A[j][1] = i_tmp;
       
      }
    }
  }
 
  for(i=0;i<n;i++){
    for(j=0;j<2;j++){
      printf("%c",A[i][j]);  
    }
    if(i!=(n-1))printf(" ");
  }
  printf("\n");
  return 0;
}

int SelectionSort(char A[10000][2],int n){
  int i,j,minj;
  char c_tmp;
  int i_tmp;
  int judge = 0;

  
  for(i=0;i<n;i++){
    minj = i;
    
    for(j = i ;j < n ;j++){
      if(A[j][1] < A[minj][1]){
	minj = j;
      }
    }
 
    c_tmp = A[minj][0];
   
    A[minj][0] = A[i][0];
    A[i][0] =c_tmp;
      
    i_tmp = A[minj][1];
    A[minj][1] = A[i][1];
    A[i][1] = i_tmp;


  }
  
  
  
  for(i=0;i<n;i++){
    for(j=0;j<2;j++){
      printf("%c",A[i][j]);  
    }
    if(i!=(n-1)) printf(" ");
  }
  printf("\n");
  return 0;
  
}

int isStable(char in[10000][2],char out[10000][2], int n){
  int a,b,i,j;
  for(i=0;i<n;i++){
    if( in[i][0] != out[i][0]){
  
	return 1;
      }
  }
  return 0;
}

