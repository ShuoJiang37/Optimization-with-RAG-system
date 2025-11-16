#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int n, i, j, sum, minj, count;
int A[MAX], B[MAX], C[MAX];

int min(int x, int y)
{
  if(x < y) return x;
  else return y;
}

int solve(int x)
{
  for(i = 0; i < n; i++){
    if(A[i] == x) return i;
  }
}

int main()
{
  int ans = 0, x, tmp;

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
    B[i] = A[i];
  }

  for(i = n - 1; i > 0; i--){
    for(j = 0; j < i; j++){
      if(B[j + 1] < B[j]){
        tmp = B[j];
        B[j] = B[j + 1];
        B[j + 1] = tmp;
      }
    }
  }

  for(i = 0; i < n; i++){
    C[i] = 0;
  }

  for(i = 0; i < n; i++){
    x = i;
    count = 0;
    sum = 0;
    minj = (1 << 24);
    while(C[x] == 0){
      C[x] = 1;
      count++;
      sum += A[x];
      minj = min(minj, A[x]);
      x = solve(B[x]);
    }
    if(count < 2) continue;
    ans += min(sum + B[0] * (count + 1) + minj, sum + minj * (count - 2));

  }

  printf("%d\n", ans);

  return 0;
}

