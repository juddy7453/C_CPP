# include <stdio.h>

int main(void) {
	int n;
	long long count = 0;

	scanf("%d", &n);

	if (n <= 2) {
		printf("0\n");
		printf("3\n");
		return 0;
	}

	for (int i = 2; i < n; i++) 
		count += (i - 1) * (n - i);
	

	printf("%lld\n", count);
	printf("3\n");

	return 0;
}