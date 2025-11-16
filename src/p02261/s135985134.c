#include <stdio.h>
#include <string.h>

struct Card
{
  char suit;
  int value;
};

main()
{
  struct Card C1[36], C2[36];
  int length, i, j, tmpint, min,flag = 0;
  char tmpchar;

  scanf("%d\n", &length);

  for(i = 0; i < length; i++)
    {
      if(i == 0)
	{
	  scanf("%c %d", &C1[i].suit, &C1[i].value);
	}
      else
	{
	  scanf(" %c %d", &C1[i].suit, &C1[i].value);
	}
    }

  for(i = 0; i < length; i++)
    {
      C2[i] = C1[i];
    }

  /*bubble sort start*/
  for(i = 0; i < length; i++)
    {
      for(j = length - 1; j >= i + 1; j--)
	{
	  if(C1[j].value < C1[j - 1].value)
	    {
	      tmpint = C1[j].value;
	      C1[j].value = C1[j - 1].value;
	      C1[j - 1].value = tmpint;
	      tmpchar = C1[j].suit;
	      C1[j].suit = C1[j - 1].suit;
	      C1[j - 1].suit = tmpchar;
	    }
	}
    }
  for(i = 0; i < length; i++)
    {
      if(i == length - 1)
	{
	  printf("%c%d\n", C1[i].suit, C1[i].value);
	}
      else
	{
	  printf("%c%d ", C1[i].suit, C1[i].value);
	}
    }
  printf("Stable\n");
  /*bubble sort finish*/

  /*select sort start*/
  for(i = 0; i < length; i++)
    {
      min = i;
      for(j = i + 1; j < length; j++)
	{
	  if(C2[j].value < C2[min].value)
	    {
	      min = j;
	      flag = 1;
	    }
	}
      if(flag == 1)
	{
	  tmpint = C2[i].value;
	  C2[i].value = C2[min].value;
	  C2[min].value = tmpint;
	  tmpchar = C2[i].suit;
	  C2[i].suit = C2[min].suit;
	  C2[min].suit = tmpchar;
	}
      flag = 0;
    }
  for(i = 0; i < length; i++)
    {
      if(i == length - 1)
	{
	  printf("%c%d\n", C2[i].suit, C2[i].value);
	}
      else
	{
	  printf("%c%d ", C2[i].suit, C2[i].value);
	}
    }
  for(i = 0; i < length; i++)
    {
      if(C1[i].suit == C2[i].suit)
	{
	  continue;
	}
      else
	{
	  flag = 1;
	  break;
	}
    }
  if(flag == 0)
    {
      printf("Stable\n");
    }
  else
    {
      printf("Not stable\n");
    }
  /*select sort finish*/
  return 0;
}