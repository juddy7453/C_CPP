# include <stdio.h>
# include <stdlib.h>

int* merge(int** arr, int size, int i, int j) {
	if (size >= j)
		return *arr;

	if (j % 2 == 1) {
		int x = (*arr)[0];
		int* tmp_arr = (int*)malloc(sizeof(int) * (j - 1));

		for (int k = 0; k < j - 1; k++)
			tmp_arr[k] = (*arr)[k + 1];

		int* tmp_result = (int*)malloc(sizeof(int) * j - 1);

		tmp_result = merge(&tmp_arr, size, 0, j - 1);

		int* result = (int*)malloc(sizeof(int) * j);
		for (int k = 0; k < j - 1; k++) {
			if (tmp_result[k] > x) {
				result[k] = x;
				for (int t = k + 1; t < j; t++) {
					result[t] = tmp_result[t - 1];
				}
				break;
			}
			else {
				result[k] = tmp_result[k];
				if (k + 1 >= j - 1)
					result[k + 1] = x;
			}
		}
	}
	else if (j % 2 == 0)
	{
		int* result_array = (int*)malloc(sizeof(int) * j);
		int** result = &result_array;

		int* l;
		int* r;
		int l_count, r_count;

		for (int k = i; k < j - 1; k += 2 * size) {
			l_count = 0; r_count = 0;
			printf("#######################\n");
			for (int t = k; t < k + (2 * size) - 1; t++) {
				if (k + 2 * size - 1 > j) {
					for (int g = t; g < j; g++)
						(*result)[g] = (*arr)[g];
					break;
				}

				if (t == k) {
					l = &((*arr)[t]);
					r = &((*arr)[t + size]);
				}

				//			printf("t=%d\n", t);
				if ((*l) > (*r)) {
					(*result)[t] = *r;
					r_count++;
					//				printf("caseA : ");
					printf("t=%d, %d\n", t, (*result)[t]);

					if (r_count < size) {
						r = r + 1;

						if (r == l) {
							(*result)[t + 1] = *l;
							printf("t+1=%d, %d\n", t + 1, (*result)[t + 1]);
							break;
						}
						//					printf("r=%d\n", *r);
					}
					else {
						r = &((*arr)[k + size - 1]);
						r_count = 0;

						if (r == l) {
							(*result)[t + 1] = *l;
							printf("t+1=%d, %d\n", t + 1, (*result)[t + 1]);
							break;
						}
						//					if (l == &((*arr)[k + size - 2]))
						//						(*result)[t + 2] = *r;
					}
				}
				else if ((*l) < (*r)) {
					(*result)[t] = *l;
					l_count++;
					//				printf("caseB : ");
					printf("t=%d, %d\n", t, (*result)[t]);

					if (l_count < size) {
						l = l + 1;
						if (l == r) {
							(*result)[t + 1] = *r;
							printf("t+1=%d, %d\n", t + 1, (*result)[t + 1]);
							break;
						}
						//					printf("l=%d\n", *l);
					}
					else {
						l = &((*arr)[k + 2 * size - 1]);
						l_count = 0;

						if (l == r) {
							(*result)[t + 1] = *r;
							printf("t+1=%d, %d\n", t + 1, (*result)[t + 1]);
							break;
						}
						//					if (r == &((*arr)[size - 2]))
						//						(*result)[t + 2] = *l;
					}
				}

			}
		}

		printf("size=%d\n", size);
		for (int k = 0; k < j; k++)
			printf("%d\n", (*result)[k]);

		return merge(result, size * 2, i, j);
	}

}

int main(void) {
	int n;

	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int size = 1;


	int* result = (int*)malloc(sizeof(int) * n);
	result = merge(&arr, size, 0, n);

	for (int k = 0; k < n; k++)
		printf("%d\n", result[k]);




	return 0;
}