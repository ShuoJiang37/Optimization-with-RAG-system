#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define DATA_MAX_NUM 100

void dump_array(int32_t num, int32_t data[])
{
  int i;
  for (i = 0; i < num; i++) {
    if (0 < i) printf(" ");
    printf("%d", data[i]);
  }
  printf("\n");
  return;
}

void bubble_sort(int32_t num, int32_t data[])
{
  bool flag = true;
  int j = 0;
  int count = 0;
  while (flag) {
    flag = false;
    for (j = num - 1; 0 < j; j--) {
      if (data[j - 1] > data[j]) {
        int v = data[j];
        data[j] = data[j - 1];
        data[j - 1] = v;
        flag = true;
        count++;
      }
    }
  }
  dump_array(num, data);
  printf("%d\n", count);
  return;
}
int main(void)
{
  int32_t i = 0;
  int32_t num = 0;
  int32_t data[DATA_MAX_NUM];

#if defined(TEST)
  int32_t test[] = {5, 3, 2, 4, 1};

  dump_array(sizeof(test) / sizeof(test[0]), test);
  bubble_sort(sizeof(test) / sizeof(test[0]), test);
  dump_array(num, data);
#else
  scanf("%d", &num);

  for (i = 0; i < num; i++) {
    scanf("%d ", &data[i]);
  }

  bubble_sort(num, data);
#endif
  return 0;
}