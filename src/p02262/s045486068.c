//============================================================================
// 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//============================================================================
typedef struct{
    char suit;
    int  value;
    int  order;
}TCard;
//============================================================================
void dump(int *A, int N)
{
    int i;

    for (i=0; i<N; i++){
        if (i)
            printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}
//============================================================================
int insertionSort(int *A, int N, int G) // N??????????´??????????0-?????????????????????A
{
    int i,j,v,cnt;

    //printf("start sorting\n");
    for(cnt=0, i=G; i<N; i++){// ??? 1 ?????? N-1 ?????§
        v = A[i];
        j = i - G;
        while(j >= 0 && A[j] > v){
            A[j+G] = A[j];
            j-=G;
            cnt++;
        }
        A[j+G] = v;
        //dump(A, N);
    }
    //printf("end of sort\n");
    return cnt;
}
//----------------------------------------------------------------------------
void shellSort(int *A, int n)
{
    int i,j,m,cnt,*G;

    for (cnt=1, m=0; cnt<=n; cnt=3*cnt+1, m++);
     //printf("%d",cnt);
    G = malloc(m*sizeof(int));
    for (i=0, j=m-1, cnt=1; i<m; i++, j--, cnt=3*cnt+1)
        G[j]=cnt;
    for (i=cnt=0; i<m; i++)
        cnt+=insertionSort(A, n, G[i]);
    printf("%d\n", m);
    dump(G, m);
    printf("%d\n", cnt);
    for (i=0; i<n; i++)
        printf("%d\n", A[i]);
    free(G);
}
//============================================================================
int BubbleSort(TCard *ary, int n)
{
    int i,j,k,l, cnt; TCard chg;

    for (k=cnt=0, l=n; k<n-1; k++, l--)
    for (i=0,j=1; j<l; i++, j++){
        if (ary[j].value<ary[i].value)
            chg=ary[i], ary[i]=ary[j], ary[j]=chg, cnt++;
	}
    return cnt;
}
//============================================================================
int SelectionSort(TCard *ary, int n)
{
    int i,j,minj,cnt; TCard chg;

    for (i=cnt=0; i<n; i++){
        for (j=minj=i; j<n; j++){
            if (ary[j].value<ary[minj].value)
                minj=j;
        }
        if (i!=minj)
            chg=ary[i], ary[i]=ary[minj], ary[minj]=chg, cnt++;
    }
    return cnt;
}
//============================================================================
void selectionsort()
{
    int i,cnt, n; TCard *ary;

    scanf("%d", &n);
    ary=malloc(n*sizeof(TCard));
    for (i=0; i<n; i++)
        scanf("%d", &ary[i].value);
    cnt=SelectionSort(ary, n);
    for (i=0; i<n; i++){
        if (i) printf(" ");
        printf("%d", ary[i].value);
    }
    printf("\n%d\n", cnt);
    free(ary);
}
//============================================================================
void prnval(TCard *ary, int n)
{
    int i,nstb;

    for (i=nstb=0; i<n; i++){
        if (i) printf(" ");
        printf("%c%d", ary[i].suit, ary[i].value);
        if (i<n-1)
        if (ary[i].value==ary[i+1].value && ary[i+1].order<ary[i].order)
                nstb++;
    }
    printf("\n%s\n", (nstb)?"Not stable":"Stable");
}
//============================================================================
void cardsort()
{
    int i,cnt,nstb,n; TCard *bary, *sary; char sub[10];

    scanf("%d", &n);
    bary=malloc(n*sizeof(TCard));
    sary=malloc(n*sizeof(TCard));
    for (i=0; i<n; i++){
        scanf("%s", sub);
        //scanf("%c%d", &bary[i].suit, &bary[i].value);
        bary[i].suit=*sub;
        bary[i].value=sub[1]-'0';
        bary[i].order=i;
    }
    memcpy(sary, bary, sizeof(TCard)*n);
    cnt=BubbleSort(bary, n);
    prnval(bary, n);
    cnt=SelectionSort(sary, n);
    prnval(sary, n);
    free(sary);
    free(bary);
}
//============================================================================
void shellsort()
{
    int i,n,*ary;

    scanf("%d", &n);
    ary=malloc(n*sizeof(int));
    for (i=0; i<n; i++)
        scanf("%d", &ary[i]);
    shellSort(ary, n);
    free(ary);
}
//============================================================================
int main(void)
{
    //selectionsort();
    //cardsort();
    shellsort();
    return 0;
}
//============================================================================