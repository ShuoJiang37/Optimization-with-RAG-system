#include<stdio.h>
#define MMM 9
int sonyu(int*,int,int);
int cnt=0;
int main() {
  int i, j, N, A[1000000], key, k,cnt2=0;
  scanf("%d", &N);
  for(i = 0; i < N; i++)
    scanf("%d", &A[i]);
  int g[9]={1507,203,110,9,7,5,3,2,1};
  for(i=0;i<MMM;i++){
    if(g[i]<=N){
      sonyu(A,N,g[i]);
      cnt2++;
    }
    
  }
  printf("%d\n",cnt2);
  for(i=MMM-cnt2;i<MMM;i++){
    printf("%d",g[i]);
    if(i == cnt2-1)
      printf("\n");
    else
      printf(" ");
  }
  printf("%d\n",cnt);
  for(i = 0; i < N; i++)
    printf("%d\n", A[i]);




}
int sonyu(int *A,int n, int g){
  int i,j,key;
  for(i=g;i<n;i++){
    j=i-g;
    key=A[i];
    //    printf("i = %d\n",i);
    while(j >= 0 && A[j] > key) {
      A[j + g] = A[j];
      j-=g;
      cnt++;
    }
  A[j + g] = key;
  // for(j = 0; j < n; j++)
  //printf("%d\n", A[j]);

  }
  return 0;
}

