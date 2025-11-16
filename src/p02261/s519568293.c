#include <stdio.h>
typedef struct {
  char e;
  int num;
}To;
void BubbleSort(To*, int);
void SelectionSort(To*, int);
int main(){
  int flag,n,i;
  char a[3];
  To data[36],data2[36];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s",a);
    data[i].e=a[0];
    data[i].num=a[1]-'0';
    data2[i]=data[i];
  }
  
  BubbleSort(data,n);
  for(i=0;i<n;i++){
    printf("%c%d",data[i].e,data[i].num);
    if(i==n-1)break;
    printf(" ");
  }
  printf("\n");
  printf("Stable\n");
 
  SelectionSort(data2,n);
  flag=0;
  for(i=0;i<n;i++){
    printf("%c%d",data2[i].e,data2[i].num);
    if(data2[i].e!=data[i].e)
      flag=1;
    if(i==n-1)break;
    printf(" ");
  }
  printf("\n");
  if(flag==1)
    printf("Not stable\n");
  else printf("Stable\n");
  
 
  return 0;
}
void BubbleSort(To* A, int N){
  int flag=1,i,j;
  To tmp;
  while(flag==1){
    flag=0;
    for(j=N-1;j>=1;j--){
      if(A[j].num<A[j-1].num){
	tmp=A[j];
	A[j]=A[j-1];
	A[j-1]=tmp;
	flag=1;       
      }
    }
  } 
}
void SelectionSort(To* A, int N){
  int i,j,minj;
  To tmp;
  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j].num<A[minj].num)
	minj=j;
    }
    tmp=A[i];
    A[i]=A[minj];
    A[minj]=tmp; 
  }
}

