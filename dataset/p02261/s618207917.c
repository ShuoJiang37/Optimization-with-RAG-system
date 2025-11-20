#include <stdio.h>
#include <string.h>

void swap(char *x, char *y){
  char t[3];
  strcpy(t, x);
  strcpy(x, y);
  strcpy(y, t);
}

int main(){
  int n, i, j, f, min;
  char in[37][3], bs[37][3];
  scanf("%d", &n);
  for(i = 0; i < n; ++i) scanf("%s", in[i]);

  for(i = 0; i < n; ++i) strcpy(bs[i], in[i]);

  for(i = 0; i < n; ++i)
    for(j = n - 1; j > i; --j)
      if(bs[j][1] < bs[j - 1][1])
	swap(bs[j], bs[j - 1]);

  for(i = 0; i < n; ++i) printf(i != 0 ? " %s" : "%s", bs[i]);
  printf("\nStable\n");

  for(i = 0; i < n; ++i){
    min = i;
    for(j = i + 1; j < n; ++j)
      if(in[j][1] < in[min][1]) 
	min = j;
    if(min != i)
      swap(in[min], in[i]);
  }
  f = 0;
  for(i = 0; i < n; ++i){
    printf(i != 0 ? " %s" : "%s", in[i]);
    if(in[i][0] != bs[i][0]) f = 1;
  }
  puts("");
  puts(f ? "Not stable" : "Stable");
  return 0;
}

