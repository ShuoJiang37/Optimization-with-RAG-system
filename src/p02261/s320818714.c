#include <stdio.h>
#include <string.h>
void swap(char *st1,char *st2){
	char tmp[3];
	memcpy(tmp,st1,3);
	memcpy(st1,st2,3);
	memcpy(st2,tmp,3);
}
int main(void){
	int n,i,j,min;
	char ori[36][3],bub[36][3],sel[36][3];
	scanf("%d",&n);
	for (i=0;i<n;i++)
		scanf("%s",ori[i]);
	memcpy(bub,ori,n*3);
	memcpy(sel,ori,n*3);
	for(i=0;i<n;i++)
		for(j=n-1;j>=i+1;j--)
			if (bub[j][1]<bub[j-1][1])
				swap(bub[j],bub[j-1]);
	for(i=0;i<n;i++){
		min=i;
		for(j=i;j<n;j++)
			if (sel[j][1]<sel[min][1])
				min=j;
		swap(sel[i],sel[min]);
	}
	for(i=0;i<n;i++)
		printf("%s%c",bub[i],i!=n-1?' ':'\n');
	printf("Stable\n");
	for (i=0;i<n;i++)
		printf("%s%c",sel[i],i!=n-1?' ':'\n');
	for(i=0;i<n;i++)
		if(sel[i][0]!=bub[i][0]||sel[i][1]!=bub[i][1])
			i=999;
	if(i==1000)printf("Not stable\n");
	else printf("Stable\n");
	
	return 0;
}