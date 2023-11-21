# include <stdio.h>
# include <stdlib.h>

int compare(const void* a, const void* b) {
	if (*(int*)a >= *(int*)b)
		return 1;
	else
		return -1;
}

int bs(int* arr, int n, int value, int startindex, int endindex) {
	if (startindex >= endindex)
		return 0;

	int mid = (endindex - startindex) / 2;
	value = startindex + mid;
	int r = arr[value] - n;

	int check = 1;

	while (startindex < endindex) {

		if (r < 0) { // element가 value보다 크다면
			return bs(arr, n, value, value + 1, endindex);
		}
		else if (r > 0) { // element가 value보다 작다면
			return bs(arr, n, value, startindex, value - 1);
		}
		else {
			int pivot_l = value - 1;
			int pivot_r = value + 1;

			// 오른쪽 왼쪽 중 하나라도 또 element가 있을 경우
			if (arr[pivot_l] == n || arr[pivot_r] == n) {
				while (arr[pivot_l] == n) {
					pivot_l--;
					if (pivot_l < 0) {
						pivot_l++;
						check = 0;
						break;
					}
				}
				while (arr[pivot_r] == n) {
					pivot_r++;
					if (pivot_r > endindex) {
						pivot_r--;
						check = 0;
						break;
					}
				}

			}
			return pivot_r - pivot_l - check;


		}

	}

}



int main(void) {
	int m;
	scanf("%d", &m);
	int* given = (int*)malloc(sizeof(int) * m);
	for (int i = 0; i < m; i++)
		scanf("%d", &given[i]);

	int n;
	scanf("%d", &n);
	int* have = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &have[i]);

	if (n == 1) {
		int c = 0;
		for (int u = 0; u < m; u++) {
			if (have[0] == given[u]) {
				c++;
			}
		}
		printf("%d ", c);
		return 0;
	}

	if (m > 1) {

		qsort(given, m, sizeof(int), compare);


		int* arr = (int*)malloc(sizeof(int) * n);
		for (int i = 0; i < n; i++) {
			arr[i] = bs(given, have[i], 0, 0, m - 1);
			printf("%d ", arr[i]);
		}
		return 0;
	}

	else if (m == 1) {
		for (int t = 0; t < n; t++) {
			if (given[0] == have[t])
				printf("1 ");
			else
				printf("0 ");
		}
		return 0;
	}

	return 0;
}