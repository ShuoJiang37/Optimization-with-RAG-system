#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 36
typedef struct{
	char str;
	int num;
}Card;
void bubble(Card*,int);
void sel(Card*,int);
void isStable(Card*,Card*,int);
int main(){
	int n,i,j;
	Card array[N],p[N],q[N];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf(" %c%d",&array[i].str,&array[i].num);
		p[i].str = q[i].str = array[i].str;
		p[i].num = q[i].num = array[i].num;
	}
	bubble(&p,n);
	//for(i=0;i<n;i++) printf("%c%d ",p[i].str,p[i].num);
	i=0;
	while(i<n){
		if(i == n-1){
			printf("%c%d\n",p[i].str,p[i].num);
			break;	
		}
	printf("%c%d ",p[i].str,p[i].num);
	i++;
	}
	printf("Stable\n");
	sel(&q,n);
  	//for(i=0;i<n;i++) printf("%c%d ",q[i].str,q[i].num);
  	i=0;
  	while(i<n){
  		if(i == n-1){
  			printf("%c%d\n",q[i].str,q[i].num);
  			break;	
  		}
  	printf("%c%d ",q[i].str,q[i].num);
  	i++;
  	}
  	isStable(&q,&p,n);
	return 0;
}
void bubble(Card array[],int n){
	int i,j;
	Card p;
	for(i = 0; i < n-1 ; i++){
    for(j = n-1; j > i ; j --){
      if(array[j-1].num > array[j].num){
        p = array[j];
        array[j] = array[j-1];
        array[j-1] = p;
       }
    }
  }
}
void sel(Card array[],int n){
	int lowkey,lowest,i,j;
	Card t;
	for(i=0;i<n;i++){
    lowkey = array[i].num;
    lowest = i;
    for(j=i+1;j<n;j++){
      if(lowkey > array[j].num){
        lowkey = array[j].num;
        lowest = j;
      }
    }
    t = array[i];
   	array[i] = array[lowest];
    array[lowest] = t;
  }
}
void isStable(Card q[],Card p[],int n){
	int i,j,judge=0;
	for(i=0;i<n-1;i++){
		if(q[i].str != p[i].str)judge=1;
	}
	if(judge == 1) printf("Not stable\n");
	else printf("Stable\n");
}
