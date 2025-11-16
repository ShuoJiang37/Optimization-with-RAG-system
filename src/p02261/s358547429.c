#include <stdio.h>

int main(void)

{
 char a[100][100];
 char b[100][100];

 int i, j, n, s, minj;
 int f;
 int k = 0;

 scanf("%d", &n);

 for(i = 0; i < n; i++)
{
  scanf("%s", &a[i]);
  b[i][0] = a[i][0];
  b[i][1] = a[i][1];  
}

  for(i = 0; i < n; i++)
{
    for(j = n-1; j >= i+1; j--)
{

  if(a[j][1] < a[j-1][1])
{
 s = a[j][1];
   a[j][1] = a[j-1][1];
   a[j-1][1] = s;
   f = a[j][0];
   a[j][0] = a[j-1][0];
   a[j-1][0] = f;

}
}

 }


  for(i = 0; i < n; i++)
{
  minj = i;
  for(j = i; j < n; j++)
{
   if(b[j][1] < b[minj][1])
{
     minj = j;
}

}
  s = b[minj][1];
  b[minj][1] = b[i][1];
  b[i][1] = s;
  f = b[minj][0];
  b[minj][0] = b[i][0];
  b[i][0] = f;

}

 for(i = 0; i < n; i++)
{
  printf("%c", a[i][0]);
 if(i < n-1)
  printf("%c ", a[i][1]);
 else
  printf("%c\n", a[i][1]);
}

 printf("Stable\n");

 for(i = 0; i < n; i++)
{
  printf("%c", b[i][0]);
 if(i < n-1)
  printf("%c ", b[i][1]);
 else
  printf("%c\n", b[i][1]);
}

 for(i = 0; i < n; i++)
{
 if(b[i][0] == a[i][0])
{
  k++;
}

}

 if(k == n)
   printf("Stable\n");
 else
  printf("Not stable\n");


 return 0;

}

  
