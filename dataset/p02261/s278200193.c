#include <stdio.h>

#define MAX 36

typedef struct{
  int value[MAX];
  char word[MAX];
}data;

int hantei(data,data,int);

int main(){
  data seq,seqs,seqb;
  int len,c=0;
  int temp,chk=1,num;
  char tempc;
  int i,j;

  scanf("%d",&len);
  for(i=0;i<len;i++) scanf(" %c %d",&seq.word[i],&seq.value[i]);
  seqs=seq;
  seqb=seq;

  //bubble
  while(chk==1){
    chk=0;
    for(i=len-1;i>=1;--i){
      if(seqb.value[i-1]>seqb.value[i]){
	temp=seqb.value[i];
	seqb.value[i]=seqb.value[i-1];
	seqb.value[i-1]=temp;
	
	tempc=seqb.word[i];
	seqb.word[i]=seqb.word[i-1];
	seqb.word[i-1]=tempc;
	chk=1;
      }
    }
  }
  

  for(i=0;i<len-1;i++) printf("%c%d ",seqb.word[i],seqb.value[i]);
  printf("%c%d\n",seqb.word[i],seqb.value[i]);
  
  if(hantei(seqb,seq,len)==0) printf("Stable\n");
  else printf("Not stable\n");
  
  //selection
  for(i=0;i<len;i++){
    num=i;
    for(j=i+1;j<len;j++){
      if(seqs.value[num]>seqs.value[j]){
	num=j;
      }
    }
    temp=seqs.value[num];
    seqs.value[num]=seqs.value[i];
    seqs.value[i]=temp;
    tempc=seqs.word[num];
    seqs.word[num]=seqs.word[i];
    seqs.word[i]=tempc;
  }
  
  for(i=0;i<len-1;i++) printf("%c%d ",seqs.word[i],seqs.value[i]);
  printf("%c%d\n",seqs.word[i],seqs.value[i]);

  if(hantei(seqs,seq,len)==0) printf("Stable\n");
  else printf("Not stable\n");
   
  return 0;
}

int hantei(data seq,data seqo,int len){
  int i,j,k,l;
  
  for(i=0;i<len;i++){
    for(j=i+1;j<len;j++){
      for(k=0;k<len;k++){
	for(l=k+1;l<len;l++){
	  if(seq.value[i]==seq.value[j]
	     &&seq.word[i]==seqo.word[l]
	     &&seq.value[i]==seqo.value[l]
	     &&seq.word[j]==seqo.word[k]
	     &&seq.value[j]==seqo.value[k]
	     ){
	      return 1;
	  }
      	}
      }
    }
  }
  return 0;
}

