#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int judge(char *c_d,char *c_o,int *d_d,int *d_o,int N);
char delete(char *c,int l);
void swap (char *x, char *y);

int main() {
  int N,i,j,flag,tmpi;
  scanf("%d",&N);

  char c[N],c_d[N][3],c_b[N][3],c_s[N][3],d[N],tmpc[N];
  int d_b[N],d_s[N],d_d[N];




  for(i=0;i<N;i++){
    
    scanf("%s",d);
    strcpy(c,d);
    

    delete(c,strlen(d));

    
    
    d_d[i]=atoi(c);
    d_b[i]=atoi(c);
    d_s[i]=atoi(c);
    strcpy(c_d[i],d);
    strcpy(c_b[i],d);
    strcpy(c_s[i],d);
    
    
    
  }

  /*test
  printf("test");
  for(i=0;i<N;i++){
    printf(" %d",d_d[i]);
  }

  printf("\n");
  */

  
  //BubbleSort
  for(i=0; i<=N-1; i++){
    for(j= N-1; j>=i+1; j--){
      if(d_b[j] < d_b[j-1]){
	tmpi = d_b[j];
	d_b[j] = d_b[j-1];
	d_b[j-1] = tmpi;
	
	strcpy(tmpc, c_b[j]);
	strcpy(c_b[j],c_b[j-1]);
	strcpy(c_b[j-1], tmpc);
	
	//swap(&(c_b[j]),&(c_b[j-1]));
	
	
      }
    }
  }
  
  //SelectionSort
  for(i=0;i<=N-1;i++){
    int minj;
    minj = i;
    for(j=i; j<=N-1; j++){
      if(d_s[j] < d_s[minj]){
	minj = j;
      }
    }
    tmpi = d_s[i];
    d_s[i] = d_s[minj];
    d_s[minj] = tmpi;

    strcpy(tmpc, c_s[i]);
    if(i!=minj) strcpy(c_s[i],c_s[minj]);
    strcpy(c_s[minj], tmpc);

    

    //swap(&(c_s[j]),&(c_s[j-1]));
    
  }
  
  for(i=0;i<=N-1;i++){
    if(i==0) {
      printf("%s",c_b[i]);
    }
    else{
    printf(" %s",c_b[i]);
    }
  }
  printf("\n");
  
  flag = 0;
  for(i=0;i<N;i++){
    if(strcmp(c_b[i],c_b[i])!=0){
      flag=1;
      }
  }
  if(flag==0){
    printf("Stable\n");
  }
  else printf("Not stable\n");

  for(i=0;i<=N-1;i++){
    if(i==0) printf("%s",c_s[i]);
    else printf(" %s",c_s[i]);
  }
  printf("\n");
  
  flag = 0;
  for(i=0;i<N;i++){
    if(strcmp(c_s[i],c_b[i])!=0){
      flag=1;
    }
  }
  if(flag==0){
    printf("Stable\n");
  }
  else printf("Not stable\n");

  return 0;
}

int judge(char *c_d,char *c_o,int *d_d,int *d_o,int N){
  int i,j,a,b;

  for(i=0; i<=N-1; i++){
    for(j=i+1; j<=N-1; j++){
      for(a=0; a<=N-1; a++){
	for(b=a+1; b<=N-1; b++){
	  if(d_d[i]==d_o[i] && c_d[a] == c_o[b] && c_d[j] == c_o[a]){
	    return -1;
	  }
	}
      }
    }
  }
  return 1;
}

char delete(char *c,int l){
  int i;
  for(i=0;i<l-1;i++){
    c[i]=c[i+1];
    c[i+1]='\0';
  }

  return *c;
}
  

void swap (char *x, char *y) {
  char temp;    // 値を一時保存する変数

  temp = *x;
  *x = *y;
  *y = temp;
}
  
  
    
	
  
  
  
  

