#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 36


main(){

  char nul;
  char C1[N],C2[N];
  char tmpc;


  int A1[N],A2[N];
  int n,i,j,k=0;
  int tmp;
  int flag,mini,min;



  /* input */
  scanf("%d%c",&n,&nul);
  if(n<1||n>36)return 0;

  for(i=0;i<n;i++){
    scanf("%c%d%c",&C1[i],&A1[i],&nul);
    C2[i]=C1[i];
    A2[i]=A1[i];
  } 

  /*---------------  bubble sort  ------------------ */
 for(i=0;i<n;i++){
   for(j=1;j<n;j++){

     if(A1[j]<A1[j-1]){
       tmp=A1[j];
       tmpc=C1[j];
       A1[j]=A1[j-1];
       C1[j]=C1[j-1];
       A1[j-1]=tmp;
       C1[j-1]=tmpc;
     }
   }
 }
 
 for(i=0;i<n;i++){
   printf("%c%d",C1[i],A1[i]);
   if(i<n-1)printf(" ");
   if(i==n-1)printf("\n");
 }
 printf("Stable\n");


 
 /*----------------- selection sort ------------------*/
 
  min=A2[0];

  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      if(min>A2[j]){
	min=A2[j];
	mini=j;
	flag=1;
      }
    }

    if(flag==1){
	tmp=A2[i];
	tmpc=C2[i];
	A2[i]=A2[mini];
	C2[i]=C2[mini];
	A2[mini]=tmp;
	C2[mini]=tmpc;
	flag=0;
      }
    min=A2[i+1];
  }

for(i=0;i<n;i++){
   printf("%c%d",C2[i],A2[i]);
   if(i<n-1)printf(" ");
   if(i==n-1)printf("\n");
   if(C1[i]!=C2[i]){
     k=1;
   }
 }

 if(k==1)printf("Not stable\n");
 else printf("Stable\n");
 return 0;
}/*main*/