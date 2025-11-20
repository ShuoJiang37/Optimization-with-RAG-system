#include<stdio.h>
#include<string.h>
#define N 101

struct node{ char suit;
             char value;
            };

void selectsort(struct node *,int);
void bubblesort(struct node *,int);
void print(struct node *,int);
int stable(struct node *,struct node *,int);

int main(){
  struct node n1[N],n2[N];
  int n,i;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c%c",&n1[i].suit,&n1[i].value);
  }
  for(i=0;i<n;i++) n2[i]=n1[i];

  bubblesort(n1,n);
  selectsort(n2,n);

  print(n1,n);
  printf("Stable\n");
  print(n2,n);
  if(stable(n1,n2,n)==1) printf("Stable");
  else printf("Not stable");
  printf("\n");


  return 0;
}
void bubblesort(struct node *n1,int n ){
  int i,j;
  struct node temp;  
  for(i=0;i<n;i++){
    for(j=n-1;j>=i+1;j--){
      if(n1[j].value<n1[j-1].value){
        temp=n1[j];
	n1[j]=n1[j-1];
	n1[j-1]=temp;
      }
    }
  }
}

void selectsort(struct node *n2,int n){
  int i,j,min;
  struct node temp;
  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(n2[j].value<n2[min].value) min =j;     
    }
    temp=n2[i];
    n2[i]=n2[min];
    n2[min] =temp;
  }
}

void print(struct node *m,int n){
  int i;
  for(i=0;i<n;i++){
      printf("%c%c",m[i].suit,m[i].value);
      if(i!=n-1) printf(" ");
  }
   printf("\n");
}
int stable(struct node *n1,struct node *n2,int n){
  int i;
  for(i=0;i<n;i++){
    if(n1[i].suit!=n2[i].suit){
      // printf("%c %c\n",n1[i].suit,n2[i].suit);
      return 0;
    }
  }
  return 1;
  
}

