#include <stdio.h>

#define MAX 1000000
#define MAX_INDEX 100

int InsertionSort(int [],int,int);
int ShellSort(int [],int);

int main(){
  int A[MAX];
  int i,n;
  int cnt;
  
  scanf("%d",&n);

  for (i = 0;i < n;i++)
    scanf("%d",&A[i]);

  cnt = ShellSort(A,n);

  printf("%d\n",cnt);
  
  for (i = 0;i < n;i++)
    printf("%d\n",A[i]);
  
  return 0;
}

int InsertionSort(int A[],int n,int g){
  int i,j,v,cnt = 0;
  
  for (i = g;i < n;i++){
    v = A[i];
    j = i - g;
    
    while (j >= 0 && A[j] > v){
      A[j+g] = A[j];
      j = j - g;
      cnt++;
    }
  
    A[j + g] = v;
}

  return cnt;
}
  
int ShellSort(int A[],int n){
  int i,cnt = 0,m,h = 1;
  int G[MAX_INDEX];
  
  for (i = 0;i < MAX_INDEX;i++){
    if (h > n)
      break;
    
    G[i] = h;
    h = 3*h + 1;
  }
  
  m = i;

  printf("%d\n",m);

  for (i = 0;i < m;i++){
    if (i)
      printf(" ");

    printf("%d",G[m-1 - i]);
  }

  printf("\n");
  
  for (i = 0;i < m;i++)
    cnt += InsertionSort(A, n, G[m-1 - i]);

    return cnt;
}

