#include <stdio.h>
  
  
int cnt = 0;
int a[1000000];
  
void insertionSort(int a[], int n, int g){
  int i, j, key;
  
  for(i = g;i < n;i++){
    key = a[i];
    j = i - g;
    while(j >= 0 && a[j] > key){
      a[j+g] = a[j];
      j = j - g;
      cnt++;
    }
    a[j+g] = key;
  }
}
  
void shellSort(int a[], int n){
  int m = 13; 
  int g[13] = {1, 4, 13, 40, 121, 364, 1093, 3280, 9841, 29524, 88573, 165720, 797161};
  int i;
  
  cnt = 0;
  while(g[m-1] > n){
    m--;
  }
  printf("%d\n", m);
  for(i = m-1;i >= 1;i--){
    printf("%d ", g[i]);
  }
  printf("%d\n", g[0]);
  for(i = m-1;i >= 0;i--){
    insertionSort(a, n, g[i]);
  }
}
 
main(){
  int n, i;
  
  scanf("%d", &n);
  for(i = 0;i < n;i++){
    scanf("%d", &a[i]);
  }
  shellSort(a, n);
  printf("%d\n", cnt);
  for(i = 0;i < n;i++){
    printf("%d\n", a[i]);
  }
  return 0 ;
}
