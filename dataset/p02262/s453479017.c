#include<stdio.h>

int main(void){
    int N[1000000],G[20];
    int x,j=0;
    int a,t,c,d,h=1,cnt=0;
    
    scanf("%d",&x);
    for(int i=0;i<x;i++){
        scanf("%d",&N[i]);
    }
	
	c=x;
	while(c>0){
		G[j]=h;
		h=h*3+1;
		j++;
		d=c%3;
		c=c/3;
		if(h>=d+c*3){break;}
	}
	
	printf("%d\n",j);
	printf("%d",G[j-1]);
	for(int i=j-2;i>=0;i--){
		printf(" %d",G[i]);
	}
	printf("\n");
	
	for(h=G[j-1];h>0;h/=3){
	    for(int i=h;i<x;i++){
	        a=N[i];
	        t=i-h;
	        while(t>=0 && N[t]>a){
	            N[t+h]=N[t];
	            t-=h;
	        	cnt++;
	        }
	        N[t+h]=a;
	    }
	}
	
	printf("%d\n",cnt);
	
	for(int i=0;i<x;i++){
		printf("%d\n",N[i]);
	}
	
    return 0;
}
