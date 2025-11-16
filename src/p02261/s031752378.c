#include <stdio.h>
#define true 1
#define false 0
int hantei(char *,char *,int kazu);
int main(){
  int kazu,i,j,k[100],gensui[100],temp,moji,mini,minimoji,l,head,headmoji;
  char mark,a[100],kin[100];
  scanf("%d",&kazu);
  for(i=0;i<kazu;i++){
    scanf(" %c%d",&a[i],&k[i]);
  }
  for(i=0;i<kazu;i++){
    kin[i]=a[i];
    gensui[i]=k[i];
  }
  for(i=0;i<kazu;i++){
    for(j=kazu-1;j>i;--j){
      if(k[j]<k[j-1]){
	moji=a[j-1];
	temp=k[j-1];
	a[j-1]=a[j];
	k[j-1]=k[j];
	a[j]=moji;
	k[j]=temp;	
      }
    }
  }
  
  for(i=0;i<kazu-1;i++)
    {
      mini=gensui[i];
      minimoji=kin[i];
      l=i;
      for(j=i+1;j<kazu;j++)
	{
	  if(gensui[j]<mini){
	    mini=gensui[j];
	    minimoji=kin[j];
	    l=j;
	  }
	}
      if(i!=l){
	head=gensui[i];
	headmoji=kin[i];
	gensui[i]=gensui[l];
	kin[i]=kin[l];
	gensui[l]=head;
	kin[l]=headmoji;
      }
    }        
  for(i=0;i<kazu;++i){
    if(i>0)printf(" ");
    printf("%c%d",a[i],k[i]); 
  }
  printf("\n");
     printf("Stable\n");
  for(i=0;i<kazu;++i){
    if(i>0)printf(" ");
    printf("%c%d",kin[i],gensui[i]);     
  }
  printf("\n"); 
  if(hantei(a,kin,kazu)==1)printf("Stable\n");
  else printf("Not stable\n");
  return 0;
}

int hantei(char x[],char y[],int kazu)
{
  int i;
  for(i=0;i<kazu;i++)
    {
    if(x[i]!=y[i])return false;
    }
      return true;  
}

