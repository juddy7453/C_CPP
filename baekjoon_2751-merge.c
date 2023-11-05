# include <stdio.h>
# include <stdlib.h>

void merge(int** arr, int** result, int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left; // result¿« ¿Œµ¶Ω∫

	while (i <= mid && j <= right) {
		if ((*arr)[i] < (*arr)[j])
			(*result)[k++] = (*arr)[i++];
		else
			(*result)[k++] = (*arr)[j++];
	}

	if (i > mid) {
		for (int t = j; t <= right; t++)
			(*result)[k++] = (*arr)[t];
	}
	else if (j > right) {
		for (int t = i; t <= mid; t++)
			(*result)[k++] = (*arr)[t];
	}

	for (int t = left; t <= right; t++)
		(*arr)[t] = (*result)[t];
}

void merge_sort(int** arr, int** result, int left, int right) {
	int mid = (left + right) / 2;

	if (left < right) {
		merge_sort(arr, result, left, mid);
		merge_sort(arr, result, mid + 1, right);
		merge(arr, result, left, mid, right);
	}
}

int main(void) {
	int n;

	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);



	int* result = (int*)malloc(sizeof(int) * n);
	
	if (n == 1) {
		printf("%d\n", arr[0]);
		return 0;
	}

	merge_sort(&arr, &result, 0, n - 1);

	for (int k = 0; k < n; k++)
		printf("%d\n", result[k]);




	return 0;
}