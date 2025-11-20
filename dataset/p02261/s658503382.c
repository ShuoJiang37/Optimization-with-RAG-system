#include <stdio.h>

typedef struct {
  char gara;
  int kazu;
}card;

card b[36];
card s[36];

void bubble(card *b,int a) {
  int i,j;
  card z;
  for(i=0;i<a;i++){
    for(j=a-1;j>i;j--){
      if(b[j-1].kazu>b[j].kazu){
	z=b[j];
	b[j]=b[j-1];
	b[j-1]=z;
      }
    }
  }
  for(j=0;j<a;j++) {
    if(j>0) printf(" ");
    printf("%c%d",b[j].gara,b[j].kazu);
  }
  printf("\nStable\n");
}

void select(card *s,int a) {
  int i,j,small;
  card z;

  for(i=0;i<a;i++) {
    small=i;
    for(j=i;j<a;j++) {
      if(s[small].kazu>s[j].kazu) {
	small=j;
      }
    }
      z=s[i];
      s[i]=s[small];
      s[small]=z;
  }
  for(j=0;j<a;j++) {
    if(j>0) printf(" ");
    printf("%c%d",s[j].gara,s[j].kazu);
  }
  printf("\n");
}

void stable(card *b,card *s, int a) {
  int i,count=0;
  for(i=0;i<a;i++) {
    if(b[i].gara!=s[i].gara || b[i].kazu!=b[i].kazu) count++;
  }
  if(count==0) printf("Stable\n");
  else printf("Not stable\n");
}

int main() {
  int a,i;
  scanf("%d",&a);
  if(1<=a&&a<=36) {
    for(i=0;i<a;i++) {
      scanf(" %c%d",&b[i].gara,&b[i].kazu);
      s[i]=b[i];
    }
    bubble(b,a);
    select(s,a);
    stable(b,s,a);
  }
  return 0;
}
	

