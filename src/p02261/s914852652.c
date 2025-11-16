/*
  バブルソートおよび選択ソートのアルゴリズムを用いて、与えられたN枚のカードをそれらの数字を基準に昇順に整列するプログラム
  また、それぞれのソートが安定な出力をしたか表示する
*/
#include <stdio.h>

typedef struct{
  
  char c;
  int value;
  
}Card;

void swap(Card *, Card *);
int isStable(Card aryA[], Card aryB[], int n);

int main()
{
  Card card[36], output[36];
  int n, i, j, minj;

  scanf("%d", &n);
  for( i = 0; i<n; i++ )
    scanf(" %c%d", &card[i].c, &card[i].value);

  /*cardをoutputにコピー*/
  for( i = 0; i<n; i++ )
    output[i] = card[i];
  /*バブルソートを用いて昇順にソート*/
  for( i = 0; i<n; i++ )
    {
      for( j = n-1; j >= i+1; j-- )
	{
	  if( output[j-1].value > output[j].value )
	      swap(&output[j-1], &output[j]);
	}
    }

  /*バブルソートの結果を出力*/
  for( i = 0; i<n; i++ )
    {
      printf("%c%d", output[i].c, output[i].value);
      if( i != n-1 )
	printf(" ");
    }
  printf("\n");
  if( isStable(card, output, n) == 1 )
    printf("Stable\n");
  else
    printf("Not stable\n");


  /*cardをoutputにコピー*/
  for( i = 0; i<n; i++ )
    output[i] = card[i];
  /*選択ソートを用いて昇順にソート*/
  for( i = 0; i<n; i++ )
    {
      minj = i;

      for( j = i+1; j<n; j++ )
	{
	  if( output[minj].value > output[j].value )
	    minj = j;
	}
      if( minj != i )
	swap(&output[i], &output[minj]);
    }

  /*選択ソートの結果を出力*/
  for( i = 0; i<n; i++ )
    {
      printf("%c%d", output[i].c, output[i].value);
      if( i != n-1 )
	printf(" ");
    }
  printf("\n");
  if( isStable(card, output, n) == 1 )
    printf("Stable\n");
  else
    printf("Not stable\n");

  return 0;
}


/*引数として与えられたCard型構造体 a,b を交換する関数*/
void swap(Card *a, Card *b)
{
  Card tmp;

  tmp = *a;
  *a  = *b;
  *b  = tmp;
}

/*ソートの出力が安定であるか調べる関数 
 戻り値： 安定 １  不安定 ０*/
int isStable(Card in[], Card out[], int n)
{
  int i,j, a, b;

  for( i = 0; i<n-1; i++ )
    {
      for( j = i+1; j<n; j++ )
	{
	  for( a = 0; a<n-1; a++ )
	    {
	      for( b = a+1; b<n; b++ )
		{
		  if( in[i].value == in[j].value &&  in[i].c == out[b].c && in[j].c == out[a].c && in[i].value == out[a].value && in[j].value == out[b].value )
		    return 0;
		}
	    }
	}
    }

  return 1;
}

