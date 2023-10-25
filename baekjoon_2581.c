# include <stdio.h>

int main(void) {
	int m = 1;
	int n = 1;
	int sum = 0;
	int min = 0;
	int count;
	
	scanf("%d", &m); // m <= n
	scanf("%d", &n);

	for (int i = m; i <= n; i++) {
		count = 0;

		for (int j = 1; j <= i; j++) {
			if (i % j == 0) 
				count += 1;

			if (j == i) {
				if (count == 2) { // i가 소수인 경우
					sum += i;
					if (sum == i) 
						min = i;
					
				}
			}
		}
	}

	if (sum == 0) {
		printf("%d\n", -1);
		return 0;
	}

	else {
		printf("%d\n", sum);
		printf("%d\n", min);
	}

	return 0;
}