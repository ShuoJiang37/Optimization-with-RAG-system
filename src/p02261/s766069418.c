#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 36
int main() {
	int i,j,n,min,flag=0;
	char C[N][3],x[3],data[N][3];
	scanf("%d", &n);
	for(i=0;i<n;i++) {
		scanf("%s",C[i]);
		strcpy(data[i],C[i]);
	}
    for(i=0;i<n-1;i++){
        for(j=n-1;j>0;j--){
	        if(atoi(&C[j][1])<atoi(&C[j-1][1])){
		        strcpy(x, C[j]);
	            strcpy(C[j],C[j-1]);
		        strcpy(C[j-1],x);
	        }
        }
    }
    for(i=0;i<n;i++){
	    printf("%s", C[i]);
	    if(i!=n-1)printf(" "); 
	}
	printf("\n");
	printf("Stable\n");
	for(i=0;i<n-1;i++) {
		min=i;
		for(j=i;j<n;j++) {
			if(atoi(&data[j][1])<atoi(&data[min][1])){
				min=j;
			}
		}
		strcpy(x,data[i]);
		strcpy(data[i],data[min]);
		strcpy(data[min],x);	
	}
	for(i=0;i<n;i++) {
		printf("%s", data[i]);
		if(strcmp(data[i],C[i])!=0)flag=1;
		if(i!=n-1)printf(" ");
	}
	printf("\n");
	if(flag==1)printf("Not stable\n");
	else printf("Stable\n");
}
