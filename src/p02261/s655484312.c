#include<stdio.h>
#define N 36
#define FALSE -1
#define TRUE 1

typedef struct{
  char mark;
  int number;
}card;

int hantei(card *, card *, int);

int main(){
  int n, v, min, f;
  int i, j;
  char m;
  card a[N], b[N], in[N]; //inは比較用

  scanf("%d", &n);
  for(i=0;i<n;i++){
    scanf(" %c%d", &a[i].mark, &a[i].number);
    b[i] = a[i];
    in[i] = a[i];
  }

  /*for(i=0;i<n;i++){
    if(i == n-1) printf("%c%d\n", a[i].mark, a[i].number);
    else printf("%c%d ", a[i].mark, a[i].number);
    }*/
  
  //バブルソート
  //マークの交換も忘れずに
  f = 1;
  while(f){
    f = 0;
    for(i=n-1;i>=1;i--){
      if(a[i].number < a[i-1].number){
        v = a[i].number;
        a[i].number = a[i-1].number;
        a[i-1].number = v;
	m = a[i].mark;
	a[i].mark = a[i-1].mark;
	a[i-1].mark = m;
        f = 1;
      }
    }
  }

  for(i=0;i<n;i++){
    if(i == n-1) printf("%c%d\n", a[i].mark, a[i].number);
    else printf("%c%d ", a[i].mark, a[i].number);
  }

  if(hantei(in, a, n) == 1) printf("Stable\n");
  else printf("Not stable\n");

  //選択ソート
  //マークの交換も忘れずに
  for(i=0;i<=n-1;i++){
    min = i;
    for(j=i;j<=n-1;j++){
      if(b[j].number < b[min].number){
        min = j;
      }
    }
    v = b[i].number;
    b[i].number = b[min].number;
    b[min].number = v;
    m = b[i].mark;
    b[i].mark = b[min].mark;
    b[min].mark = m;
  }

  for(i=0;i<n;i++){
    if(i == n-1) printf("%c%d\n", b[i].mark, b[i].number);
    else printf("%c%d ", b[i].mark, b[i].number);
  }

  if(hantei(in, b, n) == 1) printf("Stable\n");
  else printf("Not stable\n");
  
   return 0;
}

int hantei(card *in, card *out, int n){
  int i, j, k, l;

  /*for(i=0;i<n;i++){
    if(i == n-1) printf("%c%d\n", in[i].mark, in[i].number);
    else printf("%c%d ", in[i].mark, in[i].number);
  }
  for(i=0;i<n;i++){
    if(i == n-1) printf("%c%d\n", out[i].mark, out[i].number);
    else printf("%c%d ", out[i].mark, out[i].number);
    }*/
  
  for(i=0;i<n-1;i++){
    for(j=i+1;j<n-1;j++){
      for(k=0;k<n-1;k++){
	for(l=k+1;l<n-1;l++){
	  if(in[i].number == in[j].number &&
	     in[i].number == out[l].number &&
	     in[i].mark == out[l].mark &&
	     in[j].number == out[k].number &&
	     in[j].mark == out[k].mark) return FALSE;
	}
      }
    }
  }
  return TRUE;
}

