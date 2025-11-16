#include<stdio.h>
int bubbleSort(int A[],int n){
	int flag,c=0,j,tmp;
    flag=1;
    while(flag){
    	flag=0;
    	for(j=n-1;j>0;j--){
    		if(A[j]<A[j-1]){
    			tmp=A[j];
    			A[j]=A[j-1];
    			A[j-1]=tmp;
    		
    		flag=1;
            c++;
    	}
    }
}
return c;
}

int main(){
	int i,n,A[100],j,c;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	c = bubbleSort(A,n);
	for(j=0;j<n;++j){
	if(j>0) {printf(" ");}
printf("%d",A[j]);
}
printf("\n");
printf("%d\n",c);
	return 0;
}
