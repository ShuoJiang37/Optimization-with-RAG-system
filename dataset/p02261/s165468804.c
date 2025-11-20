#include<stdio.h>
#define N 36

typedef struct{
  int num;
  int val;
  char pic;
} CARD;

typedef struct{
  CARD c[36];
} DECK;

void Bsort(DECK,int);
void Ssort(DECK,int);
int Stable(DECK,int);

int main(){
  DECK d;
  int n,i;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf(" %c", &(d.c[i].pic) );
    scanf("%d", &(d.c[i].val) );
    d.c[i].num=i;
  }

  Bsort(d,n);
  Ssort(d,n);

  return 0;
}
void Bsort(DECK d,int n){
  int i,j,f=1,c=0;
  CARD swap;

   while(f!=0){
    f=0;
    
    for(i=n-1;i>=c+1;i--){      
      if(d.c[i].val<d.c[i-1].val){	
	swap=d.c[i-1];
	d.c[i-1]=d.c[i];
	d.c[i]=swap;
	f=1;
      }
    }
    
    c++;
  }
  
  for(i=0;i<n;i++){
    printf("%c%d",d.c[i].pic,d.c[i].val);
    if(i!=n-1) printf(" ");
  }
  printf("\n");

  if( Stable(d,n)==1 ) printf("Not stable\n");
  else printf("Stable\n");
	 }

void Ssort(DECK d,int n){
  int i,j,min;
  CARD swap;
    
  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){      
      if(d.c[j].val<d.c[min].val){
	min=j;	
      }      
    }
          
    if(min!=i){
      swap=d.c[i];
      d.c[i]=d.c[min];
      d.c[min]=swap;  
    }
    
  }

  for(i=0;i<n;i++){
    printf("%c%d",d.c[i].pic,d.c[i].val);
    if(i!=n-1) printf(" ");
  }
  printf("\n");

  if( Stable(d,n)==1 ) printf("Not stable\n");
  else printf("Stable\n");
	 }

int Stable(DECK d,int n){
  int i,j;
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      if(d.c[i].val==d.c[j].val && d.c[i].num>d.c[j].num) return 1;
    }
  }
  return 0;
}
	  

    

