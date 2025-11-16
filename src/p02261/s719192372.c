#include <stdio.h>

void BubbleSort(int);
void SelectionSort(int);

typedef struct{
  char mark;
  int number;
} card;

card Bubble[100];
card Select[100];
card in[100];

int main()
{
  int i,j,N,flag = 0,a,b;
  char n;

  scanf("%d ",&N);

  for(i = 0;i < N;i++){
    scanf("%c",&in[i].mark);
    scanf("%d",&in[i].number);
    scanf("%c",&n);
  }

  for(i = 0;i < N;i++){
    Bubble[i].mark = in[i].mark;
    Bubble[i].number = in[i].number;
    }

  for(i = 0;i < N;i++){
    Select[i].mark = in[i].mark;
    Select[i].number = in[i].number;
    }

  /* バブルソート */
  BubbleSort(N);

  /* 選択ソート */
  SelectionSort(N);


  /* Stable */
  /* 選択ソートの安定性 */
  for(i = 0;i < N;i++){
    for(j = i + 1;j < N - 1;j++){
      for(a = 0;a < N;a++){
	for(b = a + 1;b < N - 1;b++){
	  if((in[i].number == in[j].number) &&
	     (in[i].number == Select[b].number) &&
	     (in[j].number == Select[a].number)) flag = 1; // false
	}
      }
    }
  }
  // flag == 0 : true	     

  for(i = 0;i < N;i++){
    printf("%c%d",Bubble[i].mark,Bubble[i].number);
    if(i != N-1) printf(" ");
  }
  printf("\n");

  printf("Stable\n");

  for(i = 0;i < N;i++){
    printf("%c%d",Select[i].mark,Select[i].number);
    if(i != N-1) printf(" ");
  }
  printf("\n");

  if(flag == 1) printf("Not stable\n");
  else printf("Stable\n");

  return 0;
}

void BubbleSort(int N)
{
  int i,j;
  int num;
  char pic;
  card sub;

  for(i = 0;i < N;i++){
    for(j = N-1;j >= 0;j--){
      if(Bubble[j].number < Bubble[j-1].number){
       	pic = Bubble[j].mark;
	num = Bubble[j].number;
	Bubble[j].mark = Bubble[j-1].mark;
	Bubble[j].number = Bubble[j-1].number;
        Bubble[j-1].mark = pic;
	Bubble[j-1].number = num;
      }
    }
  }
}

void SelectionSort(int N)
{
  int i,j,minj;
  int num;
  char pic;

   for(i = 0;i < N;i++){
    minj = i;
    for(j = i;j < N;j++){
      if(Select[j].number < Select[minj].number){
	minj = j;
      }
    }
    pic = Select[i].mark;
    num = Select[i].number;
    Select[i].mark = Select[minj].mark;
    Select[i].number = Select[minj].number;
    Select[minj].mark = pic;
    Select[minj].number = num;
   }
}


 