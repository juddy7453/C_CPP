# include <stdio.h>

int main(void) {
	int indexarr[10000] = { 0, };

	int n;
	scanf("%d", &n);

	int tmp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		indexarr[tmp - 1]++;
	}
	int count = 0;

	for (int i = 0; i < 10000; i++) {
		if (count >= n)
			break;
		if (indexarr[i] > 0) {
			for (int j = 0; j < indexarr[i]; j++) {
				printf("%d\n", i+1);
				count++;
			}
		}

	}

	return 0;
}