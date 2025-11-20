#include <stdio.h>

int main(void){
  int n, i, j, minj, flag;
  int an[37], bn[37], xn;
  char am[37], bm[37], str[5], xm;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf(" %s", str);
    am[i] = str[0];
    an[i] = str[1] - '0';
    bm[i] = am[i];
    bn[i] = an[i];
  }

  for (i = 0; i < n; i++) {
    for (j = n - 1; j > i; j--) {
      if (an[j] < an[j-1]) {
        xn = an[j];
        an[j] = an[j-1];
        an[j-1] = xn;
        xm = am[j];
        am[j] = am[j-1];
        am[j-1] = xm;
      }
    }
  }

  for (i = 0; i < n; i++) {
    minj = i;
    for (j = i; j < n; j++) {
      if (bn[j] < bn[minj]) {
        minj = j;
      }
    }
    if (i != minj){
      xn = bn[i];
      bn[i] = bn[minj];
      bn[minj] = xn;
      xm = bm[i];
      bm[i] = bm[minj];
      bm[minj] = xm;
    }
  }

  flag = 0;
  for (i = 0; i < n; i++) {
    if (am[i] != bm[i]) {
      flag = 1;
      break;
    }
  }

  for (i = 0; i < n; i++) {
    if (i <= n - 2) {
      printf("%c%d ", am[i], an[i]);
    }
    else if (i == n - 1) {
      printf("%c%d\n", am[i], an[i]);
    }
  }
  printf("Stable\n");
  for (i = 0; i < n; i++) {
    if (i <= n - 2) {
      printf("%c%d ", bm[i], bn[i]);
    }
    else if (i == n - 1) {
      printf("%c%d\n", bm[i], bn[i]);
    }
  }
  if (flag == 0) {
    printf("Stable\n");
  }
  else if (flag == 1) {
    printf("Not stable\n");
  }

  return 0;
}
