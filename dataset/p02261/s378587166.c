#include <stdio.h>

int main(){

  int n,i,j,tmp,minj,t;
  char x;

  scanf("%d",&n);

  int a1[n],a2[n];

  char b1[n],b2[n];

  for(i=0;i<n;i++){
    scanf(" %c%d",&b1[i],&a1[i]);
    a2[i]=a1[i];
    b2[i]=b1[i];
  }

for(i=0;i<n;i++){
  for(j=n-1;j>=i+1;j--){
      if(a1[j]<a1[j-1]){
        tmp=a1[j];
        a1[j]=a1[j-1];
        a1[j-1]=tmp;
        x=b1[j];
        b1[j]=b1[j-1];
        b1[j-1]=x;
          }
    }
  }

for(i=0;i<n;i++){
  printf("%c%d",b1[i],a1[i]);
  if(i!=n-1){
    printf(" ");
  }
}

printf("\n");
printf("Stable\n");


for(i=0;i<n;i++){
minj=i;
for(j=i;j<n;j++){
  if(a2[j]<a2[minj]){
    minj=j;
    }
  }
  tmp=a2[i];
  a2[i]=a2[minj];
  a2[minj]=tmp;
  x=b2[i];
  b2[i]=b2[minj];
  b2[minj]=x;
  }


  for(i=0;i<n;i++){
   printf("%c%d",b2[i],a2[i]);
   if(i!=n-1){
     printf(" ");
   }
  }

  printf("\n");

  t=0;
  for(i=0;i<n;i++){
    if(b2[i]!=b1[i]){
      printf("Not stable\n");
      t=1;
      break;
    }
  }
  if(t==0){
    printf("Stable\n");
  }

  return 0;
}

