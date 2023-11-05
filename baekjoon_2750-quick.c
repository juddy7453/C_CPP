# include <stdio.h>
# include <stdlib.h>

int partition(int** arr, int left, int right) {
	int pivot_index = (left + right) / 2;
	int pivot = (*arr)[pivot_index];

	int i = left;
	int j = right;
	int tmp;

	while (i < j) {
		while ((*arr)[i] < pivot)
			i++;
		while ((*arr)[j] > pivot)
			j--;
		//printf("****while*****\n");
		//printf("arr[i]=arr[%d]=%d\n", i, (*arr)[i]);
		//printf("arr[j]=arr[%d]=%d\n", j, (*arr)[j]);
		//for (int t = 0; t < right+1; t++)
		//	printf("%d\n", (*arr)[t]);

		if ((*arr)[i] > pivot && (*arr)[j] < pivot) {
			tmp = (*arr)[j];
			(*arr)[j] = (*arr)[i];
			(*arr)[i] = tmp;
			i++; j--;
		}
		else if ((*arr)[i] == pivot && (*arr)[j] < pivot) {
			tmp = (*arr)[j];
			(*arr)[j] = (*arr)[i];
			(*arr)[i] = tmp;
			pivot_index = j; // j 위치에 pivot이 있게 됨
			i++;
		}
		else if ((*arr)[i] > pivot && (*arr)[j] == pivot) {
			tmp = (*arr)[j];
			(*arr)[j] = (*arr)[i];
			(*arr)[i] = tmp;
			pivot_index = i; // i 위치에 pivot이 있게 됨
			j--;
		}
		//printf("   |   \n");
		//printf("   v   \n");
		//printf("arr[i]=arr[%d]=%d\n", i, (*arr)[i]);
		//printf("arr[j]=arr[%d]=%d\n", j, (*arr)[j]);
		//for (int t = 0; t < right + 1; t++)
		//	printf("%d\n", (*arr)[t]);
		//printf("*********\n");

	}
	return pivot_index;
}

void quick_sort(int** arr, int left, int right) {
	if (left < right) {
		int q = partition(arr, left, right);
		quick_sort(arr, left, q - 1);
		quick_sort(arr, q + 1, right);
	}
}

int main(void) {
	int n;

	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	quick_sort(&arr, 0, n - 1);

	for (int t = 0; t < n; t++)
		printf("%d\n", arr[t]);

	return 0;
}