#include<stdio.h>

int main(){

  int i,j,n,minj,swap,a[37],b[37],f=0;
  char swapc,c[37],d[37];

  //load N
  scanf("%d",&n);

  //load number
  for(i=1;i<=n;i++){
    scanf(" %c%d",&c[i],&a[i]);
    b[i]=a[i];
    d[i]=c[i];
  }



  //BubbleSort
  for(i=1;i<=n;i++){
    for(j=n;j>=i+1;j--){
      //swap
      if(a[j]<a[j-1]){
        swap=a[j];
        a[j]=a[j-1];
        a[j-1]=swap;
	swapc=c[j];
	c[j]=c[j-1];
	c[j-1]=swapc;

	}
    }
  }
  //print
  for(i=1;i<=n;i++){
    printf("%c%d",c[i],a[i]);
    if(i!=n){
      printf(" ");
    }
  }
    printf("\n");

    //stability
    printf("Stable\n");

  //SelectionSort
  for(i=1;i<=n;i++){
    minj=i;
    for(j=i;j<=n;j++){
      if(b[j]<b[minj]){
        minj=j;
      }
    }
      //swap
      swap=b[i];
      b[i]=b[minj];
      b[minj]=swap;
      swapc=d[i];
      d[i]=d[minj];
      d[minj]=swapc;
  }


  //print
  for(i=1;i<=n;i++){
    printf("%c%d",d[i],b[i]);
    if(i!=n){
      printf(" ");
    }
  }
  printf("\n");

  //stability
  f=0;
  for(i=1;i<=n;i++){
    if(d[i]!=c[i]){
      printf("Not stable\n");
      f=1;
      break;
    }
  }  
  if(f==0)printf("Stable\n");
  
  
  

  return 0;

}

