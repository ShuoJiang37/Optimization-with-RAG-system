#include <stdio.h>
#define MAX 101

//void bubbleSort(struct Card *,int);
//void selectionSort(struct Card *, int);

struct Card{
	char number;
	char suit;
};

int main(void){
	struct Card c1[MAX],c2[MAX];
	int i,n,flag=1;
	char a;
	
	
	scanf("%d%c",&n,&a);
	for(i=0;i<n;i++){
		scanf("%c%c%c",&c1[i].suit,&c1[i].number,&a);
		c2[i].suit = c1[i].suit;
		c2[i].number = c1[i].number;
		
	}
	
	bubbleSort(c1,n);
	printf("Stable\n");
	
	selectionSort(c2,n);
	
	for(i=0;i<n;i++){
		if(c1[i].suit!=c2[i].suit){
			printf("Not stable\n");
			flag=0;
			break;
		}
	}
	if(flag==1)printf("Stable\n");
	return 0;
}

void bubbleSort(struct Card *C,int n){
    int i,j,a;
    struct Card tmp;
     
    for(i=0;i<n;i++){
        for(j=n-1;j>=i+1;j--){
            if(C[j].number<C[j-1].number){
                tmp=C[j];
                C[j]=C[j-1];
                C[j-1]=tmp;
            }
        }
    }
    for(a=0;a<n;a++){
    printf("%c%c",C[a].suit,C[a].number);
    if(a!=n-1)printf(" ");
    if(a==n-1)printf("\n");
    }
}

void selectionSort(struct Card *C,int n){
  int i,j,a,minj;
  struct Card tmp;
 
  for(i=0;i<n;i++){
    minj = i;
    for(j=i;j<n;j++){
      if(C[j].number<C[minj].number){
        minj=j;
      }
    }
    tmp = C[i];
    C[i]=C[minj];
    C[minj]=tmp;
  }
  for(a=0;a<n;a++){
  	printf("%c%c",C[a].suit,C[a].number);
    if(a!=n-1)printf(" ");
    if(a==n-1)printf("\n");
	}
}