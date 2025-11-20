#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 36

typedef struct {
    int value[N];
    char mark[N];
} data;

int n;


data bblesort(data);
data selectsort(data);
void inputdata(data);
int check(data,data);


int main()
{
  int i,che;
  char ch[3];

  /*nに要素数を入力*/
  scanf("%d",&n);

  /*構造体作成,C値入力*/
  data C,b,s;
  for(i=0;i<n;i++){
    scanf("%s",ch);
    C.mark[i]= ch[0];   
    C.value[i]= atoi(ch+1);
  }

  /*bblesortで変換*/
  b=bblesort(C);
  s=selectsort(C);

  inputdata(b);
  printf("Stable\n");
  
  inputdata(s);
  che=check(s,b);

  if(che==1)printf("Not stable\n");
  else printf("Stable\n");


  return 0;
}

data bblesort(data b)
{
  int i,cpv,j;
  char cpm;

  for(i=0;i<n;i++)
    {
      for(j=n-1;j>i;j--)
	{
	  if(b.value[j]<b.value[j-1]){
	    cpv=b.value[j];
	    cpm=b.mark[j];
	    b.value[j]=b.value[j-1];
	    b.mark[j]=b.mark[j-1];
	    b.value[j-1]=cpv;
	    b.mark[j-1]=cpm;
	  }
	}
    }
  
  return b;
}

data selectsort(data s)
{
  int i,j,minj,cpv;
  char cpm;

  for(i=0;i<n;i++)
    {
      minj=i;
      for(j=i;j<n;j++)
	{
	  if(s.value[j]<s.value[minj])
	    {
	      minj=j;
	    }
	}
      cpv=s.value[i];
      cpm=s.mark[i];
      s.value[i]=s.value[minj];
      s.mark[i]=s.mark[minj];
      s.value[minj]=cpv;
      s.mark[minj]=cpm;  
    }
  return s;
}


void inputdata(data b)
{
  int i;
  
  for(i=0;i<n;i++){
    if(i==n-1)
      printf("%c%d\n",b.mark[i],b.value[i]);
    else
      printf("%c%d ",b.mark[i],b.value[i]);
  }
}

int check(data b,data c)
{
  int i;
  for(i=0;i<n;i++)
    {
	if(b.value[i]==c.value[i]){
	  if(strcmp(&b.mark[i],&c.mark[i])!=0){
	    return 1;
	  }
	  
	}
    }
  return 0;
}


  

