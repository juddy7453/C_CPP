# include <stdio.h>

int main(void) {
	int arr[5];
	int sum = 0;
	int avg = 0;
	int median = 0;

	for (int i = 0; i < 5; i++) 
		scanf("%d", &arr[i]);
	
	int axis;
	int tmp;
	int count = -1;
	int i = 0;
	int ii = 1;

	while (i < 4) {
		axis = arr[i];
		for (int j = i + 1; j < 5; j++) {
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

	for (int j = 0; j < 5; j++)
		sum += arr[j];

	avg = sum / 5;
	median = arr[2];

	printf("%d\n", avg);
	printf("%d\n", median);

	return 0;
}