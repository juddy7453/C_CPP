# include <stdio.h>
# include <stdlib.h>

void quick(int** arr, int left, int right) {
	int pivot_index = (left + right) / 2;
	int pivot = (*arr)[pivot_index];

	int i = left;
	int j = right;
	int tmp;
	int value;

	while ((*arr)[i] != pivot && (*arr)[j] != pivot) {
		if ((*arr)[i] > pivot && (*arr)[j] < pivot) { // *l과 *r 둘 다 변경해야 하는 상황
			tmp = (*arr)[i];
			(*arr)[i] = (*arr)[j];
			(*arr)[j] = tmp;

			i++; j--;
		}
		else if ((*arr)[i] > pivot && (*arr)[j] > pivot) { // *l만 변경해야 하는 상황
			value = (*arr)[i];
			for (int k = i; k < pivot_index; k++)
				(*arr)[k] = (*arr)[k + 1];
			(*arr)[pivot_index--] = value;

			j--;
		}
		else if ((*arr)[i] < pivot && (*arr)[j] < pivot) { // *r만 변경해야 하는 상황
			value = (*arr)[j];
			for (int k = j; k > pivot_index; k--)
				(*arr)[k] = (*arr)[k - 1];
			(*arr)[pivot_index++] = value;

			i++;
		}
		else {
			i++; j--;
		}
//		printf("###pivot=%d#######\n", pivot);
//		for (int t = left; t < right + 1; t++)
//			printf("%d\n", (*arr)[t]);
//		printf("##########\n");

	}
	while ((*arr)[i] != pivot && (*arr)[j] == pivot) {
//		printf("$$ while l$$\n"); 
		if ((*arr)[i] > pivot) { // *l을 변경해야 하는 상황
			value = (*arr)[i];
//			printf("(*arr)[i]=(*arr)[%d]=%d\n", i, value);

			for (int k = i; k < pivot_index; k++)
				(*arr)[k] = (*arr)[k + 1];
			(*arr)[pivot_index--] = value;
			j--;
		}
		else {
			i++;
			if (i > right)
				break;
		}
		
	}
	while ((*arr)[i] == pivot && (*arr)[j] != pivot) {
//		printf("$$ while r$$\n");
		if ((*arr)[j] < pivot) { // *r을 변경해야 하는 상황
			value = (*arr)[j];
//			printf("(*arr)[j]=(*arr)[%d]=%d\n", j, value);

			for (int k = j; k > pivot_index; k--)
				(*arr)[k] = (*arr)[k - 1];
			(*arr)[pivot_index++] = value;
			i++;
		}
		else {
			j--;
			if (j < left)
				break;
		}
	}
	

	if (left < right) {
		quick(arr, left, pivot_index);
		quick(arr, pivot_index + 1, right);
	}
	else
		return;
	
}

void quick_sort(int** arr, int left, int right) {
	int pivot_index = (left + right) / 2;


}

int main(void) {
	int n;

	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	quick(&arr, 0, n - 1);

	for (int t = 0; t < n; t++)
		printf("%d\n", arr[t]);

	return 0;
}