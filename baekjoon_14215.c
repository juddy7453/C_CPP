# include <stdio.h>

int main(void) {
	int arr[3] = { 0, };
	int result = 0;

	scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);

	int i, j;
	int temp;

	// 오름차순 정렬
	for (i = 0; i < 3; i++) {
		for (j = 0; j < (3 - 1) - i; j++) {
			if (arr[j] > arr[j + 1]) {	// 버블 정렬 사용
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	int k = arr[0] + arr[1] - 1;
	if (k >= arr[2]) {
		result = arr[0] + arr[1] + arr[2];
	}
	else {
		arr[2] = k;
		result = arr[0] + arr[1] + arr[2];
	}

	printf("%d\n", result);

	return 0;
}