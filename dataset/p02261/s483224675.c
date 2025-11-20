#include<stdlib.h>
#include<stdio.h>
#include<string.h>


typedef struct{
  int x;
  char c;
}card;

int main(){
  int i,j,n,hantei,mini;
  card **A,**B,*swap;
  scanf("%d",&n);
  A=malloc(n*sizeof(card *));
  B=malloc(n*sizeof(card *)); 
  for(i=0;i<n;i++) A[i]=malloc(sizeof(card));
  for(i=0;i<n;i++) B[i]=malloc(sizeof(card));
  for(i=0;i<n;i++){
    scanf(" %c %d",&(A[i]->c),&(A[i]->x));
  }
  for(i=0;i<n;i++){
    B[i]->x=A[i]->x;
    B[i]->c=A[i]->c;
  }
  for(i=0;i<n-1;i++){
    hantei=0;
    for(j=n-1;j>=i+1;j--){
      if((A[j]->x)<(A[j-1]->x)){
        swap=A[j];
        A[j]=A[j-1];
        A[j-1]=swap;
        hantei=1;
      }
    }
    if(hantei==0) break;
  }
  for(i=0;i<n-1;i++) printf("%c%d ",A[i]->c,A[i]->x);
  printf("%c%d\n",A[n-1]->c,A[n-1]->x);
  printf("Stable\n");
  
  for(i=0;i<n-1;i++){
    mini=i;
    for(j=i+1;j<n;j++){
      if((B[mini]->x)>(B[j]->x)) mini=j;
    }
    if(mini!=i){
      swap=B[mini];
      B[mini]=B[i];
      B[i]=swap;
    }
  }
  for(i=0;i<n-1;i++) printf("%c%d ",B[i]->c,B[i]->x);
  printf("%c%d\n",B[n-1]->c,B[n-1]->x);
  for(i=0;i<n;i++){
    if(A[i]->c!=B[i]->c){
      printf("Not stable\n");
      return 0;
    }
  }
  printf("Stable\n");
  return 0;
}
  