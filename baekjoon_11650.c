# include <stdio.h>
# include <stdlib.h>

void merge(int** arrX, int** arrY, int** resultX, int** resultY, int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left; // result¿« ¿Œµ¶Ω∫

	while (i <= mid && j <= right) {
		if ((*arrX)[i] < (*arrX)[j]) {
			(*resultX)[k] = (*arrX)[i];
			(*resultY)[k] = (*arrY)[i];
			k++; i++;
		}
		else {
			(*resultX)[k] = (*arrX)[j];
			(*resultY)[k] = (*arrY)[j];
			k++; j++;
		}
	}

	if (i > mid) {
		for (int t = j; t <= right; t++) {
			(*resultX)[k] = (*arrX)[t];
			(*resultY)[k] = (*arrY)[t];
			k++;
		}
	}
	else if (j > right) {
		for (int t = i; t <= mid; t++) {
			(*resultX)[k] = (*arrX)[t];
			(*resultY)[k] = (*arrY)[t];
			k++;
		}
	}

	for (int t = left; t <= right; t++) {
		(*arrX)[t] = (*resultX)[t];
		(*arrY)[t] = (*resultY)[t];
	}
}

void merge_sort(int** arrX, int** arrY, int** resultX, int** resultY, int left, int right) {
	int mid = (left + right) / 2;

	if (left < right) {
		merge_sort(arrX, arrY, resultX, resultY, left, mid);
		merge_sort(arrX, arrY, resultX, resultY, mid + 1, right);
		merge(arrX, arrY, resultX, resultY, left, mid, right);
	}
}

void merge_single(int** arr, int** result, int left, int mid, int right) {
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

void merge_sort_single(int** arr, int** result, int left, int right) {
	int mid = (left + right) / 2;

	if (left < right) {
		merge_sort_single(arr, result, left, mid);
		merge_sort_single(arr, result, mid + 1, right);
		merge_single(arr, result, left, mid, right);
	}
}

int main(void) {
	int n;
	scanf("%d", &n);

	int* arrX = (int*)malloc(sizeof(int) * n);
	int* arrY = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		scanf("%d %d", &arrX[i], &arrY[i]);

	if (n == 1) {
		printf("%d %d\n", arrX[0], arrY[0]);
		return 0;
	}

	int* rX = (int*)malloc(sizeof(int) * n);
	int* rY = (int*)malloc(sizeof(int) * n);

	merge_sort(&arrX, &arrY, &rX, &rY, 0, n - 1);

	int t = 0;
	int k;
	int length;
	int l = 0;
	while (t < n) {
		for (int i = n - 1; i > t; i--) {
			if (arrX[t] == arrX[i]) {
				length = i - t + 1;
				k = t;

				merge_sort_single(&arrY, &rY, k, k + length - 1);
				l = 1;
				break;
			}

		}
		if (l == 1)
			t += length;
		else
			t++;
		l = 0;
	}


	for (int i = 0; i < n; i++)
		printf("%d %d\n", rX[i], rY[i]);

	return 0;
}