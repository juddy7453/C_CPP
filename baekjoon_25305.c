# include <stdio.h>
# include <stdlib.h>

int main(void) {
	int n, k;

	scanf("%d %d", &n, &k);
	int* arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int i = 0;
	int ii = 1;
	int count = -1;
	int tmp;
	int axis;

	while (i < n - 1) {
		axis = arr[i];
		for (int j = i + 1; j < n; j++) {
			if (axis < arr[j]) {
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;

				i = j;
				count++;
			}
		}
		if (count != -1) {
			i = ii - 1;
			count = -1;
		}
		else {
			i = ii;
			ii++;
		}
	}

	printf("%d\n", arr[k - 1]);
	
	return 0;
}