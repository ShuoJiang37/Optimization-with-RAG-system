#include<stdio.h>


#define N 100

typedef struct {

  char art;
  int value;

}Roll;

void BubbleSort(Roll *,int);
void SelectionSort(Roll *,int);
int  isStable(Roll *,Roll *,int n);

int main (){

  int n,i;
  Roll A[N],B[N];

   scanf("%d",&n);
   for(i=0;i<n;i++){
    scanf(" %c",&A[i].art);
    scanf("%d",&A[i].value);
   }
   for(i=0;i<n;i++)
     B[i]=A[i];

  BubbleSort(A,n);

  for(i=0;i<n-1;i++)
    printf("%c%d ",A[i].art,A[i].value);
    printf("%c%d\n",A[n-1].art,A[n-1].value);
   printf("Stable\n");

   SelectionSort(B,n);
   
   for(i=0;i<n-1;i++)
     printf("%c%d ",B[i].art,B[i].value);
   printf("%c%d\n",B[n-1].art,B[n-1].value);
   

   if(isStable(A,B,n)==1)
     printf("Stable\n");
   else printf("Not stable\n");
   
   return 0;
}
void BubbleSort(Roll *Sort,int n){

  int i,flag=1;
  Roll tmp;
  
  while(flag){
    flag = 0;
    for(i = 0;i < n;i++){
      if(Sort[i].value < Sort[i-1].value){
	tmp = Sort[i];
	Sort[i]=Sort[i-1];
	Sort[i-1]=tmp;
	flag = 1;

      }
    }
  }
}

void SelectionSort(Roll *Sort,int n){
 
  int i,j,min;
  Roll tmp;
 
  for(i = 0;i < n;i++){
    min = i;
    for(j = i;j < n;j++){
 
      if(Sort[j].value < Sort[min].value){
    min = j;
 
      }
    }   
    if(Sort[i].value != Sort[min].value){ 
      tmp = Sort[i];
      Sort[i] = Sort[min];
      Sort[min] = tmp;
 
    }
     
  }
}
int  isStable(Roll *in,Roll *out,int n){
  
  int i,j,a,b;

  for(i = 0;i < n;i++){

    for(j = i+1;j < n;j++){

      for(a = 0;a < n;a++){

	for(b = a+1;b < n;b++){

	  if(in[i].value==in[j].value&&in[i].value == out[b].value&&in[i].art==out[b].art&&in[j].value== out[a].value&&in[j].art==out[a].art)
	    return 0;
	}
      }
    }
  }
  return 1;
}