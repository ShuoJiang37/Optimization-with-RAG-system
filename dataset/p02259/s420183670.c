#include<stdio.h>
#define N n
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n>=1&&n<=100)
    {
        int data[N];
        int i,j,k,temp,s=0;
        for(i=0;i<N;i++) {
        scanf("%d",&data[i]);
    }
    for(j=0;j<N-1;j++) {
        for(i=0;i<N-j-1;i++) {
            if(data[i]>data[i+1]) {
                temp = data[i];
                data[i] = data[i+1];
                data[i+1] = temp;
                s++;
            }
        }
    }
    for(k=0;k<N-1;k++) {
        printf("%d ", data[k]);
    }
    printf("%d", data[N-1]);
    printf("\n");
    printf("%d\n",s);
    }

}
