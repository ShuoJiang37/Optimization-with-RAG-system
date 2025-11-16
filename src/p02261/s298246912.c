#include <stdio.h>
#include <string.h>
#define F 36

typedef struct {
  char mark;
  int  number;
} list;

int main(){
  int i,j,k,l,n,temp,v,minj,flag=0;
  list a[F],c,d[F],e;
  char b[F-1];
  int cnt=0;
  
  scanf("%d%*c",&n);
  for(i=0;i<n;i++){
    if(cnt>0){ scanf("%c",&b[cnt-1]); }
    scanf("%c%d",&a[i].mark,&a[i].number);
    cnt++;
  }
  
  for(i=0;i<n;i++){
   d[i]=a[i];
      }
  
  for (i=0;i<n-1;i++){
    for (j=n-1;j>=i+1;j--){
      if (a[j].number < a[j-1].number) {
	c = a[j];
	a[j]=a[j-1];
	a[j-1]=c;
      }
    }
  }

  for(i=0;i<n;i++){
    printf("%c%d",a[i].mark,a[i].number);
    if(i==n-1) break;
    printf(" ");
  }
  printf("\nStable\n");

  for(i=0;i<=n-1;i++){
    minj=i;
    for(j=i;j<=n-1;j++){
      if(d[j].number < d[minj].number){
	minj = j;
      }
    }
    e=d[i];  
    d[i] = d[minj];
    d[minj] = e;
  }

  for(i=0;i<n;i++){
    printf("%c%d",d[i].mark,d[i].number);
    if(i!=n-1) printf(" ");
  }

  for(i=0;i<n;i++){
    if(a[i].mark == d[i].mark){ continue; }
    else flag=1;
  }
  if(flag==0) printf("\nStable\n");
  if(flag==1) printf("\nNot stable\n");

return 0;
}
