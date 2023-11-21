# include <stdio.h>
# include <stdlib.h>

int compare(const void* a, const void* b) {
	if (*(int*)a >= *(int*)b)
		return 1;
	else
		return -1;
}

int bs(int* arr, int element, int value, int firstindex, int lastindex) {
	value = firstindex + (lastindex - firstindex) / 2;
	printf("value=%d\n", value);
	int r = arr[value] - element;
	if (firstindex > lastindex)
		return 0;

	int check = 1;

	while (firstindex < lastindex) {

		if (r < 0) { // element가 value보다 크다면
			return bs(arr, element, value, value + 1, lastindex);
		}
		else if (r > 0) { // element가 value보다 작다면
			return bs(arr, element, value, firstindex, value - 1);
		}
		else {
			int pivot_l = value-1;
			int pivot_r = value+1;

			// 오른쪽 왼쪽 중 하나라도 또 element가 있을 경우
			if (arr[pivot_l] == element || arr[pivot_r] == element) {
				while (arr[pivot_l] == element) {
					pivot_l--;
					if (pivot_l < 0) {
						pivot_l++;
						const pivot_l;
						check = 0;
						break;
					}
				}
				while (arr[pivot_r] == element) {
					pivot_r++;
					if (pivot_r > lastindex) {
						pivot_r--;
						const pivot_r;
						check = 0;
						break;
					}
				}
			//	printf("pivot_r = %d\n", pivot_r);
			//	printf("pivot_l = %d\n", pivot_l);


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


	qsort(given, m, sizeof(int), compare);


	int* arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		arr[i] = bs(given, have[i], 0, 0, n - 1);
	//	printf("%d ", arr[i]);
	}
	return 0;
}