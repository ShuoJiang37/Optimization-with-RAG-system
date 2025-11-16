#include<stdio.h>

int bubblesort(int *a, int length)
{
  int i, j, tmp, cnt=0;

for(i=0; i<length; i++)
  {
    for(j=length-1; j>i; j--)
      {
	if(a[j] < a[j-1])
	  {
	    tmp = a[j];
	    a[j] = a[j-1];
	    a[j-1]  = tmp;
	    cnt++;
	  }
      }
  }
 return cnt;
}

main()
{
  int i, n, Array[100], cnt=0;

  scanf("%d", &n);

  for(i=0; i<n; i++)
    {
      scanf("%d", &Array[i]);
    }

  cnt = bubblesort(Array, n);

  printf("%d", Array[0]);

  for(i=1; i<n; i++)
    {
      printf(" %d", Array[i]);
    }

  printf("\n%d\n", cnt);

  return 0;
}