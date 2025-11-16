#include <stdio.h>

int main() {
  int n;
  int i,j,e;
  int a[101],b[101];
  int t,minj,flag;
  char c[101],kara,m,d[101],f[4];
  char str[3];
  int sta = 0;

  scanf("%d", &n);

  for(i=0; i<n; i++) {

    scanf("%s",str);
    c[i] = str[0];
    a[i]  = str[1] - '0';
    //    printf("%c %d\n",c[i],a[i]);
    b[i] = a[i];
    d[i] = c[i];

  }



  //Bubble Sort

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




  // Selsection Sort

  

  for(i = 0; i<=n-1; i++) {
    minj = i;
    flag = 0;
  
    for(j = i; j<=n-1;j++) {
      if(b[j] < b[minj]) {
	//	printf("%d < %d\n",b[j],b[minj]);
	minj = j;
	//printf("minj = %d\n",b[minj]);
	flag = 1;
      }
    }

    

    if(flag == 1) {


      t = b[i];
      b[i] = b[minj];
      b[minj] = t;

      m = d[i];
      d[i] = d[minj];
      d[minj] = m;
  
    }
  }

   
  for(i=0;i<n;i++) {
     printf("%c%d",d[i],b[i]);
    if(i != n-1) {
      printf(" ");
    }

  }


printf("\n");
flag = 0;
for(j=0;j<n;j++){

  //printf("c[%d](%c) = d[%d](%c)\n",j,c[j],j,d[j]);

  if(c[j] != d[j]) {
    flag = 1;
   
  }
 } 

if(flag == 1) printf("Not stable\n");
 else printf("Stable\n");

 return 0;

}