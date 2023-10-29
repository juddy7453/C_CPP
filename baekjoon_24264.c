# include <stdio.h>
long long count = 0;

long long MenOfPassion(int k, int n) {
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sum += k * k;
			count++;
		}
	}
	return sum;
}

int main(void) {
	int n;

	scanf("%d", &n);

	long long sum = MenOfPassion(1, n);

	printf("%lld\n", count);
	printf("2\n");

	return 0;
}