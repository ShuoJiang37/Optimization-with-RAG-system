#include <stdio.h>
#define N 36

typedef struct{
    char alp;
    int num,o;
} card;

card c[N],arr[N];
int n;

void bubble(){
    int i;
    card tmp;
    for(i=0;i<n;i++){
        arr[i]=c[i];
    }
    
    int flag=1;
    while(flag){
      flag=0;
      for(i=n-1;i>0;i--){
	    if(arr[i].num<arr[i-1].num){
	        tmp=arr[i];
	        arr[i]=arr[i-1];
	        arr[i-1]=tmp;
	        flag=1;
	        }
        }     
    }
}

void select(){
    int i,j,minj;
    card tmp;
    
    for(i=0;i<n;i++){
        arr[i]=c[i];
    }
    
    for(i=0;i<n;i++){
        minj=i;
        for(j=i;j<n;j++){
	        if(arr[minj].num>arr[j].num) minj=j;
        }
        if(minj!=i){
	        tmp=arr[i];
	        arr[i]=arr[minj];
	        arr[minj]=tmp;
        }
    }

}

void print(){
    int i,s=1;
    for(i=0;i<n;i++){
      if(i!=0){
          if(arr[i-1].num==arr[i].num && arr[i-1].o>arr[i].o)
            s=0;
          printf(" ");
          
      }
      printf("%c%d",arr[i].alp,arr[i].num);
    }
    if(s) printf("\nStable\n");
    else  printf("\nNot stable\n");
}

int main(void){
    int i,tmp,flag=1,b;
    char a;
    
    scanf("%d ",&n);
    for(i=0;i<n;i++){
      scanf("%c%d ",&c[i].alp,&c[i].num);
      c[i].o=i;
    }
    
    bubble();
    print();
    
    select();
    print();
    
    return 0;
}

