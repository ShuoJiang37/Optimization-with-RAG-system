#include<stdio.h>

typedef struct{
  char m;
  int n;
} Card;

int main(){
  Card A[100],B[100],tmp;
  int i,j,n,mini,c=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf(" %c%d",&A[i].m,&A[i].n);
  for(i=0;i<n;i++)B[i]=A[i];

  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(A[j].n<A[j-1].n){
        tmp=A[j];
        A[j]=A[j-1];
        A[j-1]=tmp;
      }
    }
  }
  for(i=0;i<n-1;i++) printf("%c%d ",A[i].m,A[i].n);
  printf("%c%d\n",A[n-1].m,A[n-1].n);
  printf("Stable\n");

   for(i=0;i<n-1;i++){
    mini=i;
    for(j=i;j<n;j++){
      if(B[j].n<B[mini].n) mini=j;
    }
    tmp=B[i];
    B[i]=B[mini];
    B[mini]=tmp;
  }

   for(i=0;i<n-1;i++) printf("%c%d ",B[i].m,B[i].n);
   printf("%c%d\n",B[n-1].m,B[n-1].n);

   for(i=0;i<n;i++){
     if(A[i].m!=B[i].m){
       printf("Not stable\n");
       return 0;
     }
   }
   printf("Stable\n");

   return 0;
}

