#include <stdio.h>

typedef struct{ 
	char suit;
	int value; 
}card; 


int main()
{
  int i, N, j, min, s;
  card x[36],y[36],k;

  scanf("%d",&N);
  for(i = 0; i < N; i++){
  	scanf(" %c%d",&x[i].suit, &x[i].value);
  }
  
  for(i = 0; i < N; i++)
     y[i] = x[i];
 
 /* bubble */
	for(i = 0; i < N; i++){
		for(j = N-1; j > i; j--){
			if(x[j].value < x[j-1].value){
				k = x[j];
				x[j] = x[j-1];
				x[j-1] = k;
			}
		}
	}
	
	for(i = 0; i < N; i++){
	    if(i > 0) printf(" ");
		    printf("%c%d",x[i].suit,x[i].value);
	}
	printf("\n");
	printf("Stable\n");
	
 /* selection */
	for(i = 0; i < N; i++){
		min = i;
		for( j = i; j < N; j++ ){
			if( y[j].value < y[min].value){
			min = j;
			}
		}
		k = y[i];
		y[i] = y[min];
		y[min] = k;
	}

	
	for(i = 0; i < N; i++){
		if(i > 0) printf(" ");
		printf("%c%d",y[i].suit,y[i].value);
	}
	printf("\n");
	
	s = 1;
	
	for(i = 0; i < N; i++){
		if(x[i].suit != y[i].suit){
		s = 0;
	    }
	}	
	
	if(s == 0){
		printf("Not stable\n");
	}else{
		printf("Stable\n");
	}
  return 0;
}