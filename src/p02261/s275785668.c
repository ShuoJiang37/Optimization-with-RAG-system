#include<stdio.h>

typedef struct{
  char c;
  int e;
}trump;

void bubblesort(trump *);
void selectionsort(trump *);
int isstable(trump *,trump *);

int n;

int main(){

  int i, j;

  scanf("%d", &n);

  trump t[n],a[n],b[n];

  for(i=0;i<n;i++) scanf("%*c%c%d", &t[i].c, &t[i].e);

  for(i=0;i<n;i++){
    a[i]=t[i];
    b[i]=t[i];
  }

  bubblesort(a);

  for(i=0;i<n;i++){
    if(i==0) printf("%c%d",a[i].c,a[i].e);
    else printf(" %c%d",a[i].c,a[i].e);
  }printf("\n");
  if(isstable(t,a)==1) printf("Stable\n");
  else printf("Not stable\n");

  selectionsort(b);

  for(i=0;i<n;i++){
    if(i==0) printf("%c%d",b[i].c,b[i].e);
    else printf(" %c%d",b[i].c,b[i].e);
  }printf("\n");
  if(isstable(t,b)==1) printf("Stable\n");
  else printf("Not stable\n");
}

void bubblesort(trump *t){

  int i,j;
  trump tmp;

  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(t[j].e<t[j-1].e){
        tmp=t[j];
        t[j]=t[j-1];
        t[j-1]=tmp;
      }
    }
  }return;
}

void selectionsort(trump *t){

  int i,j,min;
  trump tmp;

  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(t[j].e<t[min].e) min=j;
    }
    tmp=t[i];
    t[i]=t[min];
    t[min]=tmp;
  }return ;
}

int isstable(trump *in,trump *out){

  int i,j,a,b;

  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      for(a=0;a<n;a++){
        for(b=a+1;b<n;b++){
          if(in[i].e==in[j].e&&in[i].e==out[b].e&&in[i].c==out[b].c
             &&in[j].e==out[a].e&&in[j].c==out[a].c) return 0;
        }
      }
    }
  }return 1;
}
