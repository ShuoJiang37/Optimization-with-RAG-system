#include <stdio.h>

struct card
{
	char type;
	int value;
};

int main(void)
{
	int n, i, j, minj;
	scanf("%d", &n);
	struct card a[36];
	struct card b[36];
	struct card tmp;
	
	for(i = 0; i < n; i++){
		scanf(" %c%d", &a[i].type, &a[i].value);
		b[i] = a[i];
	}
	
	for(i = 0; i < n; i++){
		for(j =n-1; j >= i+1; j--){
			if(a[j].value < a[j-1].value){
				tmp = a[j];
				a[j] = a[j-1];
				a[j-1] = tmp;
			}
		}
	}
	
	for(i = 0; i < n; i++){
		if(i != n-1)printf("%c%d ", a[i].type, a[i].value);
		else printf("%c%d\n", a[i].type, a[i].value);
	}
	printf("Stable\n");
	
	for(i = 0; i < n; i++){
		minj = i;
		for(j = i; j < n; j++){
			if(b[j].value < b[minj].value)minj = j;
		}
		tmp = b[i];
		b[i] = b[minj];
		b[minj] = tmp;
	}
	
	for(i = 0; i < n; i++){
		if(i != n-1)printf("%c%d ", b[i].type, b[i].value);
		else printf("%c%d\n", b[i].type, b[i].value);
	}
	int k=0;
	for(i = 0; i < n; i++){
		if(a[i].type != b[i].type)k++;
	}
	if(k!=0)printf("Not stable\n");
	else printf("Stable\n");
	
	return 0;
}
