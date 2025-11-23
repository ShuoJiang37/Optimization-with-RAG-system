#include <stdio.h>
int A[100];
int k=0;
void selectionSort(int);

int main()
{
  int N,i,l,b;
  double f;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  selectionSort(N);
  for(i=0;i<N;i++){
    if(i>0) printf(" ");
    printf("%d",A[i]);
  }
  //f=(double)k/2;
  //f=10*f;
  //b=f;
  //if(b%10>=5) k=b/10+1;
  //else k=f/10;
  printf("\n%d\n",k);
  return 0;
}

void selectionSort(int h)
{
  int i,minj,j,temp;
  for(i=0;i<=h-2;i++){
    minj=i;
    for(j=i;j<=h-1;j++){
      if(A[j]<A[minj]){
	minj=j;
	//k++;
      }
    }
    temp=A[i];
    A[i]=A[minj];
    A[minj]=temp;
    if(i!=minj) k++;
  }
}