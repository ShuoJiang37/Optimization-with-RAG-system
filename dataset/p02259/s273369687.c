#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define UTIL_ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

#define UTIL_SWAP(x, y)                                                                                                                    \
  do {                                                                                                                                     \
    typeof(x) _a = x;                                                                                                                      \
    x = y;                                                                                                                                 \
    y = _a;                                                                                                                                \
  } while (0)

#define UTIL_PRINT_ARRAY(arr, size)                                                                                                        \
  do {                                                                                                                                     \
    uint16_t i;                                                                                                                            \
    for (i = 0; i < size; i++) {                                                                                                           \
      if (i != 0) printf(" ");                                                                                                             \
      printf("%d", arr[i]);                                                                                                                \
    }                                                                                                                                      \
    printf("\n");                                                                                                                          \
  } while (0)

#define BUF_SIZE 100

uint32_t bubble(int32_t buf[], size_t size)
{
  uint32_t num = 0;
  uint16_t i = size;
  while (i--) {
    uint16_t j;
    for (j = 0; j < i; j++) {
      if (buf[j] > buf[j + 1]) {
        UTIL_SWAP(buf[j], buf[j + 1]);
        num++;
      }
    }
  }

  return num;
}

#if !defined(TEST)
int32_t main(void)
{
  int32_t num;
  scanf("%d", &num);
  int32_t buf[BUF_SIZE];
  uint16_t i;
  for (i = 0; i < num; i++) {
    scanf("%d", &buf[i]);
  }

  uint32_t cnt = bubble(buf, num);

  UTIL_PRINT_ARRAY(buf, num);
  printf("%d\n", cnt);

  return 0;
}
#endif