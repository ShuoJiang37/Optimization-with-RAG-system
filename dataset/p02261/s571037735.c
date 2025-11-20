#include<stdio.h>
#include<string.h>
typedef struct{
  char sign;
  int num;
}Card;


void Bubble(Card k[],int n)
{
  int i,j,flag=0;
 
  while (flag < n-1)
    {
      int last=n-1;
      for(j=n-1; j>flag; j--)
	if(k[j-1].num>k[j].num){//構造体から抜き出した変数
	  Card tmp;//構造体Card内の変数作成
	  tmp=k[j-1];
	  k[j-1]=k[j];
	  k[j]=tmp;
	  
	  last = j;
	}
      flag=last;
    }
  for(i=0; i<n; i++){
    if(i==n-1)
      printf("%c%d",k[i].sign,k[i].num);
    else
      printf("%c%d ",k[i].sign,k[i].num);
  }
}

void Selection(Card k[], int n)
{
  int i,j;
  for(i=0; i<n-1; i++){
       int min=i;
    for(j=i; j<n; j++)
      if(k[j].num<k[min].num)
	min=j;
    Card tmp;
    tmp=k[i];
    k[i]=k[min];
    k[min]=tmp;
  }
  for(i=0; i<n; i++){
    if(i==n-1)
      printf("%c%d",k[i].sign,k[i].num);
    else
      printf("%c%d ",k[i].sign,k[i].num);
  }
}

void read(Card k[],Card k3[], int n)
{
  int i;
  for(i=0; i<n; i++)
    k3[i]=k[i];
}
void judge(Card k[], Card k3[], int n)
{
  int i,a=0;
  for(i=0; i<n; i++)
    if(k[i].num!=k3[i].num||k[i].sign!=k3[i].sign)
      a++;
  if(a==0)
    printf("Stable");
  else
    printf("Not stable");
 
}  
int main()
{
  int i,n;
  scanf("%d",&n);
  Card k[n];
  Card k2[n];//初期の値を仮代入
  Card k3[n];//Bubbleソートを入れる
  for(i=0; i<n; i++){
    scanf("\t%c%d",&k[i].sign,&k[i].num);//構造体の内部の変数に読み込み
    k2[i]=k[i];
  }
  
  Bubble(k,n);
  read(k,k3,n);
  putchar('\n');
  puts("Stable");//バブルソートは安定
  
  for(i=0; i<n; i++)
    k[i]=k2[i];

  Selection(k,n);
  putchar('\n');
  judge(k,k3,n);
  putchar('\n');
    return 0;
}


