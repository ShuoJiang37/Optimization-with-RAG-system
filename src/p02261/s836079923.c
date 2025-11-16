#include <stdio.h>

struct card {
	char suit;
	int value;
};

void swap(struct card *, struct card *);
void printc(int, struct card *);

int main(void)
{
	int i, j, minj, n, flag;
	struct card Cb[36], Cs[36];
	
	scanf("%d",&n);
	for (i=0; i<n; i++) {
		scanf(" %c%d", &Cb[i].suit, &Cb[i].value);
		Cs[i] = Cb[i];
	}
	
	for (i=0; i<n; i++) {
		for (j=n-1; j>i; j--) {
			if ( Cb[j].value < Cb[j-1].value ) swap( &Cb[j] , &Cb[j-1] );
		}
	}
	
	for (i=0; i<n; i++) {
		minj = i;
		for (j=i; j<n; j++) {
			if( Cs[j].value < Cs[minj].value ) minj = j;
		}
		if(i != minj) swap( &Cs[i], &Cs[minj]);
	}
	flag = 1;
	for (i=0; i<n; i++) {
		if( Cb[i].suit != Cs[i].suit ) {
			flag = 0;
			break;
		}
	}
	
	printc(n, Cb);
	printf("Stable\n");
	printc(n, Cs);
	if(flag) printf("Stable\n");
	else printf("Not stable\n");
	
	return 0;
}

void swap(struct card *card1, struct card *card2)
{
	struct card temp;
	temp = *card1;
	*card1 = *card2;
	*card2 = temp;
}

void printc(int n, struct card *C)
{
	int i;
	for (i=0; i<n-1; i++) {
		printf("%c%d ", C[i].suit, C[i].value);
	}
	printf("%c%d\n", C[n-1].suit, C[n-1].value);
}