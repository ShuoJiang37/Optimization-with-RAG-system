#include<stdio.h>
#include<stdlib.h>
void swap(char *,char *);

int main(void){
  int i,j,min,N;
  char a,b,c,d;
  char A[36][3];
  char B[36][3];
  char C[36][3];
  char k[2];
  
  scanf("%d",&N);
  if(N<1 || 36<N){
    exit;
  }

  for(i=0; i<N; i++){
    scanf("%s",A[i]);
    B[i][0] = A[i][0];
    B[i][1] = A[i][1];
  }
  
  for(i=0; i<N; i++){
    for(j=N-1; j>=i+1; j--){
      if((int)A[j][1] < (int)A[j-1][1]){
	k[0] = A[j][0];
	k[1] = A[j][1];
	A[j][0] = A[j-1][0];
	A[j][1] = A[j-1][1];
	A[j-1][0] = k[0];
	A[j-1][1] = k[1];
      }
    }
  }
  
  for(i=0; i<N; i++){
    if(i != 0){
      printf(" ");
    }
    printf("%c%c",A[i][0],A[i][1]);
    C[i][0] = A[i][0];
    C[i][1] = A[i][1];
  }
  printf("\n");
  
  for(i=0; i<N; i++){
    if(A[i][0] != C[i][0])break;
  }
  if(i == N){
    printf("Stable\n");
  }
  else printf("Not stable\n");

  for(i=0; i<N; i++){
    min = i;
    for(j=i; j<N; j++){
      if(B[j][1] < B[min][1]){
	min = j;
      }
    }

    a = B[i][0];
    b = B[i][1];
    c = B[min][0];
    d = B[min][1];

    swap(&a,&c);
    swap(&b,&d);

    B[i][0] = a;
    B[i][1] = b;
    B[min][0] = c;
    B[min][1] = d;
  }
  
  for(i=0; i<N; i++){
    if(i != 0){
      printf(" ");
  }
    printf("%c%c",B[i][0],B[i][1]);
  }
  printf("\n");
  
  for(i=0; i<N; i++){
    if(B[i][0] != C[i][0]){
      break;
    }
  }
  if(i == N){
    printf("Stable\n");
  }
  else printf("Not stable\n");
  return 0;
}


void swap(char *x,char *y){
  char temp;
  temp = *x;
  *x = *y;
  *y = temp;
}