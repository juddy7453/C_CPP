# include <stdio.h>
# include <stdlib.h>

void selection(int** arr, int n) {
	int min = (*arr)[0];
	int min_index = 0;
	int i = 0;
	int tmp;
	while (i < n-1) {
		for (int j = i + 1; j < n; j++) {
			if (min > (*arr)[j]) {
				min = (*arr)[j];
				min_index = j;
			}
		}
		tmp = (*arr)[min_index];
		(*arr)[min_index] = (*arr)[i];
		(*arr)[i] = tmp;
		i++;
		min = (*arr)[i];
		min_index = i;
	}
}

void merge(int** arr, int** result, int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left; // resultÀÇ ÀÎµ¦½º

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
	int n, m;
	scanf("%d", &n);
	int* have = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &have[i]);
	scanf("%d", &m);
	int* newset = (int*)malloc(sizeof(int) * m);
	for (int i = 0; i < m; i++)
		scanf("%d", &newset[i]);
	
	int* result = (int*)malloc(sizeof(int) * n);
//	selection(&have, n);
//	selection(&newset, m);
	merge_sort(&have, &result, 0, n - 1);


	int t = 0;

	for (int i = 0; i < m; i++) {
		while (t < n) {
			if (t < n - 1) {
				if (have[t] < newset[i] && have[t + 1] > newset[i]) {
					printf("0 ");
					break;
				}
				else if (have[t] == newset[i]) {
					printf("1 ");
					break;
				}
				else if (have[t] < newset[i]) {
					t++;
				}
				else {
					printf("0 ");
					break;
				}
			}
			else {
				if (have[t] == newset[i]) {
					printf("1 ");
					break;
				}
				else {
					printf("0 ");
					break;
				}
			}

		}
		t = 0;
	}


	return 0;

}