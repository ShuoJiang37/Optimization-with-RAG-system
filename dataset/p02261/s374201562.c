#include<stdio.h>
#define N 100

typedef struct {

  char moji;
  int num;

}data;

int isStable(data*,data*,int);

int main(){
  data A[N],B[N],C[N],temp1,temp2;
  int i,j,k,n,flag,minj;

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf(" %c%d",&A[i].moji,&A[i].num);
    B[i]=A[i];
    C[i]=A[i];
  }

  //babbule
  flag=1;

  while(flag==1){

    flag=0;

    for(j = n-1; j >= 1; j--){

      if(A[j].num < A[j-1].num){
	temp1 = A[j];
	A[j] = A[j-1];
	A[j-1] = temp1;
	flag = 1;
	
      }
      
    }//for

  }//while

  i=0;
  j=0;

  //serect

   for(i = 0; i <= n-1; i++){

    minj = i;
    
    for(j = i; j <= n-1; j++){

      if(B[j].num < B[minj].num){
	minj = j;
      }
      
    }//for

    if(i != minj){
      
      temp2 = B[i];
      B[i] = B[minj];
      B[minj] = temp2;
    
    }
    

  }//for

  for(k = 0; k < n; k++){
    printf("%c%d",A[k].moji,A[k].num);
    if(k != n-1) printf(" ");
    else printf("\n");
  }
  
  if(isStable(C,A,n)==1){
    printf("Stable\n");
  }else{
    printf("Not stable\n");
  }

  for(k = 0; k < n; k++){
    printf("%c%d",B[k].moji,B[k].num);
    if(k != n-1) printf(" ");
    else printf("\n");
  }

  if(isStable(C,B,n)==1){
    printf("Stable\n");
  }else{
    printf("Not stable\n");
  }

  return 0;
  
}

int isStable(data *in,data *out,int n){

  int a,b,i,j;

  for(i=0;i<n-1;i++){

    for(j=i+1;j<n-1;j++){

      for(a=0;a<n-1;a++){

	for(b=a+1;b<n-1;b++){

	  if(in[i].num==in[j].num && in[i].num == out[b].num && in[j].num == out[a].num && in[i].moji==out[b].moji && in[j].moji==out[a].moji) return 0;

	}
	
      }
    }
  }

  return 1;
  
}

