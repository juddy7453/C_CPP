# include <stdio.h>
# include <stdlib.h>

int main(void) {
	long long amount;
	scanf("%lld", &amount);

	int n;
	scanf("%d", &n);

	int* a = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	// selection sort (내림차순)
	int max;
	int max_index;
	int k = 0;
	while (k < n - 1) {
		max = a[k];
		max_index = k;
		for (int i = k + 1; i < n; i++) {
			if (max < a[i]) {
				max = a[i];
				max_index = i;
			}
		}
		for (int j = max_index; j >= k + 1; j--) {
			a[j] = a[j - 1];
		}
		a[k++] = max;
	}

	long long min_count = amount;	// 가능한 개수의 최대 => 입력의 최대 (1원짜리로만)
	long long small_count;
	long long count;
	long long rest_amount;

	long long q;
	long long r;
	for (int t = 0; t < n; t++) {
		small_count = amount;
		count = 0;
		rest_amount = amount;
		for (int i = t; i < n; i++) {
			q = rest_amount / a[i];
			r = rest_amount % a[i];
			
			count += q;
			rest_amount = r;
			
			if (rest_amount == 0) {
				small_count = count;
				break;
			}
		}
		if (min_count > small_count)
			min_count = small_count;
	}
	printf("%lld\n", min_count);

	return 0;
}