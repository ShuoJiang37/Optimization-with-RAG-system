#include<stdio.h>
#define N 36
typedef struct{
  int value;
  char moji;
}C;
main()
{
  int i,j,n,flag=0,x,minj,count;
  char c;
  C C[N],M[N];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c%d",&C[i].moji,&C[i].value);
    M[i]=C[i];
  }
  flag=1;
  i=0;
  while(flag){
    flag=0;
    for(j=n-1;j>=i+1;j--){
      if(C[j].value<C[j-1].value){
	x = C[j].value;
	c = C[j].moji;
        C[j].value= C[j-1].value;
	C[j].moji= C[j-1].moji;
	C[j-1].value= x;
	C[j-1].moji= c;
        flag=1; 
	count++;     
      }   
    }
    i++;  
  }
  
  /*
    for(i=0;i<=n-1;i++){
    for(j=n-1;j>=i;j--){
    if(C[j].value<C[j-1].value){
    x = C[j].value;
    C[j].value=C[j+1].value;
    C[j+1].value=x;
    }
    }
    }*/
  for(i=0;i<n;i++){
    printf("%c%d",C[i].moji,C[i].value); 
  if(i==n-1)
      printf("\n");
    else
      printf(" ");
  }
  printf("Stable\n");
  
  /*
    for(i=0;i<=n-1;i++){
    minj=i;
    for(j=i;j<=n-1;j++){
    if(M[j].value<M[minj].value){
    minj=j;
    x=M[i].value;
    M[i]=M[minj];
    M[minj].value=x;
    }
    }
    }*/
  
  for(i=0;i<=n-1;i++){
    minj=i;
    flag=0;
    for(j=i;j<=n-1;j++){
      if(M[j].value<M[minj].value){
	minj=j;
	flag=1;
      }
    }
    if(flag==1){
    	x = M[i].value;
	c = M[i].moji;
        M[i].value= M[minj].value;
	M[i].moji= M[minj].moji;
	M[minj].value= x;
	M[minj].moji= c;
      count++;
    }
  }
  for(i=0;i<n;i++){
    printf("%c%d",M[i].moji,M[i].value);
    if(i!=n-1)
      printf(" ");
  }
  printf("\n");
  for(i=0;i<n;i++){
    if(C[i].moji!=M[i].moji)
      flag=1;
  }
  if(flag==1)
    printf("Not stable\n");
  else{
    printf("Stable\n");
  }
  return 0;
}