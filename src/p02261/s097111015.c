#include<stdio.h>
#include<stdlib.h>


typedef struct{
  char type;
  int num;
}card;

int isStable(card *,card *);
void copy(card *,card *);
int  BubbleSort(card *);
int  selectionSort(card *);
void print_dataset(card *);

int n;

int main(){
  int i;
  card *c,*b,*s;
  

  scanf("%d",&n);
  c = (card *)malloc(n*sizeof(card));
  b = (card *)malloc(n*sizeof(card));
  s = (card *)malloc(n*sizeof(card));
  for(i=0;i<n;i++) scanf(" %c%d",&c[i].type,&c[i].num);

   copy(b,c);
  copy(s,c);

  BubbleSort(b);
  selectionSort(s);

  print_dataset(b);
  printf("Stable\n");
  print_dataset(s);
  if(isStable(s,b)!=1) printf("Not stable\n");
  else printf("Stable\n");
  
  free(c);
  free(s);
  free(b);
  
  return 0;
}



int BubbleSort(card *a){
  int i,j,stock,s3,count=0;

  for(i=0;i<n;i++){
    for(j=n-1;j>0;j--){
      if(a[j].num<a[j-1].num){
	stock=a[j].num;
	a[j].num=a[j-1].num;
	a[j-1].num=stock;

	s3=a[j].type;
	a[j].type=a[j-1].type;
	a[j-1].type=s3;
	
	count++;
      }
    }
  }

  return count;
}

int selectionSort(card *a){
  int i,j,mini,stock,s3,count=0;
  int flag=1;
  
  for(i=0;i<n;i++){
    mini=i;
    flag=1;
    for(j=i;j<n;j++){
      if(a[j].num<a[mini].num){
        mini=j;
        flag=0;
      }
    }
    
    if(flag==0){
    stock=a[i].num;
    a[i].num=a[mini].num;
    a[mini].num=stock;

    s3=a[mini].type;
    a[mini].type=a[i].type;
    a[i].type=s3;
	
    
    count++;
    }
 
  }

  return count;
}

void print_dataset(card *a){
  int i;

  for(i=0;i<n;i++){
    printf("%c%d",a[i].type,a[i].num);
    if(i!=n-1) printf(" ");
  }
  printf("\n");
}

int isStable(card *sta,card *not){
  int i;
  for(i=0;i<n;i++){
    if(sta[i].type != not[i].type) return -1;
  }

  return 1;
}

void copy(card *a,card *b){
  int i;
  for(i=0;i<n;i++){
    a[i].type=b[i].type;
    a[i].num=b[i].num;
  }
}

