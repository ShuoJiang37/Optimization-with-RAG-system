#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
  char str[2000];
  char dmy[10];
  char space[] = " ";
  char *tok;
  int array[2000];
  int n = 200;
  int i = 0;
  int j = 0;
  int v;
  int k;

  // n?????????
  scanf("%d", &n);
  fgets(dmy, 20, stdin);

  // ??°????????????
  fgets(str, 2000, stdin);

  // ???????????????
  tok = strtok(str, space);
  while(tok != NULL) {
    array[i] = atoi(tok);
    i++;
    tok = strtok(NULL, space);
  }

  i = 0; // ?????????

  // ??????
  for(j = 0; j < n; j++){
    if(j == n-1){
      printf("%d\n", array[j]);
    } else {
      printf("%d ", array[j]);
    }
  }

  // ?????\?????????
  for(i = 1; i < n; i++) {

    v = array[i];
    k = i - 1;
    while(k >= 0 && array[k] > v) {
      array[k + 1] = array[k];
      k--;
    }
    array[k + 1] = v;

    // ??????
    for(j = 0; j < n; j++){
      if(j == n-1){
        printf("%d\n", array[j]);
      } else {
        printf("%d ", array[j]);
      }
    }
  }
  return 0;
}