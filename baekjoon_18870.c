# include <stdio.h>
# include <stdlib.h>

typedef struct s {
	int value;
	int original_index;
}Element;

int compare(const void* a, const void* b) {
	Element *ae = (Element*)a;
	Element* be = (Element*)b;

	if (ae->value > be->value)
		return 1;
	else
		return -1;
}

int main(void) {
	int n;
	scanf("%d", &n);

	Element* arr = (Element*)malloc(sizeof(Element) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i].value);
		arr[i].original_index = i;
	}

	if (n == 1) {
		printf("0");
		return 0;
	}

	qsort(arr, n, sizeof(Element), compare);

	int* count_arr = (int*)malloc(sizeof(int) * n);
	int tmp = 0;
//	int count = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i].value == arr[i - 1].value) {
			tmp++;
		}
		
		count_arr[arr[i].original_index] = i - tmp;

		if (i == 1)
			count_arr[arr[0].original_index] = 0;
	}

	for (int i = 0; i < n; i++)
		printf("%d ", count_arr[i]);

	return 0;
}