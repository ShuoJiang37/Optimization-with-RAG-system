#include <stdio.h>
#include <stdlib.h>

#define min(a, b) (a)<(b)?(a):(b)

int compar(const void *a, const void *b){
  return *((int*)a)-*((int*)b);
}

int main()
{
  int i, j, k, n, wmin, cost = 0;
  scanf("%d", &n);
  int w[n], c[n], u[n];
  for (i=0; i<n; i++) {
    scanf("%d", w+i);
    u[i] = w[i];
    c[i] = 0;
    if (i==0 || wmin>w[i]) wmin=w[i];
  }
  qsort((void*)u, n, sizeof(int), compar);
  int loop[n], xi;
  k = n;
  while (k>0) {
    for (i=0; c[i]==1; i++);
    c[i]=1;
    k--;
    loop[0]=i;
    int len=1;
    while (1) {
      for (xi=0; u[xi]!=w[i]; xi++);   // xi = u.index(w[i])
      if (c[xi]==1) break;
      c[xi] = 1;
      k--;
      loop[len++]=xi;
      i = xi;
    }

    if (len==1) continue;
    int lmin=w[loop[0]];

    for (i=0; i<len; i++) {
      if (lmin>w[loop[i]]) lmin=w[loop[i]];
      cost += w[loop[i]];
    }
    if (lmin==wmin) cost += lmin*(len-2);
    else            cost += min(lmin+(len+1)*wmin, lmin*(len-2));
  }
  printf("%d\n", cost);

  return 0;
}
