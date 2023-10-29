# include <stdio.h>

int main(void) {
	int n, m;
	int arr[100] = { 0, };

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int sum = 0;
	int tmp_sum = 0;

	for (int i = 0; i < n-2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			tmp_sum = arr[i] + arr[j];
			if (tmp_sum > m)
				continue;
			else{
				for (int k = j + 1; k < n; k++) {
					if (tmp_sum + arr[k] > m)
						continue;
					else {
						if (tmp_sum + arr[k] > sum) {
							sum = tmp_sum + arr[k];
						}
					}
				}
			}
		}
	}

	printf("%d\n", sum);
	return 0;
}