
#include <stdio.h>
int k=0;
int A[100];
void bubbleSort(int);

int main()
{
  int N,i;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  bubbleSort(N);
  for(i=0;i<N;i++){
    if(i>0) printf(" ");
    printf("%d",A[i]);
    //if(i==N) printf("%d",A[N]);
  }
  //printf("\n");
  printf("\n%d\n",k);
  return 0;
}

void bubbleSort(int h)
{
  int flag=1,temp,j;
  while(flag){
    flag=0;
    for(j=h-1;j>=1;j--){
      if(A[j]<A[j-1]){
	temp=A[j];
	A[j]=A[j-1];
	A[j-1]=temp;
	k++;
	flag=1;
      }
    }
  }
}
	
  