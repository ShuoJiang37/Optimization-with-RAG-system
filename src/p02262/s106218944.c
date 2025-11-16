#include <stdio.h>
#include <string.h>
#define SWAP(type, a, b) {type tmp=a; a=b; b=tmp;}

int main() {
  int n;
  scanf("%d", &n);
  
  int arr[n];
  for (int i=0; i<n; i++) {
    scanf("%d", &arr[i]);
  }

  int G[100], k=0, h=1;
  for (int h_tmp=1; h_tmp<=n; h_tmp=h_tmp*3+1) {
    G[k++]=h_tmp;
    h=h_tmp;
  }

  printf("%d\n", k);
  for (int i=k-1; i>=0; i--) {
    if (i>0) printf("%d ", G[i]);
    else printf("%d\n", G[i]);
  }
  
  int cnt=0;
  while (h) {
    for (int i=h; i<n; i++) {
      for (int j=i; j>=h && arr[j-h]>arr[j]; j-=h) {
        SWAP(int, arr[j], arr[j-h])
        cnt++;
      }
    }
    h/=3;
  }

  printf("%d\n", cnt);
  for (int i=0; i<n; i++) {
    printf("%d\n", arr[i]);
  }
  return 0;
}
