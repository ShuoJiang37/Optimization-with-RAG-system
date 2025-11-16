#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//============================================================================
#define pred(x) ((x)-1)
#define succ(x) ((x)+1)
//============================================================================
typedef unsigned char  INT8U;
typedef unsigned short INT16U;
typedef   signed short INT16S;
typedef long INT32;
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
INT16U *C;
//----------------------------------------------------------------------------
void CountingSort(INT16U *A, INT16U *B,  INT16U n, INT16U k)
{
    long i;

    for (i = 0; i<n; i++)
        C[A[i]]++;
    for (i = 1; i<=k; i++)
        C[i] += C[i-1];
    // C holds position of A
    // C[A[val]] = pred val position

    /*for (i = 1; i<=k; i++)
        printf("%d ", C[i]);
    printf("\n");*/
    /*printf("B[C[A[i]]-1] = A[i];\n");
    for (i=n-1; 0<=i; i--){
        //B[C[A[i]]-1] = A[i];
        printf("B[%d]=%d C[%d]=%d A[%d]=%d\n", C[A[i]]-1, A[i],
                            A[i], C[A[i]], i, A[i]);
        //C[A[i]]--;
    }*/
}
//----------------------------------------------------------------------------
INT16S getminptr(INT16U *A, INT16U N)
{
    INT16U i,min; INT16S ptr;

    for (i=0, ptr=-1, min=32767; i<N; i++){
        if (A[i]<min && pred(C[A[i]])!=i){
            min=A[i];
            ptr=i;
        }
    }
    return ptr;
}
//----------------------------------------------------------------------------
long SumValue;
void exchange(INT16U *x, INT16U *y)
{
    INT16U z;

    z=*x, *x=*y, *y=z;
    SumValue+=*x;
    SumValue+=*y;
    //printf("ex: %d<-->%d, sum:%ld\n", *y, *x, sum);
}
//----------------------------------------------------------------------------
void prnary(INT16U *A, INT16U N)
{
    int j;

    for (j=0; j<N; j++)
        printf("%2d ", A[j]);
    printf(" sum:%ld\n", SumValue);
}
//----------------------------------------------------------------------------
short linklen(INT16U *A, INT16U val)
{
    int idx,n;

    for (n=0, idx=val; ; n++){
        idx=A[pred(C[idx])];
        if (idx==val)
            return n;
    }
}
//----------------------------------------------------------------------------
short bgnlink(INT16U *A, INT16U val)
{
    int sum,idx,start;

    for (start=idx=val; ; ){
        idx=A[pred(C[idx])];
        if (idx<start)
            start=idx;
        if (idx==val)
            return start;
    }
}
//----------------------------------------------------------------------------
long revcost(INT16U *A, INT16U val)
{
    int sum,idx,start;

    val=bgnlink(A, val);
    for (sum=0, idx=val; ; ){
        idx=A[pred(C[idx])];
        if (idx==val)
            return sum;
        sum+=(idx+val);
    }
}
//----------------------------------------------------------------------------
long exccost(INT16U *A, INT16U val, INT16U min)
{
    int sum,idx,porn;

    if (val!=min)
        sum=val+min;
    else
        sum=0;
    for (porn=min, idx=val; ; ){
        idx=A[pred(C[idx])];
        sum+=(idx+porn);
        if (idx==val)
            return sum;
    }
}
//----------------------------------------------------------------------------
void duplication(INT16U *A, INT16U N)
{
    int i,j,k,n,a,ary[3];

#ifdef DESKTOP
    prnary(A, N);
#endif
    for (i=SumValue=0; i<pred(N); i++){
        n=linklen(A, A[i]);
        if (n==1){
            j=pred(C[A[i]]);
            exchange(&A[i], &A[j]);
            //printf("ex:(%d<->%d), ", A[i], A[j]);
        }
#ifdef DESKTOP
    }
    printf("\n");
#else
    }
#endif
}
//----------------------------------------------------------------------------
long mincostsort(INT16U *A, INT16U N)
{
    int ptr,i,j,min,ordptr,order[100];

    duplication(A, N);
    for (i=0,j=32000; i<N; i++)
        if (A[i]<j)
            j=A[i],min=i;
    for (ordptr=0; 0<=(ptr=getminptr(A, N));){
#ifdef DESKTOP
    printf("[%d]\n", A[ptr]);
        //order[ordptr++]=A[ptr];
#endif
        //if (A[min]*2<A[ptr]){
        if (exccost(A, A[ptr], A[min])<revcost(A, A[ptr])){
            exchange(&A[min], &A[ptr]);
            min=ptr;
        }
        while (pred(C[A[ptr]])!=ptr){
            for (i=0; i<N; i++)
                if (C[A[i]]==succ(ptr)){
                    order[ordptr++]=A[i];
                    if (ptr==min) min=i;
                    exchange(&A[ptr], &A[i]);
                    ptr=i;
#ifdef DESKTOP
                    //prnary(A, N);
#endif
                    break;
                }
        }
    }
#ifdef DESKTOP
    /*for (i=0; i<ordptr; i++){
        if (i) printf("->");
            printf("%d", order[i]);
    }
    printf("\n");*/
#endif
    return SumValue;
}
//----------------------------------------------------------------------------
/*
*                                         *     *
0 62 33 29 72 52 43 19 5  93 51 32  8 11 56 47 66 69 30 17 68  5
0 62 33 29 72 52 43 19 32 93 51  5  8 11 56 47 66 69 30 17 68  5
0 62 33 29 72 52 43 19 32 93 51 47  8 11 56  5 66 69 30 17 68  5
0  5 33 29 72 52 43 19 32 93 51 47  8 11 56 62 66 69 30 17 68  0
0  5 33 29 72 52 43 19 32 93  8 47 51 11 56 62 66 69 30 17 68  8
0  5 33 29 72 52  8 19 32 93 43 47 51 11 56 62 66 69 30 17 68  8
0  5 33  8 72 52 29 19 32 93 43 47 51 11 56 62 66 69 30 17 68  8
0  5 33 11 72 52 29 19 32 93 43 47 51  8 56 62 66 69 30 17 68  8
0  5 33 11 72  8 29 19 32 93 43 47 51 52 56 62 66 69 30 17 68  8
0  5 33 11 72 19 29  8 32 93 43 47 51 52 56 62 66 69 30 17 68  8
0  5 33 11 72 19 29 30 32 93 43 47 51 52 56 62 66 69  8 17 68  8
0  5 33 11 72 19 29 30 32 93 43 47 51 52 56 62 66  8 69 17 68  8
0  5 33 11 72 19 29 30 32 93 43 47 51 52 56 62 66 68 69 17  8  8
0  5 33 11 72 19 29 30 32  8 43 47 51 52 56 62 66 68 69 17 93  8
0  5  8 11 72 19 29 30 32 33 43 47 51 52 56 62 66 68 69 72 93  0
0  5  8 11 17 19 29 30 32 33 43 47 51 52 56 62 66 68 69 17 93  0

 1 80 50 70 40 20
20 80 50 70 40  1
20  1 50 70 40 80
 1 20 50 70 40 80 21        20 40 50 70  1 80   41
40 20 50 70  1 80 41        20 40 50  1 70 80   71
40 20 50  1 70 80 71        20 40  1 50 70 80   51
40 20  1 50 70 80 51        20  1 40 50 70 80   41
 1 20 40 50 70 80 41         1 20 40 50 70 80   21


5
1 5 3 4 2
7

4
4 3 2 1
10
*/
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
void input(FILE *file)
{
    long i,n,max,ave; INT16U *A, *B; char buffer[20];

    fgets(buffer, sizeof(buffer)-1, file);
    sscanf(buffer, "%ld", &n);
    A = malloc(succ(n)*sizeof(INT16U));
    B = malloc(succ(n)*sizeof(INT16U));
    for (i=ave=max=0; i<n; i++){
        fscanf(file, "%hd",  &A[i]);
        if (max<A[i])
            max=A[i];
        ave+=A[i];
    }
    ave/=n;
    C = malloc(succ(max)*sizeof(INT16U));
    memset(C, 0, sizeof(INT16U)*succ(max));
    CountingSort(A, B, n, max);
    printf("%ld\n", mincostsort(A, n));
#ifdef DESKTOP
    for (i=0; i<n; i++){
        if (i) printf(" ");
        printf("%hd", A[i]);
    }
    printf("\n");
#endif
    free(A);
    free(B);
    free(C);
}
//============================================================================
#ifndef DESKTOP
int main()
{
    input(stdin);
    return 0;
}
#endif