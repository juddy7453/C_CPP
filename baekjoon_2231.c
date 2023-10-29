# include <stdio.h>
# include <string.h>
# include <math.h>

int f(int m, int l) {
	int k = 0;
	int result = m;

	while (l >= 1) {
		l--;
		k = m % ((int)pow(10, l));
		m /= pow(10, l);
		result += m;

		m = k;
	}

	return result;
}

int main(void) {
	int n;

	scanf("%d", &n);

	int half = n / 2;
	int m = half;
	int mm = m;

	char str[8];

	sprintf(str, "%d", half);
	// itoa(half, str, 10);

	int l = strlen(str);
	int result = f(m, l);

	while (m < n) {
		if (result == n) {
			printf("%d\n", mm);
			return 0;
		}

		else {
			mm++;
			m = mm;
			result = f(m, l);
		}
	}

	if (m == n)
		printf("0\n");
	return 0;
}