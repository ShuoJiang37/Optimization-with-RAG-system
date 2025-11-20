#include<stdio.h>

typedef struct{
	char mark;
	int number;
}poker;

int main(void){
    poker N[100],A[100];
    int x,minj,c=0,flag;
	poker tmp,t;
    
    scanf("%d",&x);
    for(int i=0;i<x;i++){
        scanf("%*c%c%d",&N[i].mark,&N[i].number);
    	A[i]=N[i];
    }
	
	
	flag=1;
	while(flag==1){
		flag=0;
		for(int j=x-1;j>0;j--){
			if(N[j].number < N[j-1].number){
				t=N[j];
				N[j]=N[j-1];
				N[j-1]=t;
				c++;
				flag=1;
			}
		}
	}
	
	for(int i=0;i<x;i++){
		minj=i;
		for(int j=i;j<x;j++){
			if(A[j].number<A[minj].number){
				minj=j;
			}
		}
		if(i!=minj){
			tmp=A[i];
			A[i]=A[minj];
			A[minj]=tmp;
			c++;
		}
	}
	
	printf("%c%d",N[0].mark,N[0].number);
    for(int i=1;i<x;i++){
        printf(" %c%d",N[i].mark,N[i].number);
    }
	printf("\nStable\n");
	
	flag=0;
	printf("%c%d",A[0].mark,A[0].number);
    for(int i=1;i<x;i++){
        printf(" %c%d",A[i].mark,A[i].number);
    	if(A[i].mark!=N[i].mark){
    		flag=1;
    	}
    }
	printf("\n");
	if(flag==0){
		printf("Stable");
	}else{
		printf("Not stable");
	}
	printf("\n");
	
    return 0;
}


