# include <stdio.h>
# include <stdlib.h>

int main(void) {
	int n;

	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	if (n == 1) {
		printf("%d\n", arr[0]);
		return 0;
	}

	int k = 0;
	int i = 1;
	int tmp;
	int count = 0;
	while (count < n) {
		int axis = arr[k];
		int value = arr[i];

		while (value < axis) {
			tmp = arr[k];
			arr[k] = arr[i];
			arr[i] = tmp;

			if (k == 0 || i == 0)
				break;
			else {
				axis = arr[--k];
				value = arr[--i];
			}
		}

		count++;
		k = count - 1;
		i = count;
	}
	for (int j = 0; j < n; j++)
		printf("%d\n", arr[j]);

	return 0;
}