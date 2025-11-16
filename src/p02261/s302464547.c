#include <stdio.h>
#include <string.h>

int main(){
  int n, i, j, min;
  char c1[36][3], c2[36][3];
  char mark[3];

  scanf("%d", &n);

  for(i=0; i<n; i++){
    scanf("%s", c1[i]);
    strcpy(c2[i], c1[i]);
  }

  for(i=0; i<n-1; i++)
    for(j=n-1; j>i; j--)
      if(c1[j][1] < c1[j-1][1]){
	strcpy(mark, c1[j]);
	strcpy(c1[j], c1[j-1]);
	strcpy(c1[j-1], mark);
      }

  for(i=0; i<n-1; i++) printf("%s ", c1[i]);
  printf("%s\nStable\n", c1[i]);

  for(i=0; i<n; i++){
    min = i;
    for(j=i; j<n; j++){
      if(c2[j][1] < c2[min][1]) min = j;
    }
    if(i != min){
      strcpy(mark, c2[i]);
      strcpy(c2[i], c2[min]);
      strcpy(c2[min], mark);
    }
  }

  for(i=0; i<n-1; i++) printf("%s ", c2[i]);
  printf("%s\n", c2[i]);

  for(i=0; i<n; i++)
    if(strcmp(c1[i], c2[i]) != 0) break;
  if(i==n) printf("Stable\n");
  else printf("Not stable\n");

  return 0;
}

