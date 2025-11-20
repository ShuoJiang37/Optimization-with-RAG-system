#include<stdio.h>

typedef struct {
  int a;
  char aa;
} po;


void bsort(po*,int);
void ssort(po*, int);
int sta(po*,po*,int);

int main() {
  int i,n;
  po kk[36],kkk[36];

  scanf("%d",&n);

    for(i=0;i<n;i++) {
      scanf(" %c%d",&kk[i].aa,&kk[i].a);
    }
  
    
      for(i=0;i<n;i++) {
	kkk[i].a=kk[i].a;
     	kkk[i].aa=kk[i].aa;
      }

      bsort(kk,n);
      ssort(kkk,n);

      for(i=0;i<n;i++) {
	printf("%c%d",kk[i].aa,kk[i].a);
	if(i!=n-1) printf(" ");
      }
      printf("\nStable\n");

      for(i=0;i<n;i++) {
	printf("%c%d",kkk[i].aa,kkk[i].a);
	if(i!=n-1) printf(" ");
      }
      if(sta(kk,kkk,n)) printf("\nStable\n");
      else printf("\nNot stable\n");

      return 0;
    }


void bsort(po *a,int n) {
  int i,j,p=1;
  po t;

  while(p==1){
    p=0;
    for(j=n-1;j>0;j--) {
    
      if(a[j].a<a[j-1].a) {
    
    t=a[j];
    a[j]=a[j-1];
    a[j-1]=t;
    p=1;
    
  }
}
}
}
void ssort(po *a, int n){
  int i,j,min;
  po t;

  for(i=0;i<n;i++) {
    min=i;
    for(j=i;j<n;j++) {
      if(a[j].a<a[min].a) {
	min=j;
      }
    }

    t=a[i];
    a[i]=a[min];
    a[min]=t;
  }
}


int sta(po *a, po *b, int n) {
  int i;

  for(i=0;i<n;i++) {
    if(a[i].aa!=b[i].aa)
      return 0;
  }
  return 1;
}

