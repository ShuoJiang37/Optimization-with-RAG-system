#include <stdio.h>
#define N 10000


int main()
{
  int n,i,r,k,p;
  char a[N][2],b[N][2],tmp[2];
  scanf("%d",&n);

  for(i=0; i<n; i++) {
    scanf("%s",a[i]);
    for(k=0; k<2; k++) b[i][k]=a[i][k];
  }


  for(i=0; i<n; i++) {
    for(r=n-1; r>i; r--) {
      if(a[r][1]<a[r-1][1]) {
	     for(k=0; k<2; k++) {tmp[k]=a[r][k];}

	     for(k=0; k<2; k++) {a[r][k]=a[r-1][k];}

	     for(k=0; k<2; k++) {a[r-1][k]=tmp[k];}
      }
    }
  }


  for(i=0; i<n; i++) {
    p=i;
    for(r=i+1; r<n; r++) {
      if(b[r][1]<b[p][1]) {
         p=r;
      }
    }
    if(b[p][1]<b[i][1]) {
      for(k=0; k<2; k++) tmp[k]=b[i][k];

      for(k=0; k<2; k++) b[i][k]=b[p][k];

      for(k=0; k<2; k++) b[p][k]=tmp[k];
    }
  }


  int z=1;
  for(i=0; i<n; i++) {
    if(a[i][0]!=b[i][0])
    {
      z=0;
    }
  }

  for(i=0; i<n; i++) {
    if(i) printf(" ");
    printf("%c%c",a[i][0],a[i][1]);
  }


  printf("\nStable\n");
  for(i=0; i<n; i++)
   {
    if(i) printf(" ");
    printf("%c%c",b[i][0],b[i][1]);
   }

  if(z!=0) printf("\nStable\n");
  else printf("\nNot stable\n");
  return 0;
}

