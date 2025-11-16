#include <stdio.h>

int main() {
  int n,i,j,e,t,mi,fl,sta=0;
  int a[50],b[50];
  char c[101],kara,m,d[101],f[4],str[3];
  
  scanf("%d", &n);
  
  for(i=0; i<n; i++) {
    
    scanf("%s",str);
    c[i] = str[0];
    a[i]  = str[1] - '0';
    b[i] = a[i];
    d[i] = c[i];
  }
  
  for(i = 0; i<=n-1;i++) {
    for(j = 0; j<=n-1;j++) {
      if(a[j] < a[j-1]) {
	t = a[j];
	a[j] = a[j-1];
	a[j-1] = t;
	m = c[j];
	c[j] = c[j-1];
	c[j-1] = m;
      }
    }
  }
  
  for(i = 0;i<n;i++) {  
    printf("%c%d",c[i],a[i]);
    if(i != n-1) printf(" ");
  }
  
  printf("\nStable\n");
  
  for(i = 0; i<=n-1; i++) {
    mi = i;
    fl = 0;
    for(j = i; j<=n-1;j++) {
      if(b[j] < b[mi]) {
	mi = j;
	fl = 1;
      }
    }
    if(fl == 1) { 
      t = b[i];
      b[i] = b[mi];
      b[mi] = t;
      m = d[i];
      d[i] = d[mi];
      d[mi] = m;
    }
  }
  for(i=0;i<n;i++) {
    printf("%c%d",d[i],b[i]);
    if(i != n-1) {
      printf(" ");
    }   
  }
  printf("\n");
  fl = 0;
  for(j=0;j<n;j++){
    if(c[j] != d[j]) {
      fl = 1;
    }
  } 
  if(fl == 1) printf("Not stable\n");
  else printf("Stable\n");
  
  return 0;
  
}

