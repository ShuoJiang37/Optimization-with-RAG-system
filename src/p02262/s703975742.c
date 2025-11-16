#include<stdio.h>
#define N 1000000
main()
{
  int i,j,k,n,v,A[N],cnt,m;
  scanf("%d",&n);
  int G[12];
  for(i = 0; i < n; i++) scanf("%d",&A[i]);

  i = 0;
  G[i] = 1;
  m = 1;

  while (3 * G[m-1] + 1 < n) {
    G[m] = 3 * G[m-1] + 1;
    m++;
  }

  for (i = 0; i < m / 2; i++) {
    v = G[i];
    G[i] = G[m-1-i];
    G[m-1-i] = v;
  }


  printf("%d\n",m);
  cnt = 0;

  for(i = 0; i < m; i++){
    for(j = G[i]; j < n; j++){
      v = A[j];
      k = j - G[i];
      while(k >= 0 && A[k] > v){
	A[k+G[i]] = A[k];
	k = k - G[i];
	cnt++;
      }
      A[k+G[i]] = v;
    }
  }

  for (i = 0; i < m; i++) {
    if (i != m - 1) printf("%d ", G[i]);
    else printf("%d\n", G[i]);
  }

    printf("%d\n",cnt);

    for(i = 0; i < n; i++)printf("%d\n",A[i]);
    return 0;
}