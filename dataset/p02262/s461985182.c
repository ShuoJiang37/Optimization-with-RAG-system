#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char buf[32];
int cnt = 0;

void insertionSort(int *a, int n, int g)
{
  int i, j, v;
  for (i=g; i < n; i++) {
    v = a[i];
    j = i - g;
    while (j >= 0 && a[j] > v) {
      a[j+g] = a[j];
      j -= g;
      cnt++;
    }
    a[j+g] = v;
  }
}


void shellSort(int *a, int n)
{
  int i, j, g, m=0;
  m = (int)(log(2*n+1)/log(3));
  int G[m];
  for (i=m; i>0; i--) {
    G[m-i]= (pow(3,i)-1)/2;
  }
  for (i=0; i<m; i++) {
    g = G[i];
    insertionSort(a, n, g);
  }

  buf[31]=0;
  buf[30]='\n';
  i=30;
  int d = m;
  if (d>0)  for (; d>0; buf[--i]='0'+d%10,d/=10);
  else  buf[--i] = '0';
  fputs(buf+i, stdout);

  buf[30]=' ';
  for (i=0; i<m-1; i++) {
    for (j=30; G[i]>0; buf[--j]='0'+G[i]%10,G[i]/=10);
    fputs(buf+j, stdout);
  }
  buf[30]='\n';
  for (j=30; G[i]>0; buf[--j]='0'+G[i]%10,G[i]/=10);
  fputs(buf+j, stdout);

  j=30;
  if (cnt>0)
    for (; cnt>0; buf[--j]='0'+cnt%10,cnt/=10);
  else  buf[--j] = '0';
  fputs(buf+j, stdout);
  
  for (i=0; i<n; i++) {
    j=30;
    if (a[i]>0)
      for (; a[i]>0; buf[--j]='0'+a[i]%10,a[i]/=10);
    else  buf[--j] = '0';
    fputs(buf+j, stdout);
  }
}

int main()
{
 int i, n;
 char *p;
 fgets(buf, 32, stdin);
 for (n=0, p=buf; *p!='\n'; p++)  n = n * 10 + *p - '0';
 int *a = (int *)malloc(sizeof(int)*n);

 for (i=0; i<n; i++) {
   fgets(buf, 32, stdin);
   for (a[i]=0, p=buf; *p!='\n'; p++)  a[i] = a[i] * 10 + *p - '0';
 }
 shellSort(a, n);
	 
 return 0;
}

