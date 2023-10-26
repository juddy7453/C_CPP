# include <stdio.h>
# include <stdlib.h>

int main(void) {
	int t;
	int c;
	int m;
	int q, d, n, p;

	scanf("%d", &t);
	int* arr = (int*)malloc(sizeof(int) * t);

	for (int i = 0; i < t; i++) {
		scanf("%d", &c);

		arr[i] = c;	
	}

	for (int i = 0; i < t; i++) {
		q = arr[i] / 25;
		m = arr[i] % 25;

		d = m / 10;
		m %= 10;

		n = m / 5;
		m %= 5;

		p = m;

		printf("%d %d %d %d\n", q, d, n, p);
	}

	return 0;
}