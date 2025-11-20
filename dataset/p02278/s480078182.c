#include <stdio.h>

#define MAX_N 1000
#define MAX_W 10000

int n;
int w[MAX_N];
int sorted_w[MAX_N];
int idx[MAX_W+1];
int used[MAX_N];

int min(int a, int b) {
  return a > b ? b : a;
}

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void bubbleSort() {
  int i, j;
  for(i = 0; i < n-1; i++) {
    for(j = n-1; j > i; j--) {
      if(sorted_w[j] < sorted_w[j-1]) {
	swap(&sorted_w[j], &sorted_w[j-1]);
      }
    }
  }
}

int main() {
  int i;
  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    scanf("%d", w+i);
    sorted_w[i] = w[i];
  }
  bubbleSort();
  for(i = 0; i < n; i++) idx[sorted_w[i]] = i;
  int minimam = sorted_w[0];
  int ans = 0;
  for(i = 0; i < n; i++) {
    if(used[i]) continue;
    int pos = i;
    int minimal = MAX_W;
    int sum = 0;
    int cnt = 0;
    while(!used[pos]) {
      used[pos] = 1;
      if(w[pos] < minimal) minimal = w[pos];
      sum += w[pos];
      cnt++;
      pos = idx[w[pos]];
    }
    //printf("%d %d %d\n", pos, minimal, sum);
    ans += min(sum-minimal+(cnt-1)*minimal,
	       sum-minimal+(cnt-1)*minimam+(minimam+minimal)*2);
  }
  printf("%d\n", ans);

  return 0;
}