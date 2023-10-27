# include <stdio.h>
int count = 0;

int MenOfPassion(int k, int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += k;
		count++;
	}
	return sum;
}

int main(void) {
	int n;

	scanf("%d", &n);

	int sum = MenOfPassion(1, n);

	printf("%d\n", count);
	printf("1\n");

	return 0;
}