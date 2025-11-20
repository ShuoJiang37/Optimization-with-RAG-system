#include <stdio.h>
#include <math.h>

int m = 0;
int g[10000000];
int cnt;

void array_G(int n) {
  int number = 1;
  while (number <= n) {
    g[m] = number;
    number = 3 * number + 1;
    m++;
  }
}

void insertion_sort(int a[], int n, int g) {
  int v;
  int j;
  for (int i = g; i < n; i++) {
    v = a[i];
    j = i - g;
    while (j >= 0 && a[j] > v) {
      a[j + g] = a[j];
      j = j - g;
      cnt++;
    }
    a[j + g] = v;
  }
}

void shell_sort(int a[], int n) {
  cnt = 0;
  array_G(n);
  for (int i = m - 1; i >= 0; i--)
    insertion_sort(a, n, g[i]);
}

int main(void) {
  int n;
  int a[1000000];

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  shell_sort(a, n);

  printf("%d\n", m);
  for (int i = m - 1; i >= 0; i--) {
    printf("%d", g[i]);
    if (i != 0)
      printf(" ");
  }
  printf("\n%d\n", cnt);

  for (int i = 0; i < n; i++) {
    printf("%d\n", a[i]);
  }
  
  return 0;
}

