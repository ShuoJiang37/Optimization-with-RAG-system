#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define mymalloc(p,n) {p=malloc((n)*sizeof(*p));if((p)==NULL){printf("not enough memory\n");exit(1);};}

void print_array(int N, int *array){
    int i;
    for(i=0;i<N;i++){
        printf("%d", array[i]);
        if(i<N-1){printf(" ");}
    }
    printf("\n");
}
void printLn_array(int N, int *array){
    int i;
    for(i=0;i<N;i++){
        printf("%d\n", array[i]);
    }
}

int *readArray(int *num){
	int i,j;
	int *A;
	scanf("%d", num);
	mymalloc(A,*num);
	for(i=0;i<*num;i++){
		scanf("%d",&j);
		A[i]=j;
	}
	return A;
}

void insertSort(int N, int *array, int g, int *cnt){
    int i,j,key;
    for(i=g;i<N;i++){
        key=array[i];
        j=i-g;
        while(j>=0 && array[j]>key){
            array[j+g]=array[j];
            j-=g;
            (*cnt)++;
        }
        array[j+g]=key;
    }
}

	
main(){
    int i,j,n,cnt,m;
    int *A;
    int *G;
    cnt=0;
    A=readArray(&n);
    m=(int)(log(2*n+1)/log(3));
    mymalloc(G,m);
		for(i=0;i<m;i++){
			G[i]=0.5*(pow(3,m-i)-1);
		}
		for(i=0;i<m;i++){
			insertSort(n,A,G[i],&cnt);
		}
		printf("%d\n",m);
		print_array(m,G);
		printf("%d\n",cnt);
		printLn_array(n,A);
    return 0;
}