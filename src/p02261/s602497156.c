#include<stdio.h>
typedef struct{
  char c;
  int n;
}Card;

int main(){
  int i, j, k, n, minj;
  Card c1[36], c2[36], c3[36];
  Card v;
  char c;
    scanf("%d\n", &n);
  for(i=0; i<n; i++){
    scanf("%c%d", &c1[i].c, &c1[i].n);
    scanf("%c", &c);
  }
  for(i=0; i<n; i++)
  c2[i]=c1[i];
 
 k=0;
  for(i=1; i<=9; i++){
    for(j=0; j<n; j++){
      if(c1[j].n==i){
          c3[k]=c1[j];
          k++;
      }
    }
  }
  for ( i = 0; i < n; i++){
	for ( j = 1; j < n; j++){
  	if(c1[j].n < c1[j - 1].n){
    	v = c1[j];
    	c1[j] = c1[j - 1];
    	c1[j - 1] = v;
  	}
  	}
  }
  for ( i = 0; i < n; i++){
	if (i > 0)
  	printf(" ");
	printf("%c%d", c1[i].c, c1[i].n);
  }
    printf("\n");
  
  k=0;
  for(i=0; i<n; i++){
      if(c1[i].c != c3[i].c){
        printf("Not stable\n");
        k++;
        break;
      }
  }
  if(k==0)printf("Stable\n");
  
    for( i = 0; i < n ; i++){
    minj = i;
      for( j = i; j < n; j++){
        if (c2[j].n < c2[minj].n) minj = j;
      }
      v = c2[i]; c2[i] = c2[minj]; c2[minj] = v;
    }
      for ( i = 0; i < n; i++){
      if (i > 0)
      printf(" ");
      printf("%c%d", c2[i].c, c2[i].n);
    }
      printf("\n");
 
    k=0;
  for(i=0; i<n; i++){
      if(c2[i].c != c3[i].c){
        printf("Not stable\n");
        k++;
        break;
      }
  }
  if(k==0)printf("Stable\n");

  
  return 0;
}