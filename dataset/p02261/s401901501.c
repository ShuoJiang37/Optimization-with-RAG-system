#include <stdio.h>

typedef struct {
  char c,calt,n,nalt;
  int count;
} Record;
  
int isstable(Record *,int);
int main(){
  int i,j,minj,len;
  char cnum,inum;
  Record data[36];
  
  scanf("%d",&len);
  for(i=0;i<len;i++){
    scanf(" %c%c",&data[i].c,&data[i].n);
    data[i].calt=data[i].c;
    data[i].nalt=data[i].n;
   
  }
  
  for(i=0;i<len;i++){
    for(j=len-1;j>=i+1;j--){
      if(data[j].nalt<data[j-1].nalt){
	  inum=data[j].nalt;
	  data[j].nalt=data[j-1].nalt;
	  data[j-1].nalt=inum;

	  cnum=data[j].calt;
	  data[j].calt=data[j-1].calt;
	  data[j-1].calt=cnum;
	  
      }
    }
    
  }

 
  
  for(i=0;i<len;i++){
    printf("%c%c",data[i].calt,data[i].nalt);
    if(i==len-1) printf("\n");
    else printf(" ");
  }
 
  if(isstable(data,len)==1) printf("Stable\n");
  else printf("Not stable\n");
  
  for(i=0;i<len;i++){
    data[i].calt=data[i].c;
    data[i].nalt=data[i].n;
  }

  for(i=0;i<len;i++){
    minj=i;
    for(j=i;j<len;j++){
      if(data[j].nalt<data[minj].nalt) minj=j;
    }
    if(i!=minj){
      inum=data[i].nalt;
      data[i].nalt=data[minj].nalt;
      data[minj].nalt=inum;

      cnum=data[i].calt;
      data[i].calt=data[minj].calt;
      data[minj].calt=cnum;
    }
  }
  for(i=0;i<len;i++){
    printf("%c%c",data[i].calt,data[i].nalt);
    if(i==len-1)printf("\n");
    else printf(" ");
  }
  if(isstable(data,len)==1) printf("Stable\n");
  else printf("Not stable\n");
  return 0;
}

int isstable(Record * data,int len){
  int i,j,a,b;
  for(i=0;i<len;i++){
    for(j=i+1;j<len;j++){
      for(a=0;a<len;a++){
	for(b=a+1;b<len;b++){
	  if(data[i].n==data[j].n && data[i].n==data[b].nalt &&data[j].n==data[a].nalt && data[i].c==data[b].calt && data[j].c==data[a].calt ) return 0;
	}
      }
    }
  }
  return 1;
}

