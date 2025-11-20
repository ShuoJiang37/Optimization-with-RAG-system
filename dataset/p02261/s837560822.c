#include<stdio.h>
#include<string.h>
#define N 36
 
typedef struct{
  char mark;
  int value;
}MV;
 
int isStable(MV, MV);
int n;
 
int main()
{
  int i, j, a, b, d=0, min=0;
  MV c[N], c1[N], c2[N], temp;
 
  scanf("%d",&n);
  for(i=0;i<n;i++)
{
    scanf(" %c%d", &c[i].mark, &c[i].value);
    c1[i] = c[i];
    c2[i] = c[i];
  }
 
  for(i=0;i<n-1;i++)
{
    for(j=n-1;j>i;j--)
{
      if(c[j].value < c[j-1].value)
{
    temp = c[j];
    c[j] = c[j-1];
    c[j-1] = temp;
      }
    }
  }
 
  for(i=0;i<n-1;i++) printf("%c%d ", c[i].mark, c[i].value);
  printf("%c%d\n", c[n-1].mark, c[n-1].value);
 
  for(i=0;i<n-1;i++)
{
    for(j=i+1;j<n-1;j++)
{
      for(a=0;a<n-1;a++)
{
    for(b=a+1;b<n-1;b++)
{
      if(c2[i].value == c2[j].value && c2[i].mark == c[b].mark && c2[i].value == c[b].value && c2[j].mark == c[a].mark && c2[j].value == c[a].value) d = 1;
    }
      }
    }
  }
  if(d == 1) printf("Not stable\n");
  else printf("Stable\n");
 
  for(i=0;i<n;i++)

{
    min = i;
    for(j=i;j<n;j++)
{
      if(c1[j].value < c1[min].value) min = j;
    }
    temp = c1[i];
    c1[i] = c1[min];
    c1[min] = temp;
  }
 
  for(i=0;i<n-1;i++) printf("%c%d ", c1[i].mark, c1[i].value);
  printf("%c%d\n", c1[n-1].mark, c1[n-1].value);
   
  for(i=0;i<n-1;i++)
{
    for(j=i+1;j<n-1;j++)
{
      for(a=0;a<n-1;a++)
{
    for(b=a+1;b<n-1;b++)
{
      if(c2[i].value == c2[j].value && c2[i].mark == c1[b].mark && c2[i].value == c1[b].value && c2[j].mark == c1[a].mark && c2[j].value == c1[a].value) d = 1;
    }
      }
    }
  }
  if(d == 1) printf("Not stable\n");
  else printf("Stable\n");
 
  return 0;
}