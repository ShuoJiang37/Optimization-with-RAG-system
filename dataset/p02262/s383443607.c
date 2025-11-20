#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SWAP(x, y) {int z; z = x; x = y; y = z;}

void dispNumsLn(int *nums, int length) 
{
    int i;

    for(i = 0; i < length; i++) {
        printf("%d\n", nums[i]);
    }
}

void reverseArray(int *array, int length) 
{
    int head, tail;

    for(head = 0, tail = length - 1;
            head < tail;
            head++, tail--) {
        SWAP(array[head], array[tail]);
    }
}

int *supplyGArray(int n, int *interval_length)
{
    int i, j, length = n, GValue = 1;
    int *array, *tmp_array;

    array = malloc(sizeof(int) * length);
    array[0] = GValue;
    for(i = 1, length = i + 1, GValue = 3 * GValue + 1; 
            GValue < n; 
            GValue = GValue * 3 + 1, i++, length = i + 1) {
        tmp_array = malloc(sizeof(int) * length);
        memcpy(tmp_array, array, (length - 1)*sizeof(int));
        tmp_array[i] = GValue;
        free(array);
        array = malloc(sizeof(int) * length);
        memcpy(array, tmp_array, (length)*sizeof(int));
        free(tmp_array);
    }
    length--;
    *interval_length = length;
    reverseArray(array, length);
    return array;
}

int insertionSort(int *nums, int length, int interval) 
{
    int i, j, target, cnt = 0;

    for(i = interval; i < length; i++) {
        j = i - interval;
        target = nums[i];

        while(j >= 0 && nums[j] > target) {
            nums[j + interval] = nums[j];
            j -= interval;
            cnt++;
        }
        nums[j + interval] = target;
    }
    return cnt;
}

int shellSort(int *nums, int length)
{
    int i, cnt = 0, interval_length;
    int *intervals;

    intervals = supplyGArray(length, &interval_length);

    printf("%d\n", interval_length);
    for(i = 0; i < interval_length; i++) {
        printf("%d ", intervals[i]);
        cnt += insertionSort(nums, length, intervals[i]);
    }
    printf("\n");

    return cnt;
}

int main(void) 
{
    int n, i, cnt;
    int *nums;

    scanf("%d", &n);
    nums = malloc(sizeof(int) * n);
    for(i = 0; i < n; i++) {
        scanf("%d", nums + i);
    }
    cnt = shellSort(nums, n);	
    printf("%d\n", cnt);
    dispNumsLn(nums, n);

    return 0;
}