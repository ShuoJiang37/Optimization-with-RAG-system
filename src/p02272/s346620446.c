#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trace(int A[], int n){
  int i;
  for ( i = 0; i < n; i++ ){
    if ( i > 0 ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

int count = 0;

void doMS(int A[], int head, int len)
{
    if (len < 2)
        return;
    int toplen = len / 2;
    int botlen = len - toplen;
    int tophead = head;
    int bothead = tophead + toplen;
    doMS(A, tophead, toplen);
    doMS(A, bothead, botlen);
    // merge top and bottom
    int res[len];
    int i = tophead;
    int j = bothead;
    int res_i = 0;
    while (i < tophead + toplen || j < bothead + botlen)
    {
        if (i >= tophead + toplen)
        {
            memcpy(res + res_i, A + j, sizeof(int) * (bothead + botlen - j));
            count += bothead + botlen - j;
            break;
        }
        if (j >= bothead + botlen)
        {
            memcpy(res + res_i, A + i, sizeof(int) * (tophead + toplen - i));
            count += tophead + toplen - i;
            break;
        }
        res[res_i++] = A[i] > A[j] ? A[j++] : A[i++];
        count++;
    }
    memcpy(A + head, res, sizeof(int) * len);
}

void heapify(int *A, int root, int end)
{
    int i = root;
    int temp = 0;
    while(i * 2 + 1 <= end)
    {
        int c = i * 2 + 1;
        if (c + 1 <= end && A[c + 1] > A[c])
            c++;
        if(A[c] > A[i])
        {
            temp = A[i];
            A[i] = A[c];
            A[c] = temp;
        }
        else
            break;
        i = c;
    }
}


void doHS(int *A, int n)
{
    for(int i = n / 2; i >= 0; i--)
    {
        heapify(A, i, n - 1);
    }
    
    for(int i = n - 1; i > 0 ; i--)
    {
        int temp = A[i];
        A[i] = A[0];
        A[0] = temp;
        heapify(A, 0, i - 1);
    }
}


int main(){
    int n, i, j, key, temp;
    int *A, *B;
    //extern count;
    scanf("%d", &n);
    A = malloc(sizeof(int) * n);
    B = malloc(sizeof(int) * n);

    for ( i = 0; i < n; i++ ) scanf("%d", &A[i]);
    memcpy(B, A, sizeof(int) * n);
    
    doMS(A, 0, n);
    
    doHS(B, n);
    trace(B, n);
    printf("%d\n", count);

    return 0;
}




/* 
8 5 9 2 6 3 7 1 10 4
*/