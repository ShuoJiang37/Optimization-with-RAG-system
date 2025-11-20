#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copyStringArray(char **, char **, int);

main() {

  int n;
  char **o; //入力された配列
  char **b; //BubbleSort
  char **s; //SelectionSort
  char *tmp;

  int i, j, minj;



  scanf("%d", &n);

  o = (char **)malloc(sizeof(char *) *n);
  for( i=0; i<n; i++) {
    o[i] = (char *)malloc(sizeof(char) *3);
  }
  b = (char **)malloc(sizeof(char *) *n);
  for( i=0; i<n; i++) {
    b[i] = (char *)malloc(sizeof(char) *3);
  }
  s = (char **)malloc(sizeof(char *) *n);
  for( i=0; i<n; i++) {
    s[i] = (char *)malloc(sizeof(char) *3);
  }

  for( i=0; i<n; i++) {
    scanf("%s", o[i]);
  }

  for( i=0; i<n; i++) { 
    strcpy(b[i], o[i]);
    strcpy(s[i], o[i]);
  }

  
  //BubbleSort
  for( i=0; i<n; i++) {
    for( j=n-1; j>i; j--) {
      if( b[j][1] < b[j-1][1] ) {
	tmp = b[j];
	b[j] = b[j-1];
	b[j-1] = tmp;
      }
    }
  }
  
  //SelectionSort
  for( i=0; i<n; i++) {
    minj = i;
    for( j=i; j<n; j++) {
      if( s[j][1] < s[minj][1] ) {
	minj = j;
      }
    }
    if(s[i][1] != s[minj][1]) {
      tmp = s[i];
      s[i] = s[minj];
      s[minj] = tmp;
    }
  }


  for( i=0; i<n-1; i++) {
    printf("%s ", b[i]);
  }
  printf("%s\nStable\n", b[n-1]);


  for( i=0; i<n-1; i++) {
    printf("%s ", s[i]);
  }
  printf("%s\n", s[n-1]);
  for( i=0; i<n; i++) {
    if(strcmp(b[i], s[i]) != 0) {
      printf("Not stable\n");
      break;
    }
  }
  if(i == n){
    printf("Stable\n");
  }


  for( i=0; i<n; i++) {    
    free(o[i]);
    free(b[i]);
    free(s[i]);
  }
  free(o);
  free(b);
  free(s);
  
  return 0;

}