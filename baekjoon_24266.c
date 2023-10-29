# include <stdio.h>

long long count = 0;

long long MenOfPassion(int z, int n) {
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				sum += z * z * z;
				count++;
			}
		}
	}
	return sum;
}

int main(void) {
	int n;

	scanf("%d", &n);

	long long sum = MenOfPassion(1, n);

	printf("%lld\n", count);
	printf("3\n");

	return 0;
}