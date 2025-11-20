#include<stdio.h>
#include<stdlib.h>
typedef struct
{
  char mark;
  int c;
} CARD;


void swap(CARD *,CARD *);

int n;
int main(){
  int i,j,minj,k,flag=0;
  CARD trp1[36],trp2[36];
  char c[36][4];
  char memory[4][10];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    c[i][3]=0;
    scanf("%s",c[i]);
    if(c[i][3]!=0)exit(1);
    trp1[i].mark=trp2[i].mark=c[i][0];
    trp1[i].c=trp2[i].c=atoi(&c[i][1]);
}
  for(i=0;i<4;i++){
    for(j=0;j<10;j++){
      memory[i][j]='a';
    }
  }
  for(j=1;j<=9;j++){
    k=0;
   for(i=0;i<n;i++){   
     if(trp1[i].c==j)  {memory[k][j]=trp1[i].mark;k++;}
      
  }
  }

      
for(i=0;i<=n-1;i++){
  for(j=n-1;j>=i+1;j--){
    if(trp1[j].c<trp1[j-1].c) swap(&trp1[j],&trp1[j-1]);  
  }
 }
 for(i=0;i<=n-1;i++){
    if(i==n-1) printf("%c%d\n",trp1[i].mark,trp1[i].c);
    else  printf("%c%d ",trp1[i].mark,trp1[i].c);
 }
 for(i=1;i<=9;i++){
   k=0;
   for(j=0;j<n;j++){
   if(trp1[j].c==i){
     if(trp1[j].mark==memory[k][i])k++;
     else { flag=1; break;}
   }
   }
 }
 if(flag==0)printf("Stable\n");
 else printf("Not stable\n");

 flag=0;
for(i=0;i<=n-1;i++){
  minj=i;
  for(j=i;j<=n-1;j++){
    if(trp2[j].c<trp2[minj].c) minj=j;
  }
  swap(&trp2[i],&trp2[minj]);
 }

 for(i=0;i<n;i++){
    if(i==n-1) printf("%c%d\n",trp2[i].mark,trp2[i].c);
    else printf("%c%d ",trp2[i].mark,trp2[i].c);
  }
   for(i=1;i<=9;i++){
   k=0;
   for(j=0;j<n;j++){
   if(trp2[j].c==i){
     if(trp2[j].mark==memory[k][i])k++;
     else { flag=1; break;}
   }
   }
 }
   if(flag==0)printf("Stable\n");
   else printf("Not stable\n");
return 0;
}
void swap(CARD *c1,CARD *c2){
  CARD temp;
   temp =*c1;
    *c1=*c2;
    *c2=temp;
}

  

