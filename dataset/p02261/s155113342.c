#include<stdio.h>
main(){
  int i,j=0,a,b,g,sum=0,x,min,h,n[36],nsave[36];
  char y,m[36],msave[36];
  scanf("%d",&g);
  for(i=0;i<g;i++){
    scanf(" %c%d",&m[i],&n[i]);
      }
  for(i=0;i<g;i++){
    msave[i] = m[i];
    nsave[i] = n[i];
  }
while(1){
    
    for(i=g-1;i>j;i--){
      if(n[i]<n[i-1]){
	x = n[i-1];
	n[i-1] = n[i];
	n[i] = x;
        y = m[i-1];
	m[i-1] = m[i];
	m[i] = y;
      }}
    j++;
    if(j==g-1)break;
   }
 
 for(i=0;i<g;i++){
    printf("%c%d",m[i],n[i]);
    if(i<g-1)printf(" ");
  }
  printf("\nStable\n");
  

  
  for(i=0;i<g;i++){
    min = i;
    h=0;
    for(j=i;j<g;j++){
      if(nsave[j] < nsave[min]){
	min = j;
        h++;}
    }
    if(h>0){
	x = nsave[i];
	nsave[i] = nsave[min];
	nsave[min]= x;
	y = msave[i];
	msave[i] = msave[min];
	msave[min] = y;
    }}

  for(i=0;i<g;i++){
    printf("%c%d",msave[i],nsave[i]);
    if(i<g-1)printf(" ");
  }
  printf("\n");
  for(i=0;i<g;i++){
    if(m[i] == msave[i])sum++;}
  if(sum==g)printf("Stable\n");
  else printf("Not stable\n");

  return 0;
}