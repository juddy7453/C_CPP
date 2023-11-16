# include <stdio.h>

int main(void) {
	long n, m;
	scanf("%ld %ld", &n, &m);

	long r;
	r = (n >= m) ? n - m : m - n;

	if (r >= 0)
		printf("%ld\n", r);
	else
		printf("%ld\n", r * (-1));

	return 0;
}