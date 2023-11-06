# include <stdio.h>
# include <stdlib.h>

void f(int** arr, int** heap, int start, int end) {
	int i = start;
	int j = 2;
	int t;
	int tmp;
	while (i < end) {
		t = j;
		(*heap)[j] = (*arr)[i];
		while ((*heap)[t] < (*heap)[t / 2]) {
			tmp = (*heap)[t / 2];
			(*heap)[t / 2] = (*heap)[t];
			(*heap)[t] = tmp;
			t /= 2;
		}
		j++; i++;
		
	}
}

void g(int**arr, int** heap, int k) {
	int i = 1;
	int j = k;
	int tmp;
	while (i <= j) {
		printf("%d\n", (*heap)[i]);
		(*heap)[i] = (*heap)[j];
		for (int t = i; t < k; t++)
			(*arr)[t] = (*heap)[t + 1];
		f(arr, heap, 1, j);
		j--;
	}
}


int main(void) {
	int n;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int* heap = (int*)malloc(sizeof(int) * (n + 1));
	heap[1] = arr[0];

	f(&arr, &heap, 1, n);
	g(&arr, &heap, n);

	return 0;
}