

#include <stdio.h>
#include <string.h>
#define N 200

void sort(char *x, char *y){
  char t[3];
  strcpy(t, x);
  strcpy(x, y);
  strcpy(y, t);
}

int main(){
  int n, i, j, f, min;
  char a[37][3], b[37][3];
  scanf("%d", &n);
  for(i = 0; i < n; ++i) scanf("%s", a[i]);

  for(i = 0; i < n; ++i) strcpy(b[i], a[i]);

  for(i = 0; i < n; ++i)
    for(j = n - 1; j > i; --j)
      if(b[j][1] < b[j - 1][1])
	sort(b[j], b[j - 1]);

  for(i = 0; i < n; ++i) printf(i != 0 ? " %s" : "%s", b[i]);
  printf("\nStable\n");

  for(i = 0; i < n; ++i){
    min = i;
    for(j = i + 1; j < n; ++j)
      if(a[j][1] < a[min][1]) 
	min = j;
    if(min != i)
      sort(a[min], a[i]);
  }
  f = 0;
  for(i = 0; i < n; ++i){
    printf(i != 0 ? " %s" : "%s", a[i]);
    if(a[i][0] != b[i][0]) f = 1;
  }
  puts("");
  puts(f ? "Not stable" : "Stable");
  return 0;
}

