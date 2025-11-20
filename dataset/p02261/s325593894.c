#include <stdio.h>
#include <string.h>

void swap(char *a, char *b){
  char t[3];
  strcpy(t, a);
  strcpy(a, b);
  strcpy(b, t);
}

int main(){
  int u, i, j, f, min;
  char in[37][3], bs[37][3];

  scanf("%d", &u);
  for(i = 0; i < u; ++i) scanf("%s", in[i]);

  for(i = 0; i < u; ++i) strcpy(bs[i], in[i]);

  for(i = 0; i < u; ++i)
    for(j = u - 1; j > i; --j)
      if(bs[j][1] < bs[j - 1][1])
	swap(bs[j], bs[j - 1]);

  for(i = 0; i < u; ++i) printf(i != 0 ? " %s" : "%s", bs[i]);
  printf("\nStable\n");

  for(i = 0; i < u; ++i){
    min = i;
    for(j = i + 1; j < u; ++j)
      if(in[j][1] < in[min][1]) 
	min = j;
    if(min != i)
      swap(in[min], in[i]);
  }
  
  f = 0;
  for(i = 0; i < u; ++i){
    printf(i != 0 ? " %s" : "%s", in[i]);
    if(in[i][0] != bs[i][0]) f = 1;
  }
  
  puts("");
  puts(f ? "Not stable" : "Stable");

  
  return 0;
}

