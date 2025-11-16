#include <stdio.h>

int c=0;
void insertSort(int arr[],int n ,int g){
	for (int  i = g; i < n;i++){
	  int v = arr[i];
      int j = i - g;
      while ( j >= 0 && arr[j] > v){
        arr[ j +g] = arr[ j];
        j = j-g;
        c++;
      }
      arr[ j +g] =v;
	}
};
void shellSort(int A[],int n){

	int G [13]= {1,4,13,40,121,364,1093,3280,9841,29524,88573,265720,797161}; //"h"=3*"h-1"+1
	int m= 0;
for (;n/9 >= G[m];m++){}
	printf("%d\n",m+1);
	for (int i= m;i >= 0;i--){
		printf("%d ",G[i]);
		insertSort(A,n,G[i]);
	}
	printf("\n");
};
int main(){

  int n ,i ,j , m ,t,g ,k ,v;
  scanf("%d" ,&n);
  int arr[n];
  for ( i = 0; i < n; i++){
    scanf("%d",&arr[i]);
  }
shellSort(arr,n);
  printf("%d\n",c);

  for ( i = 0; i < n; i++){
    printf("%d\n",arr[i]);
  }


  return 0;

}

