#include <stdio.h>
#include <stdlib.h>

void selectSortPrint(int *, int);

int main(void)
{
  int n, *list, i;
  scanf(" %d", &n);
  list = (int *) malloc(sizeof(int[n]));
  for (i = 0; i < n; i++)
    scanf(" %d", list + i);
  selectSortPrint(list, n);
  return 0;
}

void selectSortPrint(int *list, int len)
{
  int i, j, mini, holder;
  int swaps = 0;
  for (i = 0; i < len; i++)
    {
      mini = i; // current smallest element in list[i:len]
      for (j = i; j < len; j++)
	if (list[j] < list[mini])
	  mini = j;
      if (mini != i)
	{
	  holder = list[i];
	  list[i] = list[mini];
	  list[mini] = holder;
	  swaps++;
	}
      printf("%d%s", list[i], i != (len - 1) ? " " : "\n");
    }
  printf("%d\n", swaps);
}
  
