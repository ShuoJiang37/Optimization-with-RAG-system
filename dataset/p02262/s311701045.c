#include <stdio.h>
#include <stdlib.h>

int cnt = 0;
size_t gaps[100] = { 1 };
static const size_t len_gaps = sizeof(gaps) / sizeof(*gaps);

void insertion_sort(int* array, size_t size, size_t gap)
{
  for(size_t i = gap; i < size; i++) {
    int max = array[i];
    int k = i - gap;
    while(0 <= k && max < array[k]) {
      array[k + gap] = array[k];
      k = k - gap;
      cnt++;
    }
    array[k + gap] = max;
  }
}

size_t power(int x, int n)
{
  int res = 1;
  for(int i = 0; i < n; i++) {
    res = res * x;
  }
  return res;
}

void shell_sort(int* array, size_t size)
{
  size_t gap_index;
  for(gap_index = 1; gap_index < len_gaps; gap_index++) {
    gaps[gap_index] = (power(3, gap_index+1) - 1) / 2;
    if(size / 2 < gaps[gap_index]) {
      break;
    }
  }
  gap_index--;
  printf("%lu\n", gap_index+1);
  for(int i = (int)gap_index; 0 <= i; i--) {
    printf("%lu", gaps[i]);
    if(i == 0) {
      putchar('\n');
    } else {
      putchar(' ');
    }
    insertion_sort(array, size, gaps[i]);
  }
}

int main()
{
  int size;
  scanf("%d", &size);
  int* array = malloc(sizeof(int) * size);
  if(!array) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }
  for(int i = 0; i < size; i++) {
    scanf("%d", &array[i]);
  }
  shell_sort(array, size);
  printf("%d\n", cnt);
  for(int i = 0; i < size; i++) {
    printf("%d\n", array[i]);
  }

  free(array);
  return 0;
}

