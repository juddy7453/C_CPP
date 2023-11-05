# include <stdio.h>
# include <stdlib.h>

int main(void) {
	int n;

	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int* result = (int*)malloc(sizeof(int) * n);

	int min;
	int k = 0;
	int min_index;
	while (k < n - 1) {
		min = arr[k];
		min_index = k;
		for (int i = k + 1; i < n; i++) {
			if (min > arr[i]) {
				min = arr[i];
				min_index = i;
			}
		}
		for (int i = min_index; i >= k + 1; i--) {
			arr[i] = arr[i - 1];
		}
		arr[k] = min;
		k++;

	}
	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);

	return 0;
}