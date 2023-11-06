# include <stdio.h>
# include <stdlib.h>

typedef struct {
	int key;
	int index;
}element;

void insertion(element** heap, int value, int point) {
	int p = point;
	if ((*heap)[point / 2].key > value) {
		while ((*heap)[p / 2].key > value) { // node끼리 교환이 이루어져야 할 경우
			(*heap)[p].key = (*heap)[p / 2].key;
			(*heap)[p / 2].key = value;
			p /= 2;
		}
	}
	else
	 (*heap)[point].key = value;

	(*heap)[point].index = point;
//	printf("%d\n", (*heap)[point].key);
}

void deletion(element** heap, int last) {
	int point = last + 1; // heap의 마지막 요소의 index
	printf("%d\n", (*heap)[1].key);

	int value = (*heap)[point].key;

	(*heap)[1].key = value;

	int i = 1;
	while (2* i < point) {
		if ((*heap)[2 * i].key < (*heap)[2 * i + 1].key) {
			if ((*heap)[i].key > (*heap)[2 * i].key) {
				(*heap)[i].key = (*heap)[2 * i].key;
				(*heap)[2 * i].key = value;
			}
			else
				break;
			i *= 2;
		}
		else {
			if ((*heap)[i].key > (*heap)[2 * i + 1].key) {
				(*heap)[i].key = (*heap)[2 * i + 1].key;
				(*heap)[2 * i + 1].key = value;
			}
			else
				break;
			i = i*2 +1;
		}
	}
	if (point == 2)
		printf("%d\n", (*heap)[1].key);

}

int main(void) {
	int n;

	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	element* heap = (element*)malloc(sizeof(element) * (n + 1));

	element node;
	node.index = 1;
	node.key = arr[0];

	heap[1] = node;

	for (int i = 1; i < n; i++) // heap 완성
		insertion(&heap, arr[i], i + 1);

//	for (int i = 1; i < n+1; i++)
//		printf("%d\n", heap[i]);
	for (int i = 1; i < n; i++)
		deletion(&heap, n-i);

//	printf("%d\n", heap[1].key);
//	printf("%d\n", heap[2].key);

	return 0;
}
