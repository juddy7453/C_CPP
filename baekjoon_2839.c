# include <stdio.h>

int main(void) {
	int n;
	int c3, c5;
	int min_count = 5000;
	int have_minus = 0;

	scanf("%d", &n);

	int m = n;

	int q5 = m / 5;

	for (int i = 0; i < q5 + 1; i++) {
		c5 = i;
		c3 = (m - (i * 5)) / 3;
		if ((m - (i * 5)) % 3 != 0) {
			have_minus = 1;
		}
		else {
			if (c5 + c3 < min_count)
				min_count = c5 + c3;
		}
	}

	if (min_count < 5000) 
		printf("%d\n", min_count);
	
	else {
		if (have_minus == 1)
			printf("-1\n");
	}


	return 0;
}