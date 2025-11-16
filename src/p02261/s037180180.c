#include<stdio.h>
#include<string.h>
int view(int *,int,char*);// 1 hairetu 2 nagasa
int swap(int *,int*);
int swapc(char *,char *);

int main(){
  int t,flag=1,i,j,n,a[36],b[36],*min;
  char ac[36],bc[36],*minc;
  char str[3];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %s",str);
    ac[i] = str[0];
    a[i] = str[1]-'0';
    b[i]=a[i];
    bc[i]=ac[i];
  } 
 while(flag){
    flag=0;
    for(j=n-1;j>0;j--){
      if(a[j]<a[j-1]){
	t=a[j];
	a[j]=a[j-1];
	a[j-1]=t;
swapc(&ac[j],&ac[j-1]);
	flag =1;
      }
    }
  }
  view(a,n,ac);
//printf("D2 C3 H4 S4 C9\n");

  printf("Stable\n");
    for(i=0;i<n-1;i++){
    min=&b[i];
minc=&bc[i];
    for(j=i+1;j<n;j++){
      if(*min>b[j]){
	min=&b[j];
	minc=&bc[j];
      }
    }
    if(min !=&a[i]){
    swap(&b[i],min);
	swapc(&bc[i],minc);
    }
  }
 view(b,n,bc);
ac[n] ='\0';
bc[n] = '\0';
//printf("D2 C3 S4 H4 C9\n");
    if(strcmp(ac,bc) != 0) printf("Not stable\n");
    else printf("Stable\n");
  return 0;
}

int view(int *a,int n,char *c){
  int i;
  for(i=0;i<n;i++) {
    printf("%c%d",c[i],a[i]);
    if(i!=n-1) printf(" ");
  }
  printf("\n");

}
int swap(int *a,int *b){
  int t;
        t = *a;
	*a = *b;
	*b = t;
}
int swapc(char *a,char *b){
  char t;
        t = *a;
	*a = *b;
	*b = t;
}
