#include <stdio.h>

int cmp(char[],char[]);

int main() {
  int n,i,j,k,m;
  char a[101][2],b[101][2],tmp[2];
  scanf("%d",&n);
  for(i=0; i<n; i++) {
    scanf("%s",a[i]);
    for(k=0; k<2; k++) b[i][k]=a[i][k];
  }
  for(i=0; i<n; i++) {
    for(j=n-1; j>i; j--) {
      if(a[j][1]<a[j-1][1]) {
	for(k=0; k<2; k++) tmp[k]=a[j][k];
	for(k=0; k<2; k++) a[j][k]=a[j-1][k];
	for(k=0; k<2; k++) a[j-1][k]=tmp[k];
      }
    }
  }
  for(i=0; i<n; i++) {
    m=i;
    for(j=i+1; j<n; j++) {
      if(b[j][1]<b[m][1]) m=j;
    }
    if(b[m][1]<b[i][1]) {
      for(k=0; k<2; k++) tmp[k]=b[i][k];
      for(k=0; k<2; k++) b[i][k]=b[m][k];
      for(k=0; k<2; k++) b[m][k]=tmp[k];
    }
  }
  int ck=1;
  for(i=0; i<n; i++) {
    if(a[i][0]!=b[i][0]) ck=0;
  }    
  for(i=0; i<n; i++) {
    if(i) printf(" ");
    printf("%c%c",a[i][0],a[i][1]);
  }
  printf("\nStable\n");
  for(i=0; i<n; i++) {
    if(i) printf(" ");
    printf("%c%c",b[i][0],b[i][1]);
  }
  if(ck) printf("\nStable\n");
  else printf("\nNot stable\n");
  return 0;
}

