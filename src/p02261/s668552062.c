#include<stdio.h>
#include<string.h>
#define LIM 36

void Sels(char [LIM][3],int);
void Bubs(char [LIM][3],int);
int Lss(char [LIM][3],char [LIM][3],int);

int main() {

  int N;
  int i;
  char num[LIM][3],num1[LIM][3],num2[LIM][3];
    
  scanf("%d",&N);
  for(i=0;i<N;i++) {
    scanf(" %s",num[i]);
  }

  for(i=0;i<N;i++) strcpy(num1[i],num[i]);
  for(i=0;i<N;i++) strcpy(num2[i],num[i]);

  Bubs(num1,N);
  for(i=0;i<N;i++) {
    if(i>0) printf(" ");
    printf("%s",num1[i]);
  }
  printf("\n");

  if(Lss(num,num1,N) == 1) printf("Stable\n");
  else printf("Not stable\n");
  
  Sels(num2,N);
  for(i=0;i<N;i++) {
    if(i>0) printf(" ");
    printf("%s",num2[i]);
  }
  printf("\n");

  if(Lss(num,num2,N) == 1) printf("Stable\n");
  else printf("Not stable\n");

  return 0;

}

void Bubs(char num[LIM][3],int N) {
  int flag=1;
  int i;
  char a[3];
  
  while(flag==1) {
    flag=0;
    for(i=N-1;i>0;i--) {
      if( num[i][1] < num[i-1][1] ) {
	strcpy(a,num[i]); strcpy(num[i],num[i-1]); strcpy(num[i-1],a);
	flag=1;
      }
    }
  }
}

/*void Bubs(char num[LIM][3],int N) {

  int i,j;
  char a[3];
  
  for(i=0;i<N;i++) {
    for(j=N-1;j>i;j--) {
      if( num[j][1] < num[j-1][1]) {
	strcpy(a,num[j]); strcpy(num[j],num[j-1]); strcpy(num[j],a);
      }
    }
  }
}*/

void Sels(char num[LIM][3],int N) {

  int minj;
  int i,j;
  char a[3];

  for(i=0;i<=N-1;i++) {
    minj = i;

    for(j=i;j<N;j++) {
      if(num[j][1] < num[minj][1]) minj = j;
    }
    strcpy(a,num[i]); strcpy(num[i],num[minj]); strcpy(num[minj],a);
  }
}

int Lss(char in[LIM][3],char out[LIM][3],int N) {

  int i,j,a,b;

  for(i=0;i<N;i++) {
    for(j=i+1;j<N;j++) {
      for(a=0;a<N;a++) {
	for(b=a+1;b<N;b++) {
	  if( in[i][1] == in[j][1] && (strcmp(in[i],out[b])) == 0 && (strcmp(in[j],out[a])) == 0) return 0;
	}
      }
    }
  }

  return 1;
}
