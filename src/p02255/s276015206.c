#include <stdio.h>
#include <stdlib.h>

void sort(int *, int);
void print(int *, int);

int main(void)
{
  int len, *toSort, i;
  scanf(" %d", &len);
  toSort = (int *) malloc(sizeof(int[len]));
  for (i = 0; i < len; i++)
    scanf(" %d", toSort + i);
  sort(toSort, len);
  return 0;
}

void sort(int *toSort, int len)
{
  int i, j, key;
  print(toSort, len);
  for (i = 1; i < len; i++)
    {
      key = toSort[i];
      j = i - 1;
      while (j >= 0 && toSort[j] > key)
	{
	  toSort[j+1] = toSort[j];
	  j--;
	}
      toSort[j+1] = key;
      print(toSort, len);
    }
}

void print(int *toSort, int len)
{
  int i;
  for (i = 0; i < len; i++)
    printf("%d%s", toSort[i], i == len - 1 ? "\n" : " ");
}

