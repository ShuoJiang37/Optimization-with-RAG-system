#include<stdio.h>

#define N 36
 
struct y {
  int value;
  char moji;
};
 
 main(){
  int i,j,n,m,minj;
  struct y a[N],b[N],c,d;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c%d",&a[i].moji, &a[i].value);
    b[i] = a[i];
  }
 
  for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      if(a[j].value < a[j-1].value){
      c = a[j];
      a[j] = a[j-1];
      a[j-1] = c;
      }
    }
  }
   
  printf("%c%d",a[0].moji,a[0].value);
  for(i=1;i<n;i++){
    printf(" %c%d",a[i].moji,a[i].value);
  }
  printf("\n");
  printf("Stable\n");

  for(i=0;i<n-1;i++){
    minj = i;
    for(j=i;j<n;j++){
      if(b[j].value < b[minj].value){
    minj = j;
      }
    }
    d = b[i];
    b[i] = b[minj];
    b[minj] = d;
  }
 
  printf("%c%d",b[0].moji,b[0].value);  
  for(i=1;i<n;i++){
    printf(" %c%d",b[i].moji,b[i].value);
  }
 
  for(i=0;i<n;i++){
    if(a[i].moji != b[i].moji){
      m=0;
      break;
    }
    else if(a[i].moji == b[i].moji){
      m=1;
    }
  }
  printf("\n");
    if(m==1)printf("Stable\n");
    if(m==0)printf("Not stable\n"); 
    return 0;
}