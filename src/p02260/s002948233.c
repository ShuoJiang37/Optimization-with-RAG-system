#include<stdio.h>

int selectionsort(int *a, int length)
{

  int i, j, tmp, cnt=0, mini;

  for(i=0; i<length; i++)
    {
      mini = i;
      
      for(j=i; j<length; j++)
	{
	  if(a[j]<a[mini])
	    {
	      mini = j;
	    }
	}

      if(i != mini)
	{
	  tmp = a[i];
	  a[i] = a[mini];
	  a[mini] = tmp;
	  cnt++;
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

  cnt = selectionsort(Array, n);

  printf("%d", Array[0]);

  for(i=1; i<n; i++)
    {
      printf(" %d", Array[i]);
    }

  printf("\n%d\n", cnt);

return 0;
}