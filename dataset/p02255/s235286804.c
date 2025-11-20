#include<stdio.h>
int main()
{
  int a[1000], n, i, j, k, v;
  scanf("%d", &n);
  for(k = 0; k < n; k++)
    {
      scanf("%d",&a[k]);
    }
  for(k = 0; k < n; k++)
    {
      printf("%d",a[k]);
      if(k+1 < n)
	{
	  printf(" ");
	}
    }
  printf("\n");
  for(i = 1; i < n; i++)
    {
      v = a[i];
      j = i - 1;
      while (j >= 0 && a[j] > v)
	{
	  a[j+1] = a[j];
	  j--;
	  a[j+1] = v;
	}
      for(k = 0; k < n; k++)
	{
	  printf("%d",a[k]);
	  if(k+1 < n)
	    {
	      printf(" ");
	    }
	}
      printf("\n");
    }
  return 0;
}

