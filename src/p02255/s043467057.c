#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#define N_MIN       (1)
#define N_MAX       (100)
#define A_MIN       (0)
#define A_MAX       (1000)
#define A_MAX_DIGIT (4)
#define N_ARRAY     (N_MAX * A_MAX_DIGIT + 1)

char *getsn(char *s, int n);
void insertionSort(int *, int N);
void printArray(int *, int N);

int main(void)
{
    char str[N_ARRAY];
    int  A[N_MAX], i, j, length1;
    int  flag    = 0;
    int  length2 = 0;

    /* input line 1 */
    if(getsn(str, 4) == NULL)
    {
        printf("Err: input line 1 is invalid.");
        return -1;
    }

    if((atoi(&str[0]) < N_MIN) || (N_MAX < atoi(&str[0])))
    {
        printf("Err: %d is out of range.", atoi(&str[0]));
        return -1;
    }
    length1 = atoi(&str[0]);

    /* input line 2 */
    if(getsn(str, length1 * A_MAX_DIGIT + length1) == NULL)
    {
        printf("Err: input line 2 is invalid.");
        return -1;
    }

    /* get N elements */
    j = strlen(str);
    for(i=0; i<j; i++)
    {
        if(str[i] == ' ')
        {
            flag = 0;
        }
        else
        {
            if(flag == 0)
            {
                A[length2] = atoi(&str[i]);
                if((A[length2] < A_MIN) || (A_MAX < A[length2]))
                {
                    printf("Err: %d is out of range.", A[length2]);
                    return -1;
                }
                length2++;
                flag = 1;
            }
        }
    }

    /* check the number of elements between line 1 and 2 */
    if(length1 != length2)
    {
        printf("Err: line 1 and 2 are inconsistent.");
        return -1;
    }

    /* exec insertionSort */
    insertionSort(A, length2);

    return 0;
}

char *getsn(char *s, int n)
{
    char *ln;

    if(fgets(s, n, stdin) == NULL)
    {
        return NULL;
    }

    ln = strchr(s, '\n');
    if(ln)
    {
        *ln = '\0';
    }
    else
    {
        while(1)
        {
            int c = getchar();
            if (c == '\n' || c == EOF) break;
        }
    }
    return s;
}

void insertionSort(int A[], int N)
{
    int  i, j, v;

    printArray(A, N);

    for(i=1; i<N; i++)
    {
        v = A[i];
        j = i - 1;
        while((j>=0) && (A[j] > v))
        {
            A[j+1] = A[j];
            j--;

        }
        A[j+1] = v;
        printArray(A, N);
    }
}

void printArray(int A[], int N)
{
    int i;

    for(i=0; i<N-1; i++)
    {
        printf("%d ", A[i]);
    }
    printf("%d\n", A[N-1]);
}