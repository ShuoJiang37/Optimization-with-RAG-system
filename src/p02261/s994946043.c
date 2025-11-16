#include<stdio.h>

//Card's struct
typedef struct{
  char c;
  int n;
}Card;


int main()
{
  int N;
  Card card1[36], card2[36], card3[36];
  Card copy;
  char c;
  int mini;
  int i, j, k;

  //Read N and Cards
  scanf("%d\n", &N);
  for(i=0; i<N; i++)
    {
      scanf("%c%d", &card1[i].c, &card1[i].n);
      //this operation is a step to read ' '.
      scanf("%c", &c);
    }

  //Copy to card_selectiotn and order
  for(i=0; i<N; i++)card2[i]=card1[i];

  //this sort is very stable.
  k=0;
  for(i=1; i<=9; i++)
    {
      for(j=0; j<N; j++)
	{
	  if(card1[j].n==i)
	    {
	      card3[k]=card1[j];
	      k++;
	    }
	}
    }

  //---------------------start----------------------------
  //Begin Bubble Sort
  for(i=0; i<N; i++)
    {
      for(j=N-1; j>=i+1; j--)
	{
	  if(card1[j].n<card1[j-1].n)
	    {
	      copy=card1[j];
	      card1[j]=card1[j-1];
	      card1[j-1]=copy;
	    }
	}
    }

  //print
  for(i=0; i<N; i++)
    {
      if(i!=N-1)printf("%c%d ", card1[i].c, card1[i].n);
      else printf("%c%d\n", card1[i].c, card1[i].n);
    }

  //Is this Stable?
  k=0;
  for(i=0; i<N; i++)
    {
      if(card1[i].c!=card3[i].c)
	{
	  printf("Not stable\n");
	  k++;
	  break;
	}
    }
  if(k==0)printf("Stable\n");

  //------------------------------------------
  //Selection Sort
  for(i=0; i<N; i++)
    {
      mini=i;
      for(j=i; j<N; j++)
	{
	  if(card2[j].n<card2[mini].n)mini=j;
	}
      copy=card2[i];
      card2[i]=card2[mini];
      card2[mini]=copy;
    }


  //print
  for(i=0; i<N; i++)
    {
      if(i!=N-1)printf("%c%d ", card2[i].c, card2[i].n);
      else printf("%c%d\n", card2[i].c, card2[i].n);
    }

  //Is this Stable?
  k=0;
  for(i=0; i<N; i++)
    {
      if(card2[i].c!=card3[i].c)
	{
	  printf("Not stable\n");
	  k++;
	  break;
	}
    }
  if(k==0)printf("Stable\n");
  return 0;
}