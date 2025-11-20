#include<stdio.h>
struct card{
	char E;
	int N;
};
void bs(struct card  c[],int n){
	int j,i;
	struct card tmp[n];

	for(i = 0;i < n;i++){
		for(j = n-1;j >= i+1;j--){
			if(c[j].N<c[j-1].N){
				tmp[j] = c[j];
				c[j] = c[j-1];
				c[j-1] = tmp[j];
			}
		}
	}
	
	
}
void sl(struct card  c[],int n){
	int i,j,minj;
	struct card tmp[n];
	for(i = 0;i < n;i++){
		minj = i;
		for(j = i;j < n;j++){
			if(c[j].N < c[minj].N){
				minj = j;
			}
		}
		tmp[j] = c[i];
		c[i] = c[minj];
		c[minj] = tmp[j];
	}
}
int isStable(struct card c[],struct card b[],int n){
	int i;
	for(i = 0;i < n;i++){
		if(c[i].E != b[i].E){return 1;}
		
	}
	return 0;
}

int main(void){
	int n,i,p = 0;
	
	scanf("%d",&n);
	struct card c[n];
	struct card b[n];
	for(i = 0;i < n;i++){
		scanf(" %c %d",&c[i].E,&c[i].N);
	}
	for(i = 0;i < n;i++){
		b[i] = c[i];
	}
	
	bs(b,n);
	
	for(i = 0;i < n; i++){
		if(i <n-1){
			printf("%c%d ",b[i].E,b[i].N);
		}
		else{
			printf("%c%d",b[i].E,b[i].N);
		}
		
	}
	printf("\n");
	if(p == 1){printf("Not stable\n");}
	
	else {printf("Stable\n");}
	
	 sl(c,n);

	for(i = 0;i < n; i++){
		if(i <n-1){
			printf("%c%d ",c[i].E,c[i].N);
		}
		else{
			printf("%c%d",c[i].E,c[i].N);
		}
		
	}
	printf("\n");
	p = isStable(c,b,n);
	if(p == 1){printf("Not stable\n");}
	else {printf("Stable\n");}
	
	

}
