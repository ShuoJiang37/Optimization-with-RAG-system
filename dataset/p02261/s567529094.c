#include<stdio.h>
#include<stdlib.h>
typedef struct{
  char moji;
  int su;
}to;
int antei(to *,to *,int);

to *bubblesort(to *,int);
  
to *selectsort(to *,int);

int main(){
	char c;
  int n,i,d;
  to *a,*b;
  scanf("%d",&n);
  a=(to *)malloc(sizeof(to)*n);
  b=(to *)malloc(sizeof(to)*n);
  for(i=0;i<n;i++){
    scanf(" %c%d",&a[i].moji,&a[i].su);
	b[i].su=a[i].su;
	b[i].moji=a[i].moji;
  }
  b=bubblesort(b,n);
  a=selectsort(a,n);
  if(0==antei(a,b,n))printf("Not stable\n");
  else printf("Stable\n");
  free(a);
  free(b);
  return 0;
}

int antei(to *a,to *b,int n){
  int i,j,c,d;
  for (i = 0;i<n;i++){
    for (j=i+1;j<n;j++){
      for (c = 0;c<n;c++){
	for (d=c+1;d<n;d++){
	  if (a[i].su==a[j].su&& a[i].moji == b[d].moji && a[j].moji == b[c].moji && a[i].su==b[d].su && a[j].su==b[c].su)return 0;
	}
      }
    }
  }
  return 1;
}

to *bubblesort(to *a,int n){
  int i,j,b;
  char c;
  
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(a[j].su<a[j-1].su){
	b=a[j].su;
	a[j].su=a[j-1].su;
	a[j-1].su=b;
	c=a[j].moji;
	a[j].moji=a[j-1].moji;
	a[j-1].moji=c;
      }
    }
  }
  for(i=0;i<n;i++){
    if(i==n-1)printf("%c%d\n",a[i].moji,a[i].su);
    else printf("%c%d ",a[i].moji,a[i].su);
  }
  printf("Stable\n");
  return a;
}

to *selectsort(to *a,int n){
  int mini,i,j,b;
  char c;
  for(i=0;i<n;i++){
  	mini=i;
  	for(j=i;j<n;j++){
    	if(a[j].su<a[mini].su){
			mini=j;	
      	}
    }
	if(mini!=i){
	b=a[mini].su;
    a[mini].su=a[i].su;
    a[i].su=b;
    c=a[mini].moji;
    a[mini].moji=a[i].moji;
    a[i].moji=c;
	}
  }
  for(i=0;i<n;i++){
    if(i==n-1)printf("%c%d\n",a[i].moji,a[i].su);
    else printf("%c%d ",a[i].moji,a[i].su);
  }
  return a;
}

