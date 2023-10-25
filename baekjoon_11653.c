# include <stdio.h>

int main(void) {
	int n = 1;

	scanf("%d", &n);
	int m = n;

	if (n == 1)
		return 0;

	else {
		int i = 2;

		while (i <= n) {
			if (m % i == 0) {
				printf("%d\n", i);
				m /= i;
			}

			else {
				i++;
			}

			if (m == 1)
				break;
		}

	}

	return 0;
}