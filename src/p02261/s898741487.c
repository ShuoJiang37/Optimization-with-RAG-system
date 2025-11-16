#include <stdio.h>

typedef struct{
  char mark;
  int num;
}Data;

void isStable(Data[] ,Data[],int);
void trace(Data A[], int n){
  int i;

  for ( i = 1; i <= n; i++ ){
    if ( i > 1 ) printf(" ");
    printf("%c%d", A[i].mark, A[i].num);
  }
  printf("\n");
}

int main(){
  int n, i, j, flag = 1, minj;
  Data A[100],B[100],tmp,key[100];
  
  scanf("%d%*c", &n);

  for ( i = 1; i <= n; i++ ){
    scanf("%c%d%*c", &A[i].mark, &A[i].num);
  }
 
  for(i = 1;i <= n ; i++)B[i] = A[i];
  
  while(flag!=0){
    
    flag = 0;
    
    for(j = n ;1 < j ;j--){
      
      if(B[j].num < B[j-1].num){
	tmp = B[j];
	B[j] = B[j-1]; 
	B[j-1] = tmp;

	flag = 1;	
      }
    }
  }
  
  trace(B, n);
  printf("Stable\n");
  
  for(i = 1;i <= n ; i++){
    key[i] = B[i];
    B[i] = A[i];
  }
  
  for ( i = 1; i <= n; i++ ){
    minj = i;
    
    for ( j = i; j <= n ; j++){
      if( B[j].num< B[minj].num ){
	minj = j;
      }
    }
    if(minj != i){
      tmp = B[i];
      B[i] = B[minj];
      B[minj] = tmp;
    }
  }
  
  trace(B, n);
  isStable(key,B,n);
  
  return 0;
}
void isStable(Data A[],Data B[],int n){
  int i,key = 0;

  for(i=1;i<=n;i++){
    if(A[i].num == B[i].num){
      if(A[i].mark != B[i].mark)key = 1;
    }
  }
  if(key==0) printf("Stable\n");
  else printf("Not stable\n");
  
}