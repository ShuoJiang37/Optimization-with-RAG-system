#include <stdio.h>
typedef struct{
  char c;
  int number;
}donald;
void Bub(donald *a,int n);
void Sel(donald *a, int n);
void PP(donald *a,int n);
int stablecheck(donald *a,int n,donald *b);
int judge(donald *a,int n,donald *b);
int main(){

  int n,i,stable=0;
  donald trump[36],trump1[36],trump2[36];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf(" %c%d",&trump[i].c,&trump[i].number);
    trump1[i].c=trump[i].c;
    trump1[i].number=trump[i].number;
    trump2[i].c=trump[i].c;
    trump2[i].number=trump[i].number;
  }
  /*bubblr sort */
  Bub(trump1,n);
  PP(trump1,n);

  printf("Stable\n");

  /*selection sort*/

  Sel(trump2,n);
  PP(trump2,n);
  stable=judge(trump1,n,trump2);
  if(stable==1){
    printf("Stable\n");
  }
  else{
    printf("Not stable\n");
  }

  return 0;
}

void PP(donald *a,int n){
  int i;
  for(i=0;i<n;i++){
    if(i==(n-1)){
      printf("%c%d\n",a[i].c,a[i].number);
    }
    else {
      printf("%c%d ",a[i].c,a[i].number);
    }
  }
}



void Bub(donald *a,int n){
  int j,flag=1,sub,i;
  char subc;
  while(flag){
    flag=0;
    for(j=n-1;j>=1;j--){
      if(a[j].number<a[j-1].number){
	sub=a[j].number;
	a[j].number=a[j-1].number;
	a[j-1].number=sub;
	subc=a[j].c;
	a[j].c=a[j-1].c;
	a[j-1].c=subc;
	flag=1;
      }
    }
  }
}



void Sel(donald *a,int n){
  int i,min,sub,j;
  char subc;
  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(a[j].number<a[min].number){
	min=j;
      }
    }
    if(a[i].number>a[min].number){
      sub=a[i].number;
      a[i].number=a[min].number;
      a[min].number=sub;
      subc=a[i].c;
      a[i].c=a[min].c;
      a[min].c=subc;
    }
  }
}




int stablecheck(donald *in, int n,donald *out){
  int i,j,a,b;
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      for(a=0;a<n;a++){
	for(b=a+1;b<n;b++){
	  if(in[i].number==in[j].number && in[i].number==out[a].number && in[j].number==out[b].number){
	    return 0;
	  }
	}
      }
    }
  }
  return 1;
}

int judge(donald *a,int n,donald *b){
    int i,cnt=0;

    for(i=0;i<n;i++){
      if(a[i].number==b[i].number && a[i].c==b[i].c){
          cnt++;
        }
      }
    if(cnt==n){
        return 1;
      }
    else {
      return 0;
    }
}