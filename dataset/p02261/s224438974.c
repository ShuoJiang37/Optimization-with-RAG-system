#include<stdio.h>
#include<string.h>

main(void){
  
  int a[36],i,j,tempo,N,b[36],mini;
  char c[36],tempo2,dummy,d[36];

  scanf("%d%c",&N,&dummy);
  for(i=0;i<N;i++){
    scanf("%c%d%c",&c[i],&a[i],&dummy);
    d[i]=c[i];
    b[i]=a[i];
  }
  
  for(i=0;i<N-1;i++){
    for(j=N-1;j>i;j--){
      if(a[j]<a[j-1]){
	tempo=a[j];
	tempo2=c[j];
	a[j]=a[j-1];
	c[j]=c[j-1];
	a[j-1]=tempo;
	c[j-1]=tempo2;
      }
    }
  }

  for(i=0;i<=N-1;i++){
    mini=i;
    for(j=i;j<=N-1;j++){
      if(b[j]<b[mini])mini=j;
    }
    tempo=b[i];
    tempo2=d[i];
    b[i]=b[mini];
    d[i]=d[mini];
    b[mini]=tempo;
    d[mini]=tempo2;
  }
    


  for(i=0;i<N;i++){
    if(i==N-1)printf("%c%d\n",c[i],a[i]);
    else printf("%c%d ",c[i],a[i]);
  }
  printf("Stable\n");

  for(i=0;i<N;i++){
    if(i==N-1)printf("%c%d\n",d[i],b[i]);
    else printf("%c%d ",d[i],b[i]);
  }
  for(i=0;i<N;i++){
    if(c[i]!=d[i]){
      printf("Not stable\n");
      break;
    }
    else if(i==N-1)printf("Stable\n");
  }
    
  
  return 0;
}