#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int n, *list, i, holder, j;
  int swaps = 0;
  scanf(" %d", &n);
  list = (int *) malloc(sizeof(int[n]));
  for (i = 0; i < n; i++)
    scanf(" %d", list + i);
  // bubble sort
  for (i = 0; i < n; i++)
    for (j = n - 1; j > i; j--)
      if (list[j] < list[j - 1])
	{
	  swaps++;
	  holder = list[j];
	  list[j] = list[j - 1];
	  list[j - 1] = holder;
	}
  // print list and swaps
  for (i = 0; i < n; i++)
    printf("%d%s", list[i], i != n - 1 ? " " : "\n");
  printf("%d\n", swaps);
  return 0;
}

