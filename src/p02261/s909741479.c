#include<stdio.h>

typedef struct{
  int num;
  char mark;
}trump;


int isStable(trump B[],trump C[], int m){
  int i;
  for(i = 0; i < m; i++){
    if(B[i].mark != C[i].mark)
      return 0;
  }
  return 1;
}

int main(){
  trump A[36],D[36],key;
  int i,j,n,minj,flag;

  scanf("%d%*c",&n);

  for(i = 0; i < n; i++)
    scanf("%c%d%*c",&A[i].mark,&A[i].num);


  for(i = 0; i < n; i++)
    D[i] = A[i];
    
  for(i = 0; i < n; i++){
    minj = i;

    for(j = i; j < n; j++){
      if(A[j].num < A[minj].num)
	minj = j;
    }

    if(i != minj){
      key = A[minj];
      A[minj] = A[i];
      A[i] = key;
    }
  }


  flag = 1;

   while(flag){
    flag = 0;

    for(i = n-1; i > 0; i--){
      if(D[i].num < D[i-1].num){
	key = D[i-1];
	D[i-1] = D[i];
	D[i] = key;
	flag = 1;
      }
    }

  }

   for(i = 0; i < n-1; i++)
     printf("%c%d ",D[i].mark,D[i].num);
   
   printf("%c%d\n",D[n-1].mark,D[n-1].num);
   printf("Stable\n");

  for(i = 0; i < n-1; i++)
      printf("%c%d ",A[i].mark,A[i].num);

      printf("%c%d\n",A[n-1].mark,A[n-1].num);

      if(isStable(A,D,n))
	printf("Stable\n");

      else printf("Not stable\n");
      
  return 0;
}