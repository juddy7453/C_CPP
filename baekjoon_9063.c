# include <stdio.h>

int main(void) {
	int n;
	int x[100000] = { 0, };
	int y[100000] = { 0, };

	scanf("%d", &n);

	for (int i = 0; i < n; i++) 
		scanf("%d %d", &x[i], &y[i]);

	int x_min = x[0];
	int x_max = x[0];
	int y_min = y[0];
	int y_max = y[0];

	for (int i = 1; i < n; i++) {
		if (x_min > x[i]) {
			x_min = x[i];
		}
		if (x_max < x[i]) {
			x_max = x[i];
		}

		if (y_min > y[i]) {
			y_min = y[i];
		}
		if (y_max < y[i]) {
			y_max = y[i];
		}
	
	}

	int a = x_max - x_min;
	int b = y_max - y_min;

	printf("%d\n", a * b);

	return 0;
}