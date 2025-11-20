#include <stdio.h>
int n;
void bubble(char c[100],char value[100])
{
  int i,j;
  char tmp;
  for(i=0;i<n;i++)
  {
    for(j=n-1;j>=i+1;j--)
    {
      if(value[j]<value[j-1])
      {
        tmp = c[j];
        c[j]=c[j-1];
        c[j-1]=tmp;
        tmp = value[j];
        value[j]=value[j-1];
        value[j-1]=tmp;
      }
    }
  }
}
void selection(char c[100],char value[100])
{
  int i,j,minj,tmp;
  for(i=0;i<n;i++)
  {
    minj=i;
    for(j=i;j<n;j++)
    {
      if(value[j]<value[minj])
      {
        minj=j;
      }
    }
    tmp=c[i];
    c[i]=c[minj];
    c[minj]=tmp;
    tmp = value[i];
    value[i]=value[minj];
    value[minj]=tmp;
  }
}
void print(char c[100],char value[100])
{
  int i;
  for(i=0;i<n;i++)
  {
    if(i>0)printf(" ");
    printf("%c%c",c[i],value[i]);
  }
  printf("\n");
}
int stable(char c1[100],char c2[100])
{
  int i;
  for(i=0;i<n;i++)
  {
    if(c1[i]!=c2[i])return -1;
  }
  return 1;
}
int main()
{
  char c1[100],c2[100],value1[100],value2[100],i;
  char ch[3];

  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%s",ch);
    c1[i]=ch[0];
    value1[i]=ch[1];
  }
  for(i=0;i<n;i++)
  {
    c2[i]=c1[i];
    value2[i]=value1[i];
  }
  bubble(c1,value1);
  selection(c2,value2);

  print(c1,value1);
  printf("Stable\n");
  print(c2,value2);
  if(stable(c1,c2)==1)printf("Stable\n");
  else printf("Not stable\n");

  return 0;
}

