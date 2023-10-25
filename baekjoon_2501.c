# include <stdio.h>

int main(void) {
	int n = 1;
	int k = 1;

	scanf("%d %d", &n, &k);

	int i = 0;	// n의 약수

	while (k > 0) {
		if (i == n) {
			printf("%d\n", 0);
			return 0;
		}

		if (n % (i + 1) == 0) {
			k--;	// i+1은 n의 n-k 번째로 작은 약수
		}
		i++;

	}

	
	printf("%d\n", i);

	return 0;
	
}