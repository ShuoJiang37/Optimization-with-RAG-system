#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 36

typedef struct{
  char key[2];
  int value;
} SHCD;

int main(){
  SHCD A[N],temp,B[N];
  int i,j,n,minj,flag;

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++){
    scanf("%s",A[i].key);
    A[i].value = atoi(&A[i].key[1]);
    B[i] = A[i];  
  }

  i = 0;
  flag = 1;
  while(flag==1){
    flag = 0;
    for(j = n-1 ; j >= i ; j--){
      if(A[j].value < A[j-1].value){
	temp = A[j];
	A[j] = A[j-1];
	A[j-1] = temp;
      }
      flag = 1;
    }
    i+=1;
  }


  for(i = 0 ; i < n ; i++){
    minj = i;
    for(j = i ; j < n ; j++){
      if(B[j].value < B[minj].value){
	minj = j; 
      } 
    }
    if(B[j].value != B[minj].value ) {
      temp = B[minj];
      B[minj] = B[i];
      B[i] = temp;
    }
  }

  for(i = 0 ; i < n-1 ; i++){
    printf("%c%d ",A[i].key[0],A[i].value);
  }
  printf("%c%d\n",A[i].key[0],A[i].value);
  printf("Stable\n");

  for(i = 0 ; i < n-1 ; i++){
    printf("%c%d ",B[i].key[0],B[i].value);
  }
  printf("%c%d\n",B[i].key[0],B[i].value);
 
  flag = 0;
  for( i = 0 ; i < n ; i++ )
    {
      if( strcmp(A[i].key,B[i].key) != 0 ){
	flag = 1;
	break;
      }
    } 
  if( flag == 0 ) printf("Stable\n");
  else printf("Not stable\n");
  return 0;
}