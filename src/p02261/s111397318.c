#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  int i, j, a, b, n, isstable, minj, tmpi;
  char tmpc;
  char c[36][2];
  char bufc[36], bc[36], sc[36];
  int bufi[36], bi[36], si[36];

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%s", c[i]);
    bufc[i] = bc[i] = sc[i] = c[i][0];
    bufi[i] = bi[i] = si[i] = c[i][1] - '0';
  }

  //BubbleSort
  for(i = 0; i < n; i++){
    for(j = n-1; j > i; j--){
      if(bi[j] < bi[j-1]){
        tmpi = bi[j];
        tmpc = bc[j];
        bi[j] = bi[j-1];
        bc[j] = bc[j-1];
        bi[j-1] = tmpi;
        bc[j-1] = tmpc;
      }
    }
  }

  //SelectionSort
  for(i = 0; i < n; i++){
    minj = i;
    for(j = i; j < n; j++){
      if(si[j] < si[minj]){
        minj = j;
      }
    }
    tmpi = si[i];
    tmpc = sc[i];
    si[i] = si[minj];
    sc[i] = sc[minj];
    si[minj] = tmpi;
    sc[minj] = tmpc;
  }

  for(i = 0; i < n-1; i++)
    printf("%c%d ", bc[i], bi[i]);
  printf("%c%d\n", bc[i], bi[i]);
  isstable = 1;
  for(i = 0; i < n; i++)
    for(j = i+1; j < n; j++)
      for(a = 0; a < n; a++)
        for(b = a+1; b < n; b++)
          if(bufi[i] == bufi[j] && (bufc[i] == bc[b] && bufi[i] == bi[b]) && (bufc[j] == bc[a] && bufi[j] == bi[a]))
            isstable = 0;
  if(isstable == 0)printf("Not stable\n");
  else printf("Stable\n");

  for(i = 0; i < n-1; i++)
    printf("%c%d ", sc[i], si[i]);
  printf("%c%d\n", sc[i], si[i]);
  isstable = 1;
  for(i = 0; i < n; i++)
    for(j = i+1; j < n; j++)
      for(a = 0; a < n; a++)
        for(b = a+1; b < n; b++)
          if(bufi[i] == bufi[j] && (bufc[i] == sc[b] && bufi[i] == si[b]) && (bufc[j] == sc[a] && bufi[j] == si[a]))
            isstable = 0;
  if(isstable == 0)printf("Not stable\n");
  else printf("Stable\n");

  return 0;
}