#include<stdio.h>
int main(void){
  struct as{
    int n;
    char C;
  }A[36],B[36],t;

  int i,j,len,mini;
  char c;
  scanf("%d",&len);
  for(i=0;i<len;i++){
    scanf("%c%c%d",&c,&A[i].C,&A[i].n);
  }
  for(i=0;i<len;i++){
    B[i]=A[i];
  }
  for(i=0;i<len;i++){
    for(j=len-1;j>i;j--){
      if(A[j].n<A[j-1].n){
	t=A[j];
	A[j]=A[j-1];
	A[j-1]=t;
      }
    }
  }
  for(i=0;i<len;i++){
    if(i!=0){
      printf(" ");
    }
    printf("%c%d",A[i].C,A[i].n);
  }
  printf("\n");
  printf("Stable\n"); 
  for(i=0;i<len;i++){
    mini=i;
     for(j=i;j<len;j++){
       if(B[j].n<B[mini].n){
	 mini=j;
       }
     }
     if(i!=mini){
       t.n=B[i].n;
       B[i].n=B[mini].n;
       B[mini].n=t.n;
       t.C=B[i].C;
       B[i].C=B[mini].C;
       B[mini].C=t.C;

     }
  }
  for(i=0;i<len;i++){
    if(i!=0){
      printf(" ");
    }
    printf("%c%d",B[i].C,B[i].n);
  }
  printf("\n");
  
   
  for(i=0;i<len;i++){
    if(B[i].C!=A[i].C){
	printf("Not stable\n");
	break;
      }
  } 
    if(i==len)printf("Stable\n");
  return 0;
}