#include <stdio.h>

int insertionSort(int *A, int n, int g);
void shellSort(int *A, int n);

int main()
{
    int i,n;
    scanf("%d%*c",&n);
    int *A;
    A = malloc(n*sizeof(int));
    for (i=0;i<n;i++)
    {
        scanf("%d%*c",&A[i]);
    }
    shellSort(A,n);
    for (i=0;i<n;i++)
    {
        printf("%d\n",A[i]);
    }


    return 0;
}

int insertionSort(int *A, int n, int g)
{
    int i,j,tmp,cnt=0;
    for(i=g;i<n;i++)
    {
        tmp = A[i];
        j = i-g;
        while (j>=0 && A[j]>tmp)
        {
            A[j+g] = A[j];
            j = j-g;
            cnt++;
        }
        A[j+g] = tmp;
    }
    return cnt;
}

void shellSort(int *A,int n)
{
    int ans[102] = {1};
    int i,j,m=1,cnt=0;
    int h=1;
    for (i=0;i<((int)(n*0.333333)+1);i++)
    {
        h = 3*h+1; // h=1,4,13,40,121,364...
        if (h<=n && m<100)
        {
            ans[m] = h;
            m+=1;
        }
        else break;
    }
    printf("%d\n",m);
    int *G;
    G = malloc((m)*sizeof(int));
    for (i=0;i<m;i++)
    {
        G[i] = ans[m-1-i];
        printf("%d",G[i]);
        if (i<m-1) printf(" ");
    }
    printf("\n");
    for (i=0;i<m;i++)
    {
        cnt += insertionSort(A,n,G[i]);
    }
    printf("%d\n",cnt);
    free(G);
    return; //G 넣은뒤 m,cnt넣어놓기.
}
