#include <stdio.h>

int main(){

  int n, i, j, v, m, k, count=0;
  int a[1000000] = {0};
  int g[100] = {0};

  scanf("%d",&n);

  for(i=0; i<n; i++) scanf("%d", &a[i]);

  i=0;
  g[0]=1;

  while(1){
    if(g[i]>n){
      m=i;
      break;
    }else{
      g[i+1]=3*g[i]+i;
      i++;
    }
  }

  for(i=0; i<m; i++){
    for(j=g[m-1-i]; j<n; j++){
      v=a[j];
      k=j-g[m-1-i];
      while(k>=0 && a[k]>v){
        a[k+g[m-i-1]]=a[k];
        k=k-g[m-i-1];
        count++;
      }
      a[k+g[m-i-1]]=v;
    }
  }

  printf("\n%d\n" ,m);

  for(i=0; i<m; i++){
    if(i==m-1) printf("%d\n", g[m-i-1]);
    else printf("%d ", g[m-i-1]);
  }

  printf("%d\n", count);

  for(i=0; i<n; i++) printf("%d\n", a[i]);

  return 0;
}