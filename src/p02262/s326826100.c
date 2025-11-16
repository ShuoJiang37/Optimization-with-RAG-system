#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int count = 0;

void insertSort(int *A,int n,int g);

int main(){
  int n,i,j;
  int *A;
  int G[20];
  int m = 0;

  scanf("%d",&n);
  A = malloc(n * sizeof(int));
  for(i = 0;i<n; i++){
    scanf("%d",&A[i]);
  }
   for(i = 0;i<20; i++){
     G[i] = 0;
  }

   while(1){
     if(n<3 * G[m] +1){
       break;
     }
     G[m+1] = 3*G[m] +1;
     m++;
   }

   for(i = m; i>0 ; i--){
     insertSort(A,n,G[i]);
   }

   printf("%d\n",m);
   for(i = m; i>=1 ; i--){
     printf("%d ",G[i]);
   }
     printf("\n");
     printf("%d\n",count);

     for(i = 0;i < n; i++){
       printf("%d\n", A[i]);
     }

       return 0;
     }


void insertSort(int *A,int n,int g){
  int i,j;
  int key;
  for(i = g; i<n; i++){
    j = i;
    key = A[i];
    while(0<=j-g){
      if(A[j-g] <= key)break;
      A[j] = A[j-g];
      j -= g;
      count++;
    }
    A[j] = key;
  }
}

