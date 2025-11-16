#include <stdio.h>
#include <stdlib.h>

#define N 36

typedef struct {
	char moji[3];
	int value;
} Roll;
	

int main()
{
Roll Bcard[N],Scard[N];
int i,j,num,kari,soeji[N],flag,stabflag,min;

scanf("%d",&num);
for(i=0; i<num; i++){
	scanf("%s",Bcard[i].moji);
	Bcard[i].value = Bcard[i].moji[1];
}
flag =1;
stabflag = 1;

for(i=0; i<num; i++){
	Scard[i] = Bcard[i];
	soeji[i] = i;
}

/*BubbleSort*/
for(i=0; flag==1; i++){
flag = 0;
for(j=num-1; j>=i+1; j--){
if(Bcard[j].value < Bcard[j-1].value){
kari = Bcard[j].value;
Bcard[j].value = Bcard[j-1].value;
Bcard[j-1].value = kari;
flag = 1;
			kari = soeji[j];
			soeji[j] = soeji[j-1];
			soeji[j-1] = kari;
		}
	}
}
for(i=0; i<num-1; i++){
printf("%s ",Bcard[soeji[i]].moji);
}
printf("%s\n",Bcard[soeji[num-1]].moji);

for(i=0; i<num-1; i++){
if(	Bcard[soeji[i]].moji[1] == Bcard[soeji[i+1]].moji[1] && soeji[i] > soeji[i+1] ) stabflag=0;
}
if(stabflag==0) printf("Not stable\n");
else printf("Stable\n");


/*SelectSort*/
stabflag = 1;
for(i=0; i<num; i++){
	soeji[i] = i;
}

for(i=0; i<num; i++){
min = i;
for(j=i; j<num; j++){
if(Scard[j].value < Scard[min].value){
min = j;
}
}
kari = Scard[min].value;
Scard[min].value = Scard[i].value;
Scard[i].value = kari;
kari = soeji[min];
soeji[min] = soeji[i];
soeji[i] = kari;
}

for(i=0; i<num-1; i++){
printf("%s ",Scard[soeji[i]].moji);
}
printf("%s\n",Scard[soeji[num-1]].moji);

for(i=0; i<num-1; i++){
if(	Scard[soeji[i]].moji[1] == Scard[soeji[i+1]].moji[1] && soeji[i] > soeji[i+1] ) stabflag=0;
}
if(stabflag==0) printf("Not stable\n");
else printf("Stable\n");

return 0;
}