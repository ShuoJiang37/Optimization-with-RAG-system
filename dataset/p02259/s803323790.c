#include <stdio.h>

int main(void) {
  int i, j, k, a[100], n, l, flag = 1, temp, count = 0;
  char buf[2];
  scanf("%d", &l);
  for (n = 0; n < l && (j = scanf("%d%1[\n]", a+n, buf)) == 1; n++) ;
  if (j == 2)
  n++;

  while (flag) {
    flag = 0;
    for (j = l - 1; j > 0; j--) {
      if (a[j] < a[j - 1]) {
        temp = a[j];
        a[j] = a[j - 1];
        a[j - 1] = temp;
        flag = 1;
        count++;
      }
    }
  }

    for (k = 0; k < l; k++) {
      printf("%d", a[k]);
      if (k < n - 1) {
        printf(" ");
      }
    }
    printf("\n");
    printf("%d\n", count);
    return 0;
  }

