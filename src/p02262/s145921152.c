#include<stdio.h>

int a[10001000],g[10000];
int top = 1, cnt = 0, n;

void add(){
  while(g[top] * 3 + 1 < n)
    {  
      top++;
      g[top] = g[top - 1] * 3 + 1;
    }
}
void sort(int a[], int id){
  int v, i, j;
  for(i = id + 1 ; i <= n ; i++)
    {
      v = a[i];
      j = i-id;
      while(j >= 1 && a[j] > v)
	{
	  a[j+id]=a[j];
	  j-=id;
	  cnt++;
        }
      a[j+id]=v;
    }
}
int main(){
  int i;
    
  scanf("%d",&n);
  g[1]=1;
  for(i = 1 ; i <= n ; i++)
    {
      scanf("%d",&a[i]);
    }
    
  add();
  for(i = top ; i >= 1 ; i--)
    {
      sort(a,g[i]);
    }
    
  printf("%d\n",top);
  for(i = top ; i >= 1 ; i--)
    {
      printf("%d ",g[i]);
    }
  printf("\n%d\n",cnt);
  for(i=1;i<=n;i++)
    {
      printf("%d\n",a[i]);
    }
  
  return 0;
}

