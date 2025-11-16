#include<stdio.h>

typedef struct
{
  char card;
  int num;
  int p;
}card;

int main()
{
  int n;
  card t[36];
  card d[36];
  card temp;
  int i = 0;
  char card;
  int num;
  int p;
  int f = 1;
  
  scanf("%d", &n);
  
  for(int j = 0; j < n*2; j++)
    {
      scanf("%c %d", &card, &num);
      t[j/2].card = card;
      t[j/2].num = num;
      t[j/2].p = j;
      d[j/2].card = t[j/2].card;
      d[j/2].num = t[j/2].num;
      d[j/2].p = j;
    }
  while(1)
    {
      if(i == n-1)
	{
	  break;
	}
      if(d[i].num > d[i+1].num)
	{
	  temp.card = d[i].card;
	  temp.num = d[i].num;
	  d[i].card = d[i+1].card;
	  d[i].num = d[i+1].num;
	  d[i+1].card = temp.card;
	  d[i+1].num= temp.num;
	  i = 0;
	  continue;
	}
      i++;
    }
  
  for(int k = 0; k < n-1; k++)
    {
      p = k;
      for(int j = k; j < n; j++)
	{
	  if(t[j].num < t[p].num)
	    {
	      p = j;
	    }
	}
      if(p != k)
	{
	  temp = t[k];
	  t[k] = t[p];
	  t[p] = temp;
	}
    }
  for(int j = 0; j < n; j++)
    {
      printf("%c%d%c", d[j].card, d[j].num, " \n"[j == n-1]);
      if(j>0 && d[j].num == d[j-1].num && d[j].p < d[j-1].p)
	{
	  f = 0;
	}
    }
  printf((f ? "Stable\n" : "Not stable\n"));
  for(int j = 0; j < n; ++j)
    {
      printf("%c%d%c", t[j].card, t[j].num, " \n"[j==n-1]);
      if(j>0 && t[j].num == t[j-1].num && t[j].p < t[j-1].p)
	{
	  f = 0;
	}
    }
  printf((f ? "Stable\n" : "Not stable\n"));
}

