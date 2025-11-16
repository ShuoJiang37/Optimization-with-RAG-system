#include<stdio.h>
int main()
{
  int i,n,j,min,cnt=0;
  char temp,a[36][3],b[36][3],c[3];
    
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s",c);
    a[i][0]=b[i][0]=c[0];
    a[i][1]=b[i][1]=c[1];
  }
  for(i=0;i<n;i++){
    for(j=0;j<n-1-i;j++){
      if(a[j][1]-a[j+1][1]>0){
	temp=a[j][1];
	a[j][1]=a[j+1][1];
	a[j+1][1]=temp;
 
	temp=a[j][0];
	a[j][0]=a[j+1][0];
	a[j+1][0]=temp;
      }
    }
  }
 
  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(b[j][1]-b[min][1]<0){
	min=j;
      }
    }
    temp=b[i][1];
    b[i][1]=b[min][1];
    b[min][1]=temp;
    temp=b[i][0];
    b[i][0]=b[min][0];
    b[min][0]=temp;
  }
 
  for(i=0;i<n;i++){
    if(i!=n-1){
      printf("%c%c ",a[i][0],a[i][1]);
    }
    else
      printf("%c%c\n",a[i][0],a[i][1]);
  }
 
  printf("Stable\n");
 
  for(i=0;i<n;i++){
      if(i!=n-1){
	printf("%c%c ",b[i][0],b[i][1]);
      }
      else
	printf("%c%c\n",b[i][0],b[i][1]);
 
      if(a[i][0]==b[i][0]){
	cnt++;
      }
    }
 
  if(cnt!=n){
    printf("Not stable\n");
  }
  else
    printf("Stable\n");
  return 0;
}