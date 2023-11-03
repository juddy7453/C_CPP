# include <stdio.h>
# include <stdlib.h>

int main(void) {
	int n;

	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int axis;
	int tmp;

	int i = 0;
	int count = -1;
	int ii = 1;

	while(i < n){
		axis = arr[i];
		for (int j = i + 1; j < n; j++) {
			if (axis > arr[j]) {
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

	for (int k = 0; k < n; k++)
		printf("%d\n", arr[k]);

	return 0;
}
