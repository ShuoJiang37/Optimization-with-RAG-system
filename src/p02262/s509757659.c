#include <stdio.h>
#include <math.h>

int insertionSort(int a[1000010],int n, int g){
  int count = 0;
  for(int i = g; i < n; i++){
    int v = a[i];
    int j = i - g;  
    while(j >= 0 && a[j] > v){
      a[j + g] = a[j];
      j = j - g;
      count++;
    }
    a[j + g] = v;  
  }
  return count;
}

int main(void){
  int a[1000010],n,m,i,g[1000010],count = 0;
  int arr[] = {0,3,12,39,120,363,1092,3279,9840,29523,88572,265719,797160};
  scanf("%d",&n);
  for(i = 0; i < n; i++)scanf("%d",&a[i]);
  for(i = 1; i < 13; i++){
    if(arr[i - 1] < n && n <= arr[i])break;
  }
  m = i;
  printf("%d\n",m);
  for(i = 0; i < n; i++){
    g[i] = arr[i] + 1;
  }
  for(i = m - 1; i >= 0; i--){
    if(i != m - 1)printf(" ");
    printf("%d",g[i]);
  }
  for(i = m - 1; i >= 0; i--){
    count += insertionSort(a,n,g[i]);
  }
  printf("\n%d",count);

  for(i = 0; i < n; i++)printf("\n%d",a[i]);
  printf("\n");
  return 0;
}
