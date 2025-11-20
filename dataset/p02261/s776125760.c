#include<stdio.h>
#include<stdlib.h>
 
void Bubble(int a[36],char b[36],int n)
{
  int i,tempa,flag;
  char tempb;
  flag = 1;
  while(flag == 1) {
  flag = 0;
  for (i =n-2; i >=0;i--) {
    if(a[i]>a[i+1]){
      tempa = a[i+1];
      tempb = b[i+1];
      a[i+1] = a[i];
      b[i+1] = b[i];
      a[i] = tempa;
      b[i] = tempb;
      flag = 1;
    
    }
  }
  }
  for(i = 0; i<n-1;i++)
    printf("%c%d ",b[i],a[i]);
  printf("%c%d\n",b[n-1],a[n-1]);
  printf("Stable\n");
}
 

void Selection(int a[36],char b[36],int n)
{
  int i,mini,tempa,j;
  char tempb;
  for (i = 0; i < n; i++) {
    mini = i;
    for (j = i; j < n; j++) {
      if(a[mini] > a[j])
        mini = j;
    }
    if(mini != i){
      tempa = a[i];
      tempb = b[i];
      a[i] = a[mini];
      b[i] = b[mini];
      a[mini] = tempa;
      b[mini] = tempb;
    }  
   }
  for (i = 0; i < n-1; i++)
  printf("%c%d ",b[i],a[i]);
  printf("%c%d\n",b[n-1],a[n-1]);
}

void Stable(char b1[36],char b2[36],int n){
  int i,flag = 0;
  for(i = 0;i < n ;i++){
    if(b1[i]!=b2[i]) {
      printf("Not stable\n");
      flag = 1;
      break;
    }
  }
  if(flag == 0)
    printf("Stable\n");  
}

int main ()
{
 int i,a1[36],a2[36],n,num=0;
 char b1[36],b2[36],input[72];
 scanf("%d",&n);
 for (i = 0; i < 2*n; i+=2) {
  scanf("%s",input);
  a1[num]=atoi(&input[1]);
  b1[num]=input[0];
  num++;
}
 for (i = 0; i < n; i++) {
  a2[i]=a1[i];
  b2[i]=b1[i];
 }
 Bubble(a1,b1,n);
 Selection(a2,b2,n);
 Stable(b1,b2,n);
 return 0;
}