# include <stdio.h>
# include <stdlib.h>
# include <math.h>

void merge(int** arr, int** result, int left, int mid, int right) {
	int k = left;
	int i = left;
	int j = mid+1;

	while (i <= mid && j <= right) {
		if ((*arr)[i] < (*arr)[j])
			(*result)[k++] = (*arr)[j++];
		else
			(*result)[k++] = (*arr)[i++];
	}

	if (i > mid) {
		for (int t = j; t <= right; t++)
			(*result)[k++] = (*arr)[t];
	}
	else {
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
	long long n;

	scanf("%lld", &n);

	int input_arr[10] = { 0, };

	int m = n;
	long long i = 10;
	int count = 0;
	long long q, r;
	q = n / i;
	while (q > 0) {
		q /= i;
		count += 1; // ÃÖ´ë ÀÚ¸´¼ö = 10^count
	}
	for (int k = count; k >= 0; k--) {
		q = m / pow(10, k);
		r = m % (int)pow(10, k);
		input_arr[k] = q;
		m = r;
	}

	int* arr = (int*)malloc(sizeof(int) * (count + 1));
	for (int k = 0; k < count + 1; k++)
		arr[k] = input_arr[k];

	int* result = (int*)malloc(sizeof(int) * (count + 1));

	merge_sort(&arr, &result, 0, count);

	for (int k = 0; k < count+1; k++)
		printf("%d", arr[k]);

	return 0;
}