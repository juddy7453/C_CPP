# include <stdio.h>
# include <string.h>
# include <math.h>

int f(int m, int l) {
	int q = m / (int)pow(10, l - 1);

	return q;
}

int main(void) {
	int n;

	scanf("%d", &n);

	int m = 1;
	int mm = m;

	char str[8];

	while (m < n) {
		sprintf(str, "%d", m);
		// itoa(half, str, 10);

		int l = strlen(str);
		int result = m;

		while (l > 0) {
			result += f(m, l);
			m %= (int)pow(10, l - 1);
			l--;
		}

		if (result == n) {
			printf("%d\n", mm);
			return 0;
		}

		else {
			mm++;
			m = mm;
		}
		
	}

	if (m == n)
		printf("0\n");

	return 0;
}