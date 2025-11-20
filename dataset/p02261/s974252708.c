#include <stdio.h>
 
struct card {
    char num1;
    int num2;
};
 
void def1(struct card *, struct card *);

void def2(int, struct card *);
 
#define N 36 
int main(void)
{
  int i, j; 
int minj, n, flag;

    struct card array1[N], array2[N];
     
    scanf("%d",&n);
    
for (i = 0; i < n; i++) {

        scanf(" %c%d", &array1[i].num1, &array1[i].num2);

        array2[i] = array1[i];
    }
     
    for (i = 0; i < n; i++) {
        for (j = n - 1; j > i; j--) {
            if ( array1[j].num2 < array1[j-1].num2 ) 
	      def1( &array1[j] , &array1[j-1] );
        }
    }
     
    for (i = 0; i < n; i++) {
        minj = i;
        for (j = i; j < n; j++) {
            if( array2[j].num2 < array2[minj].num2 )
	      minj = j;
        }
        if(i != minj) def1( &array2[i], &array2[minj]);
    }
    flag = 1;
    for (i = 0; i < n; i++) {
        if( array1[i].num1 != array2[i].num1 ) {
            flag = 0;
            break;
        }
    }
     
    def2(n, array1);

    printf("Stable\n");

    def2(n, array2);

    if(flag){ 
      printf("Stable\n");
    }else{
      printf("Not stable\n");
    }     
    return 0;
}
 
void def1(struct card *card1, struct card *card2)
{
  struct card temp;
  temp = *card1;
  *card1 = *card2;
    *card2 = temp;
}
 
void def2(int n, struct card *C)
{
    int i;
    for (i = 0; i < n - 1; i++) {
        printf("%c%d ", C[i].num1, C[i].num2);
    }
    printf("%c%d\n", C[n-1].num1, C[n-1].num2);
}