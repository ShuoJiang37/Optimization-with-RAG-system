#include<stdio.h>
#include<string.h>

struct card
{
  char suit;
  int num;
  int order;
};

int main()
{
  int n, i, j, min, flg;
  char str[3];
  struct card m, a[36], b[36];

  scanf("%d", &n);
  for(i=0; i<n; i++)
    {
      scanf("%s", str);
      a[i].suit = str[0];
      a[i].num = atoi(&str[1]);
      a[i].order = i;

      b[i].suit = str[0];
      b[i].num = atoi(&str[1]);
      b[i].order = i;
    }

  //bubble
  for(i=0; i<n; i++)
    {
      for(j=n-1; j>i; j--)
	{
	  if(a[j].num< a[j-1].num)
	    {
	      m = a[j];
	      a[j] = a[j-1];
	      a[j-1] = m;
	    }
	}
    }
  flg=0;
  
  for(i=0; i<n; i++)
    {
      printf("%c%d", a[i].suit, a[i].num);
      if(i+1<n) printf(" ");
      if(i < n-1 && a[i].num == a[i+1].num)
	{
	  if(a[i+1].order < a[i].order) flg=1;
	}
    }
  printf("\n");
  if(flg == 0) printf("Stable\n");
  else printf("Not stable\n");

  
  //selection
  for(i=0; i<n; i++)
    {
      min=i;
      for(j=i; j<n; j++)
	{
	  if(b[j].num<b[min].num)
	    min = j;
	}
      if(min != i)
	{
	  m = b[i];
	  b[i] = b[min];
	  b[min] = m;
	}
    }
  flg=0;
  
  for(i=0; i<n; i++)
    {
      printf("%c%d", b[i].suit, b[i].num);
      if(i+1<n) printf(" ");
      if(i < n-1 && b[i].num == b[i+1].num)
	{
	  if(b[i+1].order < b[i].order) flg=1;
	}
    }
  printf("\n");
  if(flg == 0) printf("Stable\n");
  else printf("Not stable\n");

  return 0;
}