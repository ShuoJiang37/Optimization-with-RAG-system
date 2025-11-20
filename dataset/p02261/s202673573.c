#include<stdio.h>

typedef struct{
  char kigo;
  int num;
} C;

int main(){
  C A[36],B[36],tmp;
  int i,j,N,mini,c=0;
  scanf("%d",&N);
  for(i=0;i<N;i++)scanf(" %c%d",&A[i].kigo,&A[i].num);
  for(i=0;i<N;i++)B[i]=A[i];
//bubble
  for(i=0;i<N;i++){
    for(j=N-1;j>i;j--){
      if(A[j].num<A[j-1].num){
        tmp=A[j];
        A[j]=A[j-1];
        A[j-1]=tmp;
      }
    }
  }
  for(i=0;i<N-1;i++) printf("%c%d ",A[i].kigo,A[i].num);
  printf("%c%d\n",A[N-1].kigo,A[N-1].num);
  printf("Stable\n");
//selection
   for(i=0;i<N-1;i++){
    mini=i;
    for(j=i;j<N;j++){
      if(B[j].num<B[mini].num) mini=j;
    }
    tmp=B[i];
    B[i]=B[mini];
    B[mini]=tmp;
  }

   for(i=0;i<N-1;i++) printf("%c%d ",B[i].kigo,B[i].num);
   printf("%c%d\n",B[N-1].kigo,B[N-1].num);

   for(i=0;i<N;i++){
     if(A[i].kigo!=B[i].kigo||A[i].num!=B[i].num){
       printf("Not stable\n");
       return 0;
     }
   }
   printf("Stable\n");

   return 0;
}



