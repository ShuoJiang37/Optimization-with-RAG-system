#include <stdio.h>
#include <memory.h>

typedef struct _element {
	int index;
	int val;
	char c;
} element;

int is_stable(element lst[], int n) {
	int i;
	element last;

	memcpy((char*)&last, (char*)&lst[0], sizeof(element));
	for(i=1;i<n;i++) {
		if(last.val == lst[i].val) {
			if(last.index > lst[i].index) {
				return 0;
			}
		}
		memcpy((char*)&last, (char*)&lst[i], sizeof(element));
	}
	
	return 1;
}

int bubble_sort(element lst[], int n) {
	int i, j;
	element tmp;
	for(i=0;i<n-1;i++) {
		for(j=n-1;j>i;j--) {
			if(lst[j-1].val > lst[j].val) {
				memcpy((char*)&tmp,(char*)&lst[j],sizeof(element));
				memcpy((char*)&lst[j],(char*)&lst[j-1],sizeof(element));
				memcpy((char*)&lst[j-1],(char*)&tmp,sizeof(element));
			}
		}
	}
	
	return is_stable(lst, n);
}

int selection_sort(element lst[], int n) {
	int i, j, index;
	element tmp;
	for(i=0;i<n-1;i++) {
		index = i;
		for(j=i+1;j<n;j++) {
			if(lst[j].val < lst[index].val) {
				index = j;
			}
		}
		
		if(index != i) {
			memcpy((char*)&tmp,(char*)&lst[i],sizeof(element));
			memcpy((char*)&lst[i],(char*)&lst[index],sizeof(element));
			memcpy((char*)&lst[index],(char*)&tmp,sizeof(element));
		}
	}
	
	return is_stable(lst, n);
}

int main(void) {
	int i, val, n;
	int stable;
	element lst[36];
	element b_lst[36];
	element s_lst[36];
	
	scanf("%d\n", &n);
	for(i=0;i<n;i++) {
		lst[i].index = i;
		scanf("%c%d ", &(lst[i].c), &(lst[i].val));
	}
	memcpy((char*)b_lst, (char*)lst, sizeof(lst));
	memcpy((char*)s_lst, (char*)lst, sizeof(lst));
	
	stable = bubble_sort(b_lst, n);
	for(i=0;i<n;i++) {
		printf("%c%d", b_lst[i].c, b_lst[i].val);
		if(i<n-1) {
			printf(" ");
		} else {
			printf("\n");
		}
	}
	if(stable == 1) {
		printf("Stable\n");
	} else {
		printf("Not stable\n");
	}
	
	stable = selection_sort(s_lst, n);
	for(i=0;i<n;i++) {
		printf("%c%d", s_lst[i].c, s_lst[i].val);
		if(i<n-1) {
			printf(" ");
		} else {
			printf("\n");
		}
	}
	if(stable == 1) {
		printf("Stable\n");
	} else {
		printf("Not stable\n");
	}
	
	return 0;
}