# include <stdio.h>

int main(void) {
	int a, b, c, d, e, f;

	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

	// ax + by = c
	// dx + ey = f

	int x, y;
	y = (c * d - a * f) / (b * d - a * e);
	x = (c * e - b * f) / (a * e - b * d);

	printf("%d %d\n", x, y);
	return 0;
}