#include<stdio.h>
typedef struct{
  char m;
  int n;
  int o;
} data;

void BubbleSort(data*,int);
void SelectionSort(data*,int);


int main(){
  data C[36],A[36];
  int N,i;


  scanf("%d",&N);

  for(i=0;i<N;i++) {
    scanf(" %c%d",&C[i].m,&C[i].n);
    C[i].o=i;
  }
  for(i=0;i<N;i++){
    A[i]=C[i];
   
  }
 
  BubbleSort(C,N);
  SelectionSort(A,N);



  return 0;
}

void BubbleSort(data *C,int N){
  int i,j,c=0;
  data A;
  for(i=0;i<N;i++){
    for(j=N-1;j>=i+1;j--){
      if(C[j].n<C[j-1].n){
	A=C[j];
	C[j]=C[j-1];
	C[j-1]=A;
      }
    }
    
  }
  for(i=0;i<N;i++){
    if(i!=0)printf(" ");
    printf("%c%d",C[i].m,C[i].n);

  }
    printf("\n");

    for(i=0;i<=N;i++){
      if(C[i].n==C[i+1].n&&C[i].o>C[i+1].o) c++;
    }    
    if(c>0)printf("Not stable\n");
    else printf("Stable\n");

    
}


void SelectionSort(data *C,int N){
  int i,j,minj,c=0;
  data A;
  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(C[j].n<C[minj].n)minj=j;
      }
    A=C[i];
    C[i]=C[minj];
    C[minj]=A;
  }

  for(i=0;i<N;i++){
    if(i!=0)printf(" ");
    printf("%c%d",C[i].m,C[i].n);
  }
    printf("\n");

   for(i=0;i<=N;i++){
     if(C[i].n==C[i+1].n&&C[i].o>C[i+1].o)c++;
    }   

    if(c>0)printf("Not stable\n");
    else printf("Stable\n");
}