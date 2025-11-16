#include<stdio.h>
#include<stdlib.h>

void insertionsort(int *,int,int);
void shellsort(int *,int);

int cnt=0;

int main(){

    int i,n;
    int *a;

    scanf("%d",&n);

    a=(int *)malloc(sizeof(int)*n);
    if(a==NULL) exit(8);

    for(i=0;i<n;i++) scanf("%d",&a[i]);

    shellsort(a,n);

    free(a);
    return 0;
}

void insertionsort(int *a,int n,int g){

    int i,j,v;

    for(i=g;i<n;i++){

        v=a[i];

        j=i-g;

        while(j>=0&&a[j]>v){

            a[j+g]=a[j];

            j=j-g;

            cnt++;

        }a[j+g]=v;

    }return;

}

void shellsort(int *a,int n){

    int i,m,x=1,*g;

    for(m=1;m<100;m++){

        if(n<3*x+1) break;

        x=3*x+1;

    }g=(int *)malloc(sizeof(int)*m);

    for(i=0,x=1;i<m;i++){

        g[i]=x;
        
        x=x*3+1;

    }

    for(i=m-1;i>=0;i--) insertionsort(a,n,g[i]);

    printf("%d\n",m);

    for(i=m-1;i>=0;i--){

        if(i==m-1) printf("%d",g[i]);

        else printf(" %d",g[i]);

    }printf("\n");

    printf("%d\n",cnt);

    for(i=0;i<n;i++) printf("%d\n",a[i]);

    free(g);

    return;
}
