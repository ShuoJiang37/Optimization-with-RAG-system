#include <stdio.h>

void BubbleSort(char c[], int a[], int n);
void SelectionSort(char c[],int a[],int n);
int isStable(char c[], int a[],char oc[],int oa[], int N);

int main(void){
	
	int n;
	scanf("%d",&n);
	
	int a[n];
	char c[n];
	char s[3];
	
	int i;
	
	for(i=0;i<n;i++){
		scanf("%s",s);
		c[i] = s[0];
		a[i] = s[1]-48;
	}
	
	/*for(i=0;i<n;i++){
		printf("%c%d ",c[i],a[i]);
	}
	printf("\n");
	*/
	BubbleSort(c, a, n);
	SelectionSort(c, a, n);

	return 0;
}

void BubbleSort(char c[], int a[], int n)
{

	int i,j;
	int t;
	char tc;
	
	char oc[n];
	int oa[n];
	
	for(i=0;i<n;i++){
		oc[i] = c[i];
		oa[i] = a[i];
	}
	
	for(i=0;i<n;i++){
		for (j = n-1; j > i; j--) {
			if( oa[j] < oa[j-1]) {
				t= oa[j];
				oa[j]=oa[j-1];
				oa[j-1]=t;
				tc= oc[j];
				oc[j]=oc[j-1];
				oc[j-1]=tc;
			}
		}
	}

	for(j=0; j<n; j++) {
		if(j>0){
			printf(" ");
		}
		printf("%c%d",oc[j],oa[j]);
	}
	
	printf("\n");
	
	if(isStable(c,a,oc,oa,n)==0){
		printf("Not stable\n");
	}
	else{
		printf("Stable\n");
	}

}

void SelectionSort(char c[],int a[],int n)
{

	int i,j;
	int t;
	char tc;
	int min, mini;
	
	char oc[n];
	int oa[n];
	
	for(i=0;i<n;i++){
		oc[i] = c[i];
		oa[i] = a[i];
	}
	
	for(i=0;i<n;i++){
		min = oa[i];
		mini = i;
		for (j = i+1; j < n; j++) {
			if( min > oa[j]) {
				min = oa[j];
				mini = j;
			}
		}
		if(i==mini){
			;
		}
		else{
			
			t = oa[i];
			oa[i] = min;
			oa[mini] = t;
			tc = oc[i];
			oc[i] = oc[mini];
			oc[mini] = tc;
			
		}
	}

	for(j=0; j<n; j++) {
		if(j>0){
			printf(" ");
		}
		printf("%c%d",oc[j],oa[j]);
	}
	
	printf("\n");
	
	if(isStable(c,a,oc,oa,n)==0){
		printf("Not stable\n");
	}
	else{
		printf("Stable\n");
	}

}

int isStable(char c[], int aa[],char oc[],int oa[], int N)
{
	int i,j,a,b;
	
	for (i = 0; i<N; i++)
	{
		for (j = i+1; j<N; j++) {
			for( a = 0; a< N; a++) {
				for( b = a+1; b<N-1; b++) {
					if (aa[i] == aa[j]  && c[i] == oc[b] && c[j] == oc[a] && aa[i] == oa[b] && aa[j] == oa[a]) {
						return 0;
					}
					
				}
			}
		}
	}
	
	return 1;
}
