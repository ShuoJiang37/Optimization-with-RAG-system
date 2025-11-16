#include<stdio.h>
struct card{
  char mark;
  char kazu;
};
void bubblesort(struct card a[],int n){
  int i,j;
  struct card x;
  for(i=0;i<n;i++){
    for(j=n-1;j>=i+1;j--){
      if(a[j].kazu<a[j-1].kazu){
	x=a[j];
	a[j]=a[j-1];
	a[j-1]=x;
      }
    }
  }
}
void selectionsort(struct card a[],int n){
  int i,j,mimj;
  struct card x;
  for(i=0;i<n;i++){
    mimj=i;
    for(j=i;j<=n-1;j++){
      if(a[j].kazu<a[mimj].kazu)
	mimj=j;
    }
    x=a[i];
    a[i]=a[mimj];
    a[mimj]=x;
  }
}
int stable(struct card a1[],struct card a2[],int n){
  int i;
  for(i=0;i<n;i++){
    if(a1[i].mark!=a2[i].mark) return 0;
  }
  return 1;
}
int main(){
  char p;
  int n,i;
  struct card a1[36],a2[36];
  char s[100];
  scanf("%d",&n);
  scanf("%c",&p);
  for(i=0;i<n;i++){
    scanf("%s", s);
    a1[i].mark = s[0];
    a1[i].kazu = s[1];
  }
  for(i=0;i<n;i++)
    a2[i]=a1[i];
    bubblesort(a1,n);
    selectionsort(a2,n);
    for(i=0;i<n;i++){
      if(i!=0)printf(" ");
      printf("%c%c",a1[i].mark,a1[i].kazu);
    }
    printf("\n");
    printf("Stable\n");
    for(i=0;i<n;i++){
      if(i!=0)printf(" ");
  printf("%c%c",a2[i].mark,a2[i].kazu);
    }
    printf("\n");
    if(stable(a1,a2,n)==1){
      printf("Stable\n");
    }
    else{
      printf("Not stable\n");
    }
    return 0;
}
